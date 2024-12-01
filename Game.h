#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include "Board.cpp"
#include "Player.h"
#include "Piece.cpp"
#include <utility>  // For std::pair

class Game {
private:
    Board board;
    Player whitePlayer;
    Player blackPlayer;
    bool isWhiteTurn;
    bool gameStarted;
    bool firstMoveMade;
    std::pair<int, int> sqClicked;

    sf::RenderWindow window;
    sf::Font font;
    sf::Text startButton;
    
    sf::Texture backgroundTexture;
    sf::Sprite backgroundSprite;

public:
    Game();
    void run();

private:
    void handleEvents();
    void render();
    void initializeWindow();
};

#endif // GAME_H
