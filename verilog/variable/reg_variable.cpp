#include "verilog/variable/reg_variable.h"
#include "verilog/variable/typedef.h"

VRegVariable::VRegVariable(
        string name_, 
        int length_,
        VIO iotype_
) : VNamedVariable(name_, length_, VWR::Reg, iotype_) {} 
