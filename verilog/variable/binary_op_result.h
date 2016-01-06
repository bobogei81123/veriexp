#pragma once

#include "global.h"
#include "verilog/variable/variable.h"
#include "verilog/variable/temp_variable.h"
#include "verilog/variable/wire_variable.h"

struct VBinaryOPResult : VTempVariable {
    VVariable *lhs, *rhs;
    string op;

    VBinaryOPResult(
        VVariable *lhs_, VVariable *rhs_, string op_
    );

    VWireVariable* regist(Context *context);
};
