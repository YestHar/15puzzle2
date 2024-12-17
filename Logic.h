#ifndef LOGIC_H
#define LOGIC_H

#include "Board.h"

class Logic {
public:
    Logic(int size);  // Constructor to initialize the game logic
    ~Logic();  // Destructor to clean up

    void startNewGame();  // Start a new game
    bool makeMove(int row, int col);  // Make a move by swapping the tile with the zero tile
    bool isGameSolved() const;  // Check if the game is solved
    int getTile(int row, int col) const;  // Get the tile value at a specific position
    void resetGame();  // Reset the game
    int getBoardSize() const;  // Get the board size (e.g., 3x3, 4x4)

    // Movement functions to move the tiles
    void moveUp();  // Move the empty space up
    void moveDown();  // Move the empty space down
    void moveLeft();  // Move the empty space left
    void moveRight();  // Move the empty space right

private:
    int SIZE;  // The size of the board (e.g., 3 for 3x3, 4 for 4x4)
    Board* board;  // The game board
};

#endif // LOGIC_H
