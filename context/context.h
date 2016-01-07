#ifndef CONTEXT_H_GUARD
#define CONTEXT_H_GUARD
#include <bits/stdc++.h>

struct StateManager;

#include "verilog/variable/named_variable.h"
#include "verilog/variable/reg_variable.h"
#include "verilog/module/module.h"
#include "verilog/statement/statement.h"

using namespace std;

struct BlockScope;

struct Context {
    stack<BlockScope*> blocks;
    VModule *module;
    int cur_state;
    VNamedVariable *state_var;
    map<string, VNamedVariable*> ident_map;

    Context();

    void add_input (string name, int);
    void add_output(string name, int);
    VRegVariable* add_reg   (string name, int);
    void add_wire  (string name, string);

    void add_statement(int state, VStatement*);  
    void set_next_state(int state, int next_state);  

    vector<int> djs;
    int state_n;
    int new_state();
    vector<int> new_states(int);
    int find_state(int);
};

struct BlockScope {
    map<string, string> vars;
};

#endif
