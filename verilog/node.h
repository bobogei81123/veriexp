#ifndef VERILOG_NODE_H_GUARD_INC
#define VERILOG_NODE_H_GUARD_INC

#include <bits/stdc++.h>
struct VModule;
#include "context/context.h"

using namespace std;

struct VNode {
    virtual void generate() {}
};

struct VIdentifier : VNode {
    string name;
    virtual void generate() {
        cout << name << endl;
    }
};

enum class VVarWRType {
    Wire,
    Reg
};

enum class VVarIOType {
    Input,
    Output,
    Normal
};

struct VVariable : VNode {
    string name;
    VVarWRType wrtype;
    VVarIOType iotype;
    int length;

    VVariable(string name_, 
              VVarWRType wrtype_,
              VVarIOType iotype_ = VVarIOType::Normal,
              int length_ = 1
              );

    void generate_declaration();
};

struct VStatement : VNode {
};

struct VAdd : VStatement {
    VStatement *lhs, *rhs;
};

typedef vector<VVariable*> VVarList;

struct VModule : VNode {
    string name;
    VVarList vars;

    StateManager *state_manager;

    virtual void generate();
};

#endif   /* ----- #ifndef NODE_H_GUARD_INC  ----- */
