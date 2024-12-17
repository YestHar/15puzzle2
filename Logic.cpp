#include "Logic.h"
#include <QPair>
#include <cstdlib>  // For std::abs

Logic::Logic(int size) : SIZE(size) {
    board = new Board(SIZE);  // Create a new Board with the specified size
}

Logic::~Logic() {
    delete board;  // Clean up dynamically allocated memory for the board
}

void Logic::startNewGame() {
    board->initialize();  // Initialize the board with random tiles
}

bool Logic::makeMove(int row, int col) {
    QPair<int, int> zeroPos = board->findZero();  // Find the empty tile (zero)

    // Check if the move is valid (adjacent to the zero tile)
    if ((std::abs(zeroPos.first - row) == 1 && zeroPos.second == col) ||
        (std::abs(zeroPos.second - col) == 1 && zeroPos.first == row)) {

        // If the move is valid, swap the tiles
        return board->swap(row, col, zeroPos.first, zeroPos.second);
    }
    return false;  // Return false if the move is not valid
}

bool Logic::isGameSolved() const {
    return board->isBoardSolved();  // Check if the board is in the solved state
}

int Logic::getTile(int row, int col) const {
    return board->getTile(row, col, 3);  // Get the value of a tile at a specific position
}

void Logic::resetGame() {
    board->initialize();  // Reinitialize the board to start a new game
}

int Logic::getBoardSize() const {
    return board->getSize();  // Return the size of the board (e.g., 3x3, 4x4)
}

// Movement functions to update the board state

void Logic::moveUp() {
    QPair<int, int> zeroPos = board->findZero();
    int row = zeroPos.first;
    int col = zeroPos.second;

    // If the zero is not already at the top row, move it up
    if (row > 0) {
        board->swap(row, col, row - 1, col);
    }
}

void Logic::moveDown() {
    QPair<int, int> zeroPos = board->findZero();
    int row = zeroPos.first;
    int col = zeroPos.second;

    // If the zero is not already at the bottom row, move it down
    if (row < SIZE - 1) {
        board->swap(row, col, row + 1, col);
    }
}

void Logic::moveLeft() {
    QPair<int, int> zeroPos = board->findZero();
    int row = zeroPos.first;
    int col = zeroPos.second;

    // If the zero is not already at the leftmost column, move it left
    if (col > 0) {
        board->swap(row, col, row, col - 1);
    }
}

void Logic::moveRight() {
    QPair<int, int> zeroPos = board->findZero();
    int row = zeroPos.first;
    int col = zeroPos.second;

    // If the zero is not already at the rightmost column, move it right
    if (col < SIZE - 1) {
        board->swap(row, col, row, col + 1);
    }
}
