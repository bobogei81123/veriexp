#ifndef NODE_H_GUARD
#define NODE_H_GUARD
#include <bits/stdc++.h>
using namespace std;

struct NVariableDeclaration;
struct NType;
struct NIdentifier;
struct NBlock;
typedef vector<NVariableDeclaration*> VariableList;

struct Node {
    virtual ~Node() {}
    virtual void generate() {}
};

struct NStatement : Node {
};

struct NExpression : Node {
};

struct NIdentifier : NExpression {
    string name;
    NIdentifier(string name_) : name(name_) {}

    virtual void generate() {
        cout << name;
    }
};

struct NFunctionDeclaration : NStatement {
    NType *type;
    NIdentifier *id;
    VariableList args;
    NBlock *block;

    NFunctionDeclaration(
        NType *type_,
        NIdentifier *id_,
        VariableList args_,
        NBlock *block_
    ) : type(type_), id(id_), args(args_), block(block_) { }

    virtual void generate() {
        cout << "module ";
        id->generate();
        cout << "(input start, output done);" << endl;
        cout << "endmodule";
    }
};

struct NType : NExpression {
    string name;
    NType(string name_) : name(name_) {}
};


struct NBlock : NExpression {
};

struct NVariableDeclaration : NStatement {
};
#endif 
