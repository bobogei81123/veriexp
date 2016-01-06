#include "verilog/variable/wire_variable.h"
#include "verilog/variable/typedef.h"

VWireVariable::VWireVariable(
        string name_, 
        int length_,
        VVarIOType iotype_
) : VNamedVariable(name_, length_, VWR::Wire, iotype_) {} 
