#ifndef VERILOG_TEMP_VARIABLE_H_GUARD
#define VERILOG_TEMP_VARIABLE_H_GUARD

#include "global.h"
#include "verilog/variable/variable.h"

struct VTempVariable : VVariable {
    VTempVariable(int length_);
};

#endif

