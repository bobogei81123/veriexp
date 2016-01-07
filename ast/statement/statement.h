#pragma once
#include "global.h"
#include "ast/node.h"

struct NStatement : Node {
    virtual void generate(Context *context) {}
};

