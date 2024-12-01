#ifndef BOARD_H
#define BOARD_H

#include <SFML/Graphics.hpp>
#include <map>
#include <vector>
#include <string>
#include "Piece.h"

class Board {
private:
    Piece* squares[8][8];
    std::map<std::string, sf::Texture> images;

    void drawBoard(sf::RenderWindow& window);
    void drawPieces(sf::RenderWindow& window);
    void loadImages();

public:
    static const int BOARD_SIZE = 8;
    static const int SQUARE_SIZE = 100;

    Board();
    ~Board();

    void draw(sf::RenderWindow& window);
    bool movePiece(int r1, int c1, int r2, int c2, bool isWhiteTurn);
};

#endif // BOARD_H
