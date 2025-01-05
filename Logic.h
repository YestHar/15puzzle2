#ifndef LOGIC_H
#define LOGIC_H

#include "Board.h"

class Logic {
public:
    Logic(Board* board);
    ~Logic();

    void startNewGame();
    bool makeMove(int row, int col);
    bool isGameSolved() const;
    int getTile(int row, int col) const;
    void resetGame();
    int getBoardSize() const;

    // Movement functions to move the tiles
    void moveUp();
    void moveDown();
    void moveLeft();
    void moveRight();

private:
    int SIZE = 4;
    Board* board;
};

#endif // LOGIC_H
