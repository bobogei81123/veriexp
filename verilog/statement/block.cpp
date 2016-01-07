#include "verilog/statement/block.h"

void VBlock::add_statement(VStatement *statement) {
    statements.push_back(statement);
}

void VBlock::generate(Context *context) {
    cout << "begin" << endl;
    for (auto x: statements) {
        x->generate(context);
    }
    cout << "end" << endl;
}
