#ifndef INFO_H
#define INFO_H

#include "state.h"
#include <cstddef>

struct Info {
    size_t row, col;
    State thing;
};

#endif
