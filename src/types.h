#ifndef TYPES_H
#define TYPES_H

#include <iostream>
#include <array>

using Direction = std::pair<int, int>;

struct BoardState {
    std::array<u_int8_t, 64> position;
    bool isWhiteTurn;
};

#endif
