#ifndef VERILOG_NAMED_VARIABLE_H_GUARD
#define VERILOG_NAMED_VARIABLE_H_GUARD

#include "global.h"
#include "verilog/variable/variable.h"

struct VNamedVariable : VVariable {
    VNamedVariable(
        string name_, 
        int length_,
        VVarWRType wrtype_,
        VVarIOType iotype_ = VVarIOType::Normal
    );
    void generate_declaration();
};

#endif

