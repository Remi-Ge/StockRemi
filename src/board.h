#ifndef BOARD_H
#define BOARD_H

#include <iostream>
#include <array>
#include "move.h"
#include "types.h"

class Board {
private:
    void importFen(const std::string& fen);
public:
    Board();
    Board(const std::string& fen);
    void showBoard();
    BoardState state;
};

#endif