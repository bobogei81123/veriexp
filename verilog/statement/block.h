#pragma once
#include "global.h"
#include "verilog/statement/statement.h"

typedef vector<VStatement*> StatementList;

struct VBlock : VStatement {
    StatementList statements;

    VBlock() {}

    void add_statement(VStatement*);
    virtual void generate(Context*);
};
