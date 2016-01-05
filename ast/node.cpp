#include "ast/node.h"

NType::NType(string name_) : name(name_) {
    if (name == "int") {
        length = 32;
        return;
    }
    assert(false);
}

NVariableDeclaration::NVariableDeclaration(NIdentifier *name_, NType *type_) 
    : name(name_), type(type_)
{
}

NFuncArgDeclaration::
NFuncArgDeclaration(NIdentifier *name_, NType *type_) 
    : NVariableDeclaration(name_, type_)
{
}

void NFuncArgDeclaration::generate(Context *context) {
    context->add_input(name->name, type->length);
    //context.add_input(name->name, VVarWRType::Wire,
            //VVarIOType::Input, type->length);
}

