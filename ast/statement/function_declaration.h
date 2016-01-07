#pragma once
#include "global.h"
#include "ast/statement/statement.h"
#include "ast/statement/funcarg_declaration.h"
#include "ast/statement/block.h"

typedef vector<NFuncArgDeclaration*> ArgList;

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
    );

    virtual void generate(Context *context);
};
