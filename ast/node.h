#pragma once
#include "global.h"
#include "context/context.h"

struct Node {
    //virtual ~Node() {}
    virtual void generate(Context *context) {}
};

