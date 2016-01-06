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

void NFunctionDeclaration::generate(Context *context) {
  context->module->name = id->name;
  context->add_input("clk", 1);
  context->add_input("reset", type->length);
  context->add_input("start", 1);
  context->add_output("result", type->length);
  context->add_output("done", 1);
  for (auto x: args) {
    x->generate(context);
  }
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

