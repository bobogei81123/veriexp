#include "ast/statement/funcarg_declaration.h"

NFuncArgDeclaration::
NFuncArgDeclaration(NIdentifier *name_, NType *type_) 
    : NVariableDeclaration(name_, type_)
{
}

void NFuncArgDeclaration::generate(Context *context) {
    context->add_input(name->name, type->length);
    auto ret = context->add_reg(name->name + "_", type->length);
    context->ident_map[name->name] = ret;
    //context.add_input(name->name, VVarWRType::Wire,
            //VVarIOType::Input, type->length);
}
