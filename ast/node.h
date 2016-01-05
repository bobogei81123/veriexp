#ifndef NODE_H_GUARD
#define NODE_H_GUARD
#include <bits/stdc++.h>
#include "context/context.h"
#include "verilog/node.h"
using namespace std;

struct NVariableDeclaration;
struct NType;
struct NIdentifier;
struct NBlock;
struct NFuncArgDeclaration;
typedef vector<NVariableDeclaration*> VariableList;
typedef vector<NFuncArgDeclaration*> ArgList;

struct Node {
    //virtual ~Node() {}
    virtual void generate(Context *context) {}
};

struct NStatement : Node {
    virtual void generate(Context *context) {}
};

struct NExpression : Node {
};

struct NIdentifier : NExpression {
    string name;
    NIdentifier(string name_) : name(name_) {}

    //virtual void generate(Context *context) { }
};

struct NVariableDeclaration : NStatement {
    NIdentifier *name;
    NType *type;

    NVariableDeclaration(NIdentifier*, NType*);

    virtual void generate(Context *context) {}
};

struct NFuncArgDeclaration : NVariableDeclaration {
    NFuncArgDeclaration(NIdentifier *name_, NType *type_);
    virtual void generate(Context *context);
};

struct NFunctionDeclaration : NStatement {
    NType *type;
    NIdentifier *id;
    ArgList args;
    NBlock *block;

    NFunctionDeclaration(
        NType *type_,
        NIdentifier *id_,
        ArgList args_,
        NBlock *block_
    ) : type(type_), id(id_), args(args_), block(block_) { }

    virtual void generate(Context *context) {
        context->module->name = id->name;
        for (auto x: args) {
            x->generate(context);
        }
    }
};

struct NType : NExpression {
    string name;
    int length;
    NType(string name_);
};


struct NBlock : NExpression {
};

#endif 
