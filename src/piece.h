#ifndef PIECE_H
#define PIECE_H

#include <iostream>
#include <map>

enum class PieceType {
    empty,
    rook,
    knight,
    bishop,
    queen,
    king,
    pawn
};

struct PieceInfo {
    char whiteNotation;
    char blackNotation;
    wchar_t whiteSymbol;
    wchar_t blackSymbol;
};

class Piece {
private:
    static const std::map<PieceType, PieceInfo> pieceRepresentations;
public:
    Piece(u_int8_t id);
    Piece(char notation);
    u_int8_t id;
    PieceType type;
    bool isWhite;
    char getNotation();
    wchar_t getSymbol();
};

#endif