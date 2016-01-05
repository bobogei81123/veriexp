#include "context.h"

Context::Context() {
    state_manager = new StateManager();
    module = new VModule();

    add_input("clk", 1);
    add_input("reset", 1);
}

void Context::add_input (string name, int length) {
    auto nv = new VVariable(name, VVarWRType::Wire, VVarIOType::Input, length);
    module->vars.push_back(nv);
}

int StateManager::new_state() {
    int ret = state_n ++;
    djs.push_back(ret);
    return ret;
}

vector<int> StateManager::new_states(int num) {
    vector<int> ret;
    for (int i=0; i<num; i++) {
        int x = state_n ++;
        djs.push_back(x);
        ret.push_back(x);
    }
    return ret;
}

int StateManager::find(int a) {
    return djs[a] == a ? a : (djs[a] = find(djs[a]));
}

