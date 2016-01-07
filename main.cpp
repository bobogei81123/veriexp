#include<bits/stdc++.h>
#include "ast/statement/function_declaration.h"
#include "context/context.h"

using namespace std;

extern int yyparse();
extern NFunctionDeclaration *main_func;

int main(){
    yyparse();
    Context *context = new Context();
    main_func->generate(context);
    context->module->generate();
}

