#include <iostream>
#include "Game.h"
#include <SFML/Graphics.hpp>

using namespace std;

Game::Game() : whitePlayer(true), blackPlayer(false), isWhiteTurn(true), gameStarted(false), firstMoveMade(false) {
    initializeWindow();
}

void Game::run() {
    while (window.isOpen()) {
        handleEvents();
        render();
    }
}

void Game::handleEvents() {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window.close();
        }

        if (!gameStarted && event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
            if (startButton.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
                gameStarted = true;
            }
        }

        if (gameStarted && event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
            int col = event.mouseButton.x / Board::SQUARE_SIZE;
            int row = event.mouseButton.y / Board::SQUARE_SIZE;

            cout << "Clicked square: (" << row << ", " << col << ")" << endl;

            // if click on same square
            if (row == sqClicked.first && col == sqClicked.second) {
                cout << "Same square" << endl;
                sqClicked = std::make_pair(-1, -1);
                firstMoveMade = false;
                continue;
            }

            // if one click is already done
            if (firstMoveMade) {
                cout << "Second click" << endl;
                bool moveMade = board.movePiece(sqClicked.first, sqClicked.second, row, col, isWhiteTurn);
                cout << "Move made: " << moveMade << endl;
                if (!moveMade) {
                    cout << "Invalid move" << endl;
                    sqClicked = std::make_pair(-1, -1);
                    firstMoveMade = false;
                    continue;
                }

                isWhiteTurn = !isWhiteTurn;
                sqClicked = std::make_pair(-1, -1);
                firstMoveMade = false;
            } else {
                cout << "First click" << endl;
                firstMoveMade = true;
                sqClicked = std::make_pair(row, col);
            }
        }
    }
}

void Game::render() {
    window.clear();

    if (!gameStarted) {
        window.draw(backgroundSprite);
        window.draw(startButton);
    } else {
        board.draw(window);
    }

    window.display();
}

void Game::initializeWindow() {
    window.create(sf::VideoMode(Board::BOARD_SIZE * Board::SQUARE_SIZE, Board::BOARD_SIZE * Board::SQUARE_SIZE), "Chess");

    if (!backgroundTexture.loadFromFile("background.jpg")) {
    }
    backgroundSprite.setTexture(backgroundTexture);

    if (!font.loadFromFile("arial.ttf")) {
    }

    startButton.setFont(font);
    startButton.setString("Start");
    startButton.setCharacterSize(24);
    startButton.setFillColor(sf::Color::White);
    startButton.setPosition((Board::BOARD_SIZE * Board::SQUARE_SIZE) / 2, (Board::BOARD_SIZE * Board::SQUARE_SIZE) / 2);
}
