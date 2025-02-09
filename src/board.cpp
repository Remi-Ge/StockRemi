#include <iostream>
#include <sstream>
#include "board.h"
#include "piece.h"

Board::Board() {
    this->importFen("rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1");
}

Board::Board(const std::string& fen) {
    this->importFen(fen);
}

void Board::importFen(const std::string& fen) {
    std::istringstream fenStream(fen);
    std::string boardPart;
    fenStream >> boardPart;

    int index = 0;
    for (char c : boardPart) {
        if (c == '/') {
            continue;
        } else if (std::isdigit(c)) {
            for (int i = 0; i < c - '0'; i++) {
                position[index++] = Piece(' ').id;
            }            
        } else {
            this->position[index] = Piece(c).id;
            index++;
        }
    }
}

void Board::showBoard() {
    for (int x = 0; x < 8; x++) {
        std::cout << "  " << static_cast<char>('a' + x) << ' ';
    }
    std::cout << std::endl;
    for (int y = 0; y < 8; y++) {
        std::cout << "+---+---+---+---+---+---+---+---+" << std::endl;
        for (int x = 0; x < 8; x++) {
            int index = y * 8 + x;
            Piece p(position[index]);
            std::cout << "| " << p.getNotation() << ' ';
        }
        std::cout << "| " << std::abs(y - 8) << std::endl;
    }
    std::cout << "+---+---+---+---+---+---+---+---+" << std::endl;
}
