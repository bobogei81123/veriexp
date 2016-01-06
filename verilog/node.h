#ifndef VERILOG_NODE_H_GUARD
#define VERILOG_NODE_H_GUARD

#include "global.h"

struct Context;

struct VNode {
    virtual void generate(Context*) {}
};

#endif
