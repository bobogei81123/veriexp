#ifndef CONTEXT_H_GUARD
#define CONTEXT_H_GUARD
#include <bits/stdc++.h>

struct StateManager;

#include "verilog/variable/named_variable.h"
#include "verilog/module/module.h"

using namespace std;

struct BlockScope;

struct Context {
    stack<BlockScope*> blocks;
    StateManager *state_manager;
    VModule *module;

    Context();

    void add_input (string name, int);
    void add_output(string name, int);
    void add_wire  (string name, string);
    void add_reg   (string name, string);

    void add_statement(int state);  
};

struct BlockScope {
    map<string, string> vars;
};

struct StateManager {
    vector<int> djs;
    int state_n;
    int new_state();
    vector<int> new_states(int);
    int find(int);
};
#endif
