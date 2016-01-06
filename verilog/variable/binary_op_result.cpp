#include "verilog/variable/binary_op_result.h"

VBinaryOPResult::VBinaryOPResult(
        VVariable *lhs_, VVariable *rhs_, string op_
) : VTempVariable(0), lhs(lhs_), rhs(rhs_), op(op_) {
}
