#include "verilog/variable/named_variable.h"
#include "verilog/variable/typedef.h"

VNamedVariable::VNamedVariable(
    string name_, 
    int length_,
    VWR wrtype_,
    VIO iotype_
) : VVariable(name_, length_, wrtype_, iotype_) { }

void VNamedVariable::generate_declaration() {
    string io = (iotype == VIO::Input  ? "input "
            :    iotype == VIO::Output ? "output "
            : "");

    string wr = (wrtype == VWR::Wire ? "wire "
            :    wrtype == VWR::Reg  ? "reg "
            : "");

    string len = (length > 1 ? "[" + to_string(length-1) + ":0] " : "");
    cout << io << wr << len << name << ";" << endl;
}
