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
    this->id = id;
    this->isWhite = (id & 0b1000) == 0;
    this->type = static_cast<PieceType>(id & 0b0111);
}

Piece::Piece(char notation) {
    for (const auto& [type, info] : pieceRepresentations) {
        if (notation == info.whiteNotation) {
            this->isWhite = true;
            this->type = type;
            break;
        }
        if (notation == info.blackNotation) {
            this->isWhite = false;
            this->type = type;
            break;
        }
    }
    this->id = (isWhite ? 0 : 0b1000) | (static_cast<u_int8_t>(type) & 0b0111);
}

char Piece::getNotation() {
    PieceInfo info = pieceRepresentations.at(this->type);
    return this->isWhite ? info.whiteNotation : info.blackNotation;
}

wchar_t Piece::getSymbol() {
    PieceInfo info = pieceRepresentations.at(this->type);
    return this->isWhite ? info.whiteSymbol : info.blackSymbol;
}