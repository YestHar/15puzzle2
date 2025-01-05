// #ifndef GAME_H
// #define GAME_H

// #include <QObject>
// #include <QWidget>
// #include <QPushButton>
// #include <QLabel>
// #include <QVBoxLayout>
// #include <QHBoxLayout>
// #include <QKeyEvent>
// #include <QMouseEvent>
// #include <QMainWindow>
// #include "Logic.h"
// #include "Board.h"
// #include "mainWindow.h"

// class Visualization;


// class Game : public QMainWindow {
//     Q_OBJECT

// public:
//     explicit Game(int size = 3, const QString& playerName = QString(), QMainWindow* parent = nullptr);
//     ~Game();  // Destructor

//     void startGame();
//     void restartGame();
//     bool makeMove(int row, int col);

//     // Getters
//     int getBoardSize() const;
//     bool isGameSolved() const;
//     Board* getBoard() const;

// signals:
//     void menuRequested();  // Signal to go back to the menu
//     void gameFinished();

// public slots:
//     void onTileClicked(int row, int col);
//     void onKeyPressedSlot(int key);

// private slots:
//     void onKeyPressed(int key);
//     void onRestartClicked();
//     void onMenuClicked();
//     void incrementScore();

// protected:
//     void keyPressEvent(QKeyEvent* event) override;
//     void mousePressEvent(QMouseEvent* event) override;

// private:
//     void setupUI();
//     void updateScore();

//     int gridSize;
//     int stepsCount;
//     QString playerName;
//     Visualization* visualization = nullptr;

//     Board* board;
//     Logic* logic = nullptr;
//     QWidget* centralWidget;
//     QLabel* scoreLabel;
//     QPushButton* restartButton;
//     QPushButton* menuButton;

//     QVBoxLayout* mainLayout;
//     QHBoxLayout* topBarLayout;
//     QWidget* gameBoard;
// };

// #endif // GAME_H




#ifndef GAME_H
#define GAME_H

#include <QObject>
#include "Logic.h"
#include "Board.h"
#include "mainWindow.h"

class Visualization;

class Game : public QObject {
    Q_OBJECT

public:
    Game(int size = 3, QObject* parent = nullptr);
    ~Game();  // Destructor

    void startGame();
    void restartGame();
    bool makeMove(int row, int col);

    // Getters
    int getScore();
    int getBoardSize() const;
    bool isGameSolved() const;
    Board* getBoard() const;

private:
    int score = 0;
    Board* board;
    Logic* logic = nullptr;
    Visualization* visualization = nullptr;

public slots:
    void onKeyPressedSlot(int key);
    void onTileClicked(int row, int col);
private slots:
    void onKeyPressed(int key);
};

#endif // GAME_H
