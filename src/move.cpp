#include "move.h"

Move::Move(u_int8_t startSquare, u_int8_t targetSquare) {
    this->startSquare = startSquare;
    this->targetSquare = targetSquare;
}

const std::map<PieceType, std::vector<PieceMovements>> Move::PIECE_MOVEMENTS = {
    {PieceType::rook, {
        {{1, 0}, {-1, 0}, {0, 1}, {0, -1}, true, false, 7}
    }}, {PieceType::knight, {
        {{2, 1}, {2, -1}, {-2, 1}, {-2, -1}, {1, 2}, {1, -2}, {-1, 2}, {-1, -2}, true, false, 1}
    }}, {PieceType::bishop, {
        {{1, 1}, {-1, -1}, {1, -1}, {-1, 1}, true, false, 7}
    }}, {PieceType::queen, {
        {{1, 0}, {-1, 0}, {0, 1}, {0, -1}, {1, 1}, {-1, -1}, {1, -1}, {-1, 1}, true, false, 7}
    }}, {PieceType::king, {
        {{1, 0}, {-1, 0}, {0, 1}, {0, -1}, {1, 1}, {-1, -1}, {1, -1}, {-1, 1}, true, false, 1}
    }}, {PieceType::pawn, {
        {{0, -1}, false, false, 1},  // Forward (for white)
        {{-1, -1}, {1, -1}, true, true, 1}  // Takes
    }},
};

