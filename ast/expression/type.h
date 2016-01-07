#pragma once

#include "global.h"
#include "ast/expression/expression.h"

struct NType : NExpression {
    string name;
    int length;
    NType(string name_);
};
