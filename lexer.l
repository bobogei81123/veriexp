%{
#include <bits/stdc++.h>
#include "ast/node.h"
using namespace std;
#include "parser.hpp"

#define STORE_STR yylval.str = new string(yytext)
%}

%option noyywrap
digit [0-9]
alpha [a-zA-Z]
ws [ \t]

%%
{ws}+
\n      cout << endl;
"//"[^\n]*      cout << "Comment = " << yytext << endl;

return { cout << "[RETURN]" << ' '; return RETURN;}

[a-zA-Z_][a-zA-Z_0-9]* {
    cout << "ID(" << yytext << ")" << endl;
    STORE_STR;
    return IDENT;
}

[0-9]+          {
    cout << "DIGITS(" << yytext << ")" << endl;
    STORE_STR;
    return DIGITS;
}

.               {
    cout << "OP(" << yytext << ")" << endl;
    return yytext[0];
}

%%
