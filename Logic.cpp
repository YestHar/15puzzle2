#include "Logic.h"
#include <QPair>
#include <cstdlib>

Logic::Logic(Board* other_board) : board(other_board){
}

Logic::~Logic() {
    delete board;
}

void Logic::startNewGame() {
    board->initialize();
}

bool Logic::makeMove(int row, int col) {
    QPair<int, int> zeroPos = board->findZero();

    if ((std::abs(zeroPos.first - row) == 1 && zeroPos.second == col) ||
        (std::abs(zeroPos.second - col) == 1 && zeroPos.first == row)) {

        return board->swap(row, col, zeroPos.first, zeroPos.second);
    }
    return false;
}

bool Logic::isGameSolved() const {
    return board->isBoardSolved();
}

int Logic::getTile(int row, int col) const {
    return board->getTile(row, col, 3);
}

void Logic::resetGame() {
    board->initialize();
}

int Logic::getBoardSize() const {
    return board->getSize();
}


void Logic::moveDown() {
    QPair<int, int> zeroPos = board->findZero();
    int row = zeroPos.first;
    int col = zeroPos.second;


    if (row > 0) {
        board->swap(row, col, row - 1, col);
    }
}

void Logic::moveUp() {
    QPair<int, int> zeroPos = board->findZero();
    int row = zeroPos.first;
    int col = zeroPos.second;

    if (row < SIZE - 1) {
        board->swap(row, col, row + 1, col);
    }
}

void Logic::moveRight() {
    QPair<int, int> zeroPos = board->findZero();
    int row = zeroPos.first;
    int col = zeroPos.second;

    if (col > 0) {
        board->swap(row, col, row, col - 1);
    }
}

void Logic::moveLeft() {
    QPair<int, int> zeroPos = board->findZero();
    int row = zeroPos.first;
    int col = zeroPos.second;

    if (col < SIZE - 1) {
        board->swap(row, col, row, col + 1);
    }
}
