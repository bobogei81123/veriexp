#include "verilog/module/module.h"
#include "verilog/variable/typedef.h"

void VModule::generate() {
    cout << "module " << name << "(";
    bool isf = true;
    sort(vars.begin(), vars.end(), [](const VVariable *v1, const VVariable *v2) {
          return v1->iotype < v2->iotype;
         });
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
