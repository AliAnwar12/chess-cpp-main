#include "Piece.h"

// Piece class implementation
Piece::Piece(bool isWhite): isWhite(isWhite), name("--") {}
Piece::~Piece() {}

bool Piece::getIsWhite() const { 
    return isWhite; 
}

std::string Piece::getName() const {
    return name;
}

void Piece::setName(const std::string& n) {
    name = n;
}

// King class implementation
King::King(bool isWhite): Piece(isWhite) {
    setName(isWhite ? "wK" : "bK");
}

bool King::isValidMove(int startX, int startY, int endX, int endY) {
    return true;
}

// Queen class implementation
Queen::Queen(bool isWhite): Piece(isWhite) {
    setName(isWhite ? "wQ" : "bQ");
}

bool Queen::isValidMove(int startX, int startY, int endX, int endY) {
    return true;
}

// Rook class implementation
Rook::Rook(bool isWhite): Piece(isWhite) {
    setName(isWhite ? "wR" : "bR");
}

bool Rook::isValidMove(int startX, int startY, int endX, int endY) {
    return true;
}

// Bishop class implementation
Bishop::Bishop(bool isWhite): Piece(isWhite) {
    setName(isWhite ? "wB" : "bB");
}

bool Bishop::isValidMove(int startX, int startY, int endX, int endY) {
    return true;
}

// Knight class implementation
Knight::Knight(bool isWhite): Piece(isWhite) {
    setName(isWhite ? "wN" : "bN");
}

bool Knight::isValidMove(int startX, int startY, int endX, int endY) {
    return true;
}

// Pawn class implementation
Pawn::Pawn(bool isWhite): Piece(isWhite) {
    setName(isWhite ? "wp" : "bp");
}

bool Pawn::isValidMove(int startX, int startY, int endX, int endY) {
    return true;
}
