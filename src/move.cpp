#include "move.h"
#include "board.h"

Move::Move(u_int8_t startSquare, u_int8_t targetSquare) {
    this->startSquare = startSquare;
    this->targetSquare = targetSquare;
}

const std::map<PieceType, std::vector<PieceMovements>> Move::PIECE_MOVEMENTS = {
    {PieceType::rook, {
        PieceMovements{{{1, 0}, {-1, 0}, {0, 1}, {0, -1}}, true, false, 7}
    }}, {PieceType::knight, {
        PieceMovements{{{2, 1}, {2, -1}, {-2, 1}, {-2, -1}, {1, 2}, {1, -2}, {-1, 2}, {-1, -2}}, true, false, 1}
    }}, {PieceType::bishop, {
        PieceMovements{{{1, 1}, {-1, -1}, {1, -1}, {-1, 1}}, true, false, 7}
    }}, {PieceType::queen, {
        PieceMovements{{{1, 0}, {-1, 0}, {0, 1}, {0, -1}, {1, 1}, {-1, -1}, {1, -1}, {-1, 1}}, true, false, 7}
    }}, {PieceType::king, {
        PieceMovements{{{1, 0}, {-1, 0}, {0, 1}, {0, -1}, {1, 1}, {-1, -1}, {1, -1}, {-1, 1}}, true, false, 1}
    }}, {PieceType::pawn, {
        PieceMovements{{{0, -1}}, false, false, 1},  // Forward (for white !!)
        PieceMovements{{{-1, -1}, {1, -1}}, true, true, 1}  // Takes
    }},
};

bool Move::isInBoard(u_int8_t start, Direction direction) {
    int8_t targetLine = (start / 8) + (direction.second);
    int8_t targetCol = (start % 8) + (direction.first);
    return targetLine >= 0 && targetLine <= 7 && targetCol >= 0 && targetCol <= 7;
}
