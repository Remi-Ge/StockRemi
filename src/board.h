#ifndef BOARD_H
#define BOARD_H

#include <iostream>
#include <array>

class Board {
private:
    std::array<u_int8_t, 64> position = {};
    void importFen(const std::string& fen);
public:
    Board();
    Board(const std::string& fen);
    void showBoard();
};

#endif