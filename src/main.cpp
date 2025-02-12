#include <iostream>
#include "board.h"
#include "move.h"

int main() {
    std::cout << "Welcome to StockRemi" << std::endl;

    Board board = Board("8/8/8/2ppp3/2pQp3/2ppp3/8/8 w - - 0 1");
    board.showBoard();

    std::cout << Move::getMoves(board.state).size() << " moves" << std::endl;


    return 0;
}