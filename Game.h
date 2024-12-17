#ifndef GAME_H
#define GAME_H

#include <QObject>
#include "Logic.h"
#include "Board.h"  // Include the full Board class here
// #include "Visualization.h"  // Include the full Visualization class
#include "mainWindow.h"

class Visualization;

class Game : public QObject {
    Q_OBJECT

public:
    // Constructor with a default board size, defaults to 3x3
    Game(int size = 3, QObject* parent = nullptr);
    ~Game();  // Destructor

    void startGame();  // Starts a new game
    void restartGame();  // Restarts the current game
    bool makeMove(int row, int col);  // Makes a move on the board

    // Getters
    int getBoardSize() const;
    bool isGameSolved() const;
    Board* getBoard() const;  // Returns a pointer to the Board

private:
    Board* board;  // Pointer to the game board
    Logic* logic = nullptr;  // Game logic
    Visualization* visualization = nullptr;  // UI for visualizing the game

private slots:
    // Slot to handle tile clicks
    void onTileClicked(int row, int col);

    // Slot to handle key presses
    void onKeyPressed(int key);
};

#endif // GAME_H
