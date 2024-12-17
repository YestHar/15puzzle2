#include "Game.h"

Game::Game(int size, QObject* parent)
    : QObject(parent),
    logic(new Logic(size)),
    visualization(new Visualization(this)) {
    // Connect the signals from Visualization to Game slots
    connect(visualization, &Visualization::tileClicked, this, &Game::onTileClicked);
    connect(visualization, &Visualization::keyPressed, this, &Game::onKeyPressed);
}

Game::~Game() {
    delete logic;
    delete visualization;
}

void Game::startGame() {
    logic->startNewGame();  // Initialize the board
    visualization->updateBoardDisplay();  // Update the visualization with the initial board state
    visualization->show();
}

void Game::restartGame() {
    logic->resetGame();  // Reset the board
    visualization->updateBoardDisplay();  // Update the visualization with the new state
}

bool Game::makeMove(int row, int col) {
    // Try to make the move in the logic
    if (logic->makeMove(row, col)) {
        visualization->updateBoardDisplay();  // If the move is successful, update the visualization
        return true;
    }
    return false;  // If the move is invalid, return false
}

int Game::getBoardSize() const {
    return logic->getBoardSize();  // Return the current board size
}

Board* Game::getBoard() const {
    return board;  // Assuming 'board' is a pointer to the Board object
}

bool Game::isGameSolved() const {
    return logic->isGameSolved();  // Check if the game is solved
}

// Slot to handle tile click
void Game::onTileClicked(int row, int col) {
    makeMove(row, col);  // Call makeMove when a tile is clicked
}

// Slot to handle key press
void Game::onKeyPressed(int key) {
    switch (key) {
    case Qt::Key_Up:
        // Handle the "Up" key press (move tile up)
        logic->moveUp();
        break;
    case Qt::Key_Down:
        // Handle the "Down" key press (move tile down)
        logic->moveDown();
        break;
    case Qt::Key_Left:
        // Handle the "Left" key press (move tile left)
        logic->moveLeft();
        break;
    case Qt::Key_Right:
        // Handle the "Right" key press (move tile right)
        logic->moveRight();
        break;
    default:
        break;
    }
    visualization->updateBoardDisplay();  // Update the board display after a move
}
