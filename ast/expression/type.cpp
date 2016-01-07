#include "ast/expression/type.h"

NType::NType(string name_) : name(name_) {
    if (name == "int") {
        length = 32;
        return;
    }
    assert(false);
}
