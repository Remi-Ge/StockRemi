#ifndef MOVE_H
#define MOVE_H

#include <iostream>
#include <vector>
#include "types.h"
#include <map>
#include "piece.h"

struct PieceMovements {
    std::vector<Direction> directions;
    bool canCapture;
    bool mustCapture;
    int maxDistance;
    // always opposite if black
};

class Move {
private:
    static bool isInBoard(u_int8_t start, Direction offset);
    static const std::map<PieceType, std::vector<PieceMovements>> PIECE_MOVEMENTS;
public:
    Move(u_int8_t startSquare, u_int8_t targetSquare);
    u_int8_t startSquare;
    u_int8_t targetSquare;
    std::string getNotation();

    static std::vector<Move> getMoves(BoardState& state);
};

#endif