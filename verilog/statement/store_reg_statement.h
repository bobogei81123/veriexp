#pragma once
#include "global.h"
#include "verilog/statement/statement.h"
#include "verilog/variable/reg_variable.h"

struct VStoreRegStatement : VStatement {
    VRegVariable *lhs;
    VVariable *rhs;

    VStoreRegStatement(VRegVariable *lhs_, VVariable *rhs_);
    
    virtual void generate(Context *context);
};
