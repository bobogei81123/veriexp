#include "verilog/statement/store_reg_statement.h"

VStoreRegStatement::VStoreRegStatement(
    VRegVariable *lhs_,
    VVariable    *rhs_
) : lhs(lhs_), rhs(rhs_) { }

void VStoreRegStatement::generate(Context *context) {
    lhs->generate(context);
    cout << " <= ";
    rhs->generate(context);
    cout << ";" << endl;
}
