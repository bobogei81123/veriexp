#pragma once
#include "global.h"
#include "verilog/statement/statement.h"
#include "verilog/statement/block.h"
#include "verilog/variable/variable.h"

typedef pair<VVariable*, VBlock*> ConditionPair;
typedef vector<ConditionPair> ConditionList;

struct VCondition : VStatement {
    ConditionList conditions;

    VCondition() {}

    void add_condition(VVariable*, VBlock*);
    virtual void generate(Context *context);
};
