#include "ast/statement/function_declaration.h"

NFunctionDeclaration::NFunctionDeclaration(
    NType *type_,
    NIdentifier *id_,
    ArgList args_,
    NBlock *block_
) : type(type_), id(id_), args(args_), block(block_) { }

void NFunctionDeclaration::generate(Context *context) {
  context->module->name = id->name;
  context->add_input("clk", 1);
  context->add_input("reset", 1);
  context->add_input("start", 1);
  context->add_output("result", type->length);
  context->add_output("done", 1);
  int idle_state = context->new_state();
  int start_state = context->new_state();
  for (auto x: args) {
    x->generate(context);
  }
}
