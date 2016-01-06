#pragma once

#include "global.h"
#include "verilog/node.h"

enum class VVarWRType {
    Wire,
    Reg
};

enum class VVarIOType {
    Input,
    Output,
    Normal
};

struct VVariable : VNode {
    string name;
    VVarWRType wrtype;
    VVarIOType iotype;
    int length;

    VVariable(string name_, 
              int length_,
              VVarWRType wrtype_,
              VVarIOType iotype_ = VVarIOType::Normal
              );
};
