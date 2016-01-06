#pragma once

#include "global.h"
#include "verilog/variable/named_variable.h"

struct VWireVariable : VNamedVariable {
    VWireVariable(
        string name_, 
        int length_,
        VVarIOType iotype_ = VVarIOType::Normal
    );
};
