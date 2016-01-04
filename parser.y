%{
#include <bits/stdc++.h>
#include "node/node.h"
using namespace std;
extern int yylex();
void yyerror(const char *s) { cout << "ERROR = " << s << endl; }
NFunctionDeclaration *main_func;
%}

%error-verbose
%token <str> IDENT DIGITS

%type <func_decl> func_decl
%type <type> type
%type <ident> ident

%start program

%union {
    string *str;
    Node *node;
    NBlock *block;
    NExpression *expr;
    NStatement *stmt;
    NType *type;
    NIdentifier *ident;
    NVariableDeclaration *var_decl;
    NFunctionDeclaration *func_decl;
}
%%
program : func_decl { main_func = $1; }
        ;
func_decl : type ident '(' func_args ')' block {
            $$ = new NFunctionDeclaration($1, $2, VariableList(), new NBlock());
          }
          ;

func_args : 
          | var_decl
          | func_args ',' var_decl

var_decl : type ident
         | type ident '=' expr
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

expr : ident '=' expr
     | ident '+' expr
     | ident
%%
