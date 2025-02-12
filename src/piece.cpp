#include "piece.h"

const std::map<PieceType, PieceInfo> Piece::pieceRepresentations = {
    {PieceType::empty, {' ', ' ', "Empty"}},
    {PieceType::rook, {'R', 'r', "Rook"}},
    {PieceType::knight, {'N', 'n', "Knight"}},
    {PieceType::bishop, {'B', 'b', "Bishop"}},
    {PieceType::queen, {'Q', 'q', "Queen"}},
    {PieceType::king, {'K', 'k', "King"}},
    {PieceType::pawn, {'P', 'p', "Pawn"}},
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
