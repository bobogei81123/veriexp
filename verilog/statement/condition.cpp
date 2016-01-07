#include "verilog/statement/condition.h"

void VCondition::add_condition(
    VVariable *condition_variable,
    VBlock *block
) {
    conditions.push_back({condition_variable, block});
}

void VCondition::generate(Context *context) {
    assert(conditions.size() == 1);
    cout << "if (";
    conditions[0].first ->generate(context);
    cout << ")" << endl;
    conditions[0].second->generate(context);
}
