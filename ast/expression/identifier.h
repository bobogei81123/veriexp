#pragma once

#include "global.h"
#include "ast/expression/expression.h"

struct NIdentifier : NExpression {
    string name;
    NIdentifier(string name_);

    //virtual void generate(Context *context) { }
};
