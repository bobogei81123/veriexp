#include "verilog/variable/temp_variable.h"
#include "verilog/variable/typedef.h"

VTempVariable::VTempVariable(int length_)
    : VVariable("", length_, VWR::Wire, VIO::Normal) {
}
