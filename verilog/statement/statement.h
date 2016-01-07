#pragma once

#include "global.h"
#include "verilog/node.h"

struct VStatement : VNode {
    virtual void generate(Context *context) {}
};
