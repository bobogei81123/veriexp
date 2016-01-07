%{
#include <bits/stdc++.h>
#include "ast/all_node.h"
using namespace std;
extern int yylex();

void yyerror(const char *s) { cout << "ERROR = " << s << endl; }
NFunctionDeclaration *main_func;
%}

%error-verbose
%token <str> IDENT DIGITS RETURN

%type <func_decl> func_decl
%type <arg_list> func_args
%type <func_arg_decl> func_arg_decl
%type <var_decl> var_decl
%type <type> type
%type <ident> ident

%start program

%union {
    string *str;
    Node *node;
    NType *type;
    NIdentifier *ident;
    NVariableDeclaration *var_decl;
    NFunctionDeclaration *func_decl;
    NFuncArgDeclaration *func_arg_decl;
    ArgList *arg_list;
}
%%
program : func_decl { main_func = $1; }
        ;
func_decl : type ident '(' func_args ')' block {
            $$ = new NFunctionDeclaration($1, $2, (*$4), new NBlock());
            delete $4;
          }
          ;

func_args : 
          {
              $$ = new ArgList();
          }
          | func_arg_decl { 
              $$ = new ArgList(); 
              $$->push_back($1);
          }
          | func_args ',' func_arg_decl {
              $$->push_back($3);
          }

func_arg_decl : type ident { $$ = new NFuncArgDeclaration($2, $1); }
         ;

var_decl : type ident { $$ = new NVariableDeclaration($2, $1); }
         /*| type ident '=' expr*/
         ;

ident : IDENT { $$ = new NIdentifier(*$1); }
      ;

type : IDENT { $$ = new NType(*$1); }
     ;

block : '{' stmts '}'
      ;

stmts : 
      | stmt
      | stmts stmt
      ;

stmt : expr ';'
     | var_decl ';'
     | return_stm ';'

return_stm : RETURN ident

expr : ident '=' expr
     | ident '+' expr
     | ident
%%
