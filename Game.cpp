#include "Game.h"

Game::Game(int size, QObject* parent)
    : QObject(parent)
    {
    board = new Board(size);
    logic = new Logic(board);
    visualization = new Visualization(this);
    connect(visualization, &Visualization::tileClicked, this, &Game::onTileClicked);
    connect(visualization, &Visualization::keyPressed, this, &Game::onKeyPressed);
}

Game::~Game() {
    delete logic;
    delete visualization;
}

void Game::startGame() {
    logic->startNewGame();
    visualization->updateBoardDisplay();
    visualization->show();
}

void Game::restartGame() {
    logic->resetGame();
    visualization->updateBoardDisplay();
}

bool Game::makeMove(int row, int col) {
    qDebug("game");
    score++;

    if (logic->makeMove(row, col)) {
        visualization->updateBoardDisplay();
        return true;
    }
    return false;
}

// int Game::getScore() {
//     return score;
// }

int Game::getBoardSize() const {
    return logic->getBoardSize();
}

Board* Game::getBoard() const {
    return board;
}

bool Game::isGameSolved() const {
    return logic->isGameSolved();
}

void Game::onTileClicked(int row, int col) {
    makeMove(row, col);
}

void Game::onKeyPressed(int key) {
    switch (key) {
    case Qt::Key_Up:
        logic->moveUp();
        break;
    case Qt::Key_Down:
        logic->moveDown();
        break;
    case Qt::Key_Left:
        logic->moveLeft();
        break;
    case Qt::Key_Right:
        logic->moveRight();
        break;
    default:
        break;
    }
    visualization->updateBoardDisplay();
}


void Game::onKeyPressedSlot(int key) {
    onKeyPressed(key);
}




