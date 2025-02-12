#include <iostream>
#include "board.h"
#include "move.h"

int main() {
    std::cout << "Welcome to StockRemi" << std::endl;

    Board board;
    board.showBoard();

    Move::getMoves(board.state);

    return 0;
}