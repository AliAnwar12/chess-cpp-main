#ifndef PIECE_H
#define PIECE_H

#include <string>

class Piece {
private:
    bool isWhite;
    std::string name;

public:
    Piece(bool isWhite);
    virtual ~Piece();

    virtual bool isValidMove(int startX, int startY, int endX, int endY) = 0;
    bool getIsWhite() const;
    std::string getName() const;

protected:
    void setName(const std::string& n);
};

class King : public Piece {
public:
    King(bool isWhite);
    bool isValidMove(int startX, int startY, int endX, int endY) override;
};

class Queen : public Piece {
public:
    Queen(bool isWhite);
    bool isValidMove(int startX, int startY, int endX, int endY) override;
};

class Rook : public Piece {
public:
    Rook(bool isWhite);
    bool isValidMove(int startX, int startY, int endX, int endY) override;
};

class Bishop : public Piece {
public:
    Bishop(bool isWhite);
    bool isValidMove(int startX, int startY, int endX, int endY) override;
};

class Knight : public Piece {
public:
    Knight(bool isWhite);
    bool isValidMove(int startX, int startY, int endX, int endY) override;
};

class Pawn : public Piece {
public:
    Pawn(bool isWhite);
    bool isValidMove(int startX, int startY, int endX, int endY) override;
};

#endif // PIECE_H
