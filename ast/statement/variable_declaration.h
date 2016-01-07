#pragma once
#include "global.h"
#include "ast/statement/statement.h"
#include "ast/expression/identifier.h"
#include "ast/expression/type.h"

struct NVariableDeclaration : NStatement {
    NIdentifier *name;
    NType *type;

    NVariableDeclaration(NIdentifier*, NType*);

    virtual void generate(Context *context) {}
};


