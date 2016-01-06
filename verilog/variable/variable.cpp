#include "verilog/variable/variable.h"
#include "verilog/variable/typedef.h"

VVariable::VVariable(string name_, int length_,
    VWR wrtype_, VIO iotype_)
: name(name_), wrtype(wrtype_), iotype(iotype_), length(length_) {}

