#include <iostream>
#include "board.h"
#include "move.h"

int main() {
    std::cout << "Welcome to StockRemi" << std::endl;

    Board board;
    board.showBoard();

    std::cout << Move::getMoves(board.state).size() << " moves" << std::endl;


    return 0;
}