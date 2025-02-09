#include "piece.h"

const std::map<PieceType, PieceInfo> Piece::pieceRepresentations = {
    {PieceType::empty, {'.', '.', L'.', L'.'}},
    {PieceType::rook, {'R', 'r', L'♜', L'♖'}},
    {PieceType::knight, {'N', 'n', L'♞', L'♘'}},
    {PieceType::bishop, {'B', 'b', L'♝', L'♗'}},
    {PieceType::queen, {'Q', 'q', L'♛', L'♕'}},
    {PieceType::king, {'K', 'k', L'♚', L'♔'}},
    {PieceType::pawn, {'P', 'p', L'♟', L'♙'}},
};

Piece::Piece(u_int8_t id) {
    isWhite = (id & 0b1000) == 0;
    type = static_cast<PieceType>(id & 0b0111);
}

char Piece::getNotation() {
    PieceInfo info = pieceRepresentations.at(type);
    if (isWhite) {
        return info.whiteNotation;
    }
    return info.blackNotation;
}

wchar_t Piece::getSymbol() {
    PieceInfo info = pieceRepresentations.at(type);
    if (isWhite) {
        return info.whiteSymbol;
    }
    return info.blackSymbol;
}