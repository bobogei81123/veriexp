#pragma once

#include "global.h"
#include "ast/statement/variable_declaration.h"

struct NFuncArgDeclaration : NVariableDeclaration {
    NFuncArgDeclaration(NIdentifier *name_, NType *type_);
    virtual void generate(Context *context);
};

