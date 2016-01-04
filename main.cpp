#include<bits/stdc++.h>
#include "node/node.h"

using namespace std;

extern int yyparse();
extern NFunctionDeclaration *main_func;

int main(){
    yyparse();
    main_func->generate();
}

