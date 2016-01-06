#pragma once

#include "global.h"
#include "verilog/variable/named_variable.h"

struct VRegVariable : VNamedVariable {
    VRegVariable(
        string name_, 
        int length_,
        VVarIOType iotype_ = VVarIOType::Normal
    );
};
