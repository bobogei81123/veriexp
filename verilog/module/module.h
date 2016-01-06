#ifndef VERILOG_MODULE_H_GUARD
#define VERILOG_MODULE_H_GUARD

#include "global.h"
#include "verilog/node.h"
#include "verilog/variable/named_variable.h"

struct VModule;

#include "context/context.h"

typedef vector<VNamedVariable*> VNamedVarList;

struct VModule : VNode {
    string name;
    VNamedVarList vars;

    StateManager *state_manager;

    virtual void generate();
};

#endif
