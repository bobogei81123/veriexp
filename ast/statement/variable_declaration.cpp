#include "ast/statement/variable_declaration.h"

NVariableDeclaration::NVariableDeclaration(NIdentifier *name_, NType *type_) 
    : name(name_), type(type_)
{
}
