#include "context/context.h"

Context::Context() {
    module = new VModule();
}

void Context::add_input (string name, int length) {
    auto nv_ = new VNamedVariable(name, length, VVarWRType::Wire, VVarIOType::Input);
    module->vars.push_back(nv_);
}

void Context::add_output (string name, int length) {
    auto nv = new VNamedVariable(name, length, VVarWRType::Reg, VVarIOType::Output);
    module->vars.push_back(nv);
}

VRegVariable* Context::add_reg (string name, int length) {
    auto nv = new VRegVariable(name, length);
    module->vars.push_back(nv);
    return nv;
}


void Context::add_statement (int state, VStatement *statement) {
    module->state_desc[state].first->add_statement(statement);
}

void Context::set_next_state (int state, int next_state) {
    module->state_desc[state].second = next_state;
}


int Context::new_state() {
    int ret = state_n ++;
    djs.push_back(ret);
    module->state_desc[ret].first = new VBlock();
    return ret;
}

vector<int> Context::new_states(int num) {
    vector<int> ret;
    for (int i=0; i<num; i++) {
        int x = state_n ++;
        djs.push_back(x);
        ret.push_back(x);
    }
    return ret;
}

int Context::find_state(int a) {
    return djs[a] == a ? a : (djs[a] = find_state(djs[a]));
}

