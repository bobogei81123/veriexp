#include "verilog/node.h"

typedef VVarIOType VIO;
typedef VVarWRType VWR;

void VModule::generate() {
    cout << "module " << name << "(";
    bool isf = true;
    for (auto x: vars) {
        if (x->iotype == VIO::Normal) continue;
        if (isf) isf = false, cout << x->name;
        else cout << ", " << x->name;
    }
    cout << ")" << endl;

    for (auto x: vars) {
        x->generate_declaration();
    }
    cout << "endmodule" << endl;
}

VVariable::VVariable(string name_, 
    VWR wrtype_, VIO iotype_,
    int length_) 
: name(name_), wrtype(wrtype_), iotype(iotype_), length(length_) {}

void VVariable::generate_declaration() {
    string io = (iotype == VIO::Input  ? "input "
            :    iotype == VIO::Output ? "output "
            : "");

    string wr = (wrtype == VWR::Wire ? "wire "
            :    wrtype == VWR::Reg  ? "reg "
            : "");

    string len = (length > 1 ? "[" + to_string(length-1) + ":0] " : "");
    cout << io << wr << len << name << ";" << endl;
}
