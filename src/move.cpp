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

std::string Move::getNotation() {
    char startFile = 'a' + (startSquare % 8);
    char startRank = '1' + (7 - (startSquare / 8));
    char targetFile = 'a' + (targetSquare % 8);
    char targetRank = '1' + (7 - (targetSquare / 8));

    return std::string() + startFile + startRank + targetFile + targetRank;
}

bool Move::isInBoard(u_int8_t start, Direction direction) {
    int8_t targetLine = (start / 8) + (direction.second);
    int8_t targetCol = (start % 8) + (direction.first);
    return targetLine >= 0 && targetLine <= 7 && targetCol >= 0 && targetCol <= 7;
}

std::vector<Move> Move::getMoves(BoardState& state) {
    std::vector<Move> moves;

    for (size_t i = 0; i < state.position.size(); ++i) {
        Piece p = Piece(state.position[i]);
        if (p.type == PieceType::empty || p.isWhite != state.isWhiteTurn) {
            continue;
        }
        for (PieceMovements p_moves: PIECE_MOVEMENTS.at(p.type)) {
            for (Direction direction: p_moves.directions) {
                for (int distance = 1; distance <= p_moves.maxDistance; distance++) {
                    Direction totalDirection = {direction.first * distance
                            , direction.second * distance * (state.isWhiteTurn ? 1 : -1)};
                    if (!Move::isInBoard(i, totalDirection)) {
                        break;
                    }
                    u_int8_t targetSquare = i + totalDirection.first + totalDirection.second * 8;
                    Piece targetSquarePiece = Piece(state.position[targetSquare]);

                    if (targetSquarePiece.type != PieceType::empty 
                            && targetSquarePiece.isWhite != state.isWhiteTurn
                            && p_moves.canCapture) { // capture
                        moves.push_back(Move(i, targetSquare));
                        break;
                    } else if (targetSquarePiece.type == PieceType::empty
                            && !p_moves.mustCapture) { // not capture
                        moves.push_back(Move(i, targetSquare));
                    } else {
                        break;
                    }
                }
            }
        }
    }

    return moves;
}
