#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStackedLayout>
#include <QGridLayout>
#include <QPushButton>
#include <vector>
#include "NameInputWindow.h"
#include "MatrixSizeSelectionWindow.h"
#include "GameWindow.h"
#include "RecordsWindow.h"
#include "Menu.h"
#include "Game.h"

class Game;
class Menu;
class GameWindow;

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget* parent = nullptr);
    ~MainWindow();
    QString playerName;

private:
    Menu* menu;
    NameInputWindow* nameInputWindow;
    MatrixSizeSelectionWindow* matrixSizeSelectionWindow;
    GameWindow* gameWindow;
    RecordsWindow* recordsWindow;

    QWidget* centralWidget;
    QStackedLayout* layout;


    Game* currentGame;

    void setupUI();

private slots:
    void onPlayerNameEntered(const QString& playerName);
    void onMatrixSizeSelected(int size);
    void onStartGame(int size, const QString& playerName);
    void onBackToMenu();
    void showRecords();
    void startNewGame();
};




// // mainwindow.h
// #ifndef MAINWINDOW_H
// #define MAINWINDOW_H

// #include <QMainWindow>
// #include <QStackedLayout>
// #include "Menu.h"
// #include "ScorePanel.h"
// #include "GameWidget.h"
// #include "RecordsWidget.h"  // Assuming you create a widget for displaying records

// class Game;
// class GameWidget;

// class MainWindow : public QMainWindow {
//     Q_OBJECT

// public:
//     explicit MainWindow(QWidget* parent = nullptr);
//     ~MainWindow();

// private:
//     Menu* menuWidget;          // The menu widget
//     ScorePanel* scorePanel;    // The score panel widget
//     GameWidget* gameWidget;    // The game widget
//     RecordsWidget* recordsWidget;  // Widget to display game records

//     QWidget* centralWidget;    // Central widget to hold everything
//     QStackedLayout* layout;    // Stacked layout to switch widgets

//     void setupUI();

// private slots:
//     void onStartGame(int size, const QString& playerName);
//     void showRecords();  // Slot to display the records widget
// };


// class MainWindow : public QWidget
// {
//     Q_OBJECT

// public:
//     explicit MainWindow(QWidget *parent = nullptr);
//     ~MainWindow();

// private:
//     Menu* menu;  // Declare menu as a pointer to Menu

// };



// class Visualization : public QMainWindow {
//     Q_OBJECT

// public:
//     explicit Visualization(Game* game, QMainWindow* parent = nullptr);
//     ~Visualization();

//     void updateBoardDisplay();  // Updates the display with the current game state
//     void drawTile(int row, int col, int tileValue,QPainter& painter);  // Draws a single tile on the board

// protected:
//     void paintEvent(QPaintEvent*) override;  // Handles painting the board on the widget
//     void mousePressEvent(QMouseEvent* event) override;  // Handles mouse click events
//     void keyPressEvent(QKeyEvent* event) override;  // Handles key press events

// signals:
//     void tileClicked(int row, int col);  // Signal emitted when a tile is clicked
//     void keyPressed(int key);            // Signal emitted when a key is pressed

// private:
//     Game* game;  // The game controller
//     int tileSize;  // Size of each tile (pixels)
//     int margin;  // Margin between tiles

//     void drawBoard(QPainter& painter);  // Draws the entire board
//     void drawGrid(QPainter& painter);  // Draws the grid lines
//     void handleClick(int x, int y);    // Determines which tile was clicked based on the mouse coordinates
// };


class Visualization : public QMainWindow {
    Q_OBJECT

public:
    explicit Visualization(Game* game, QMainWindow* parent = nullptr);
    ~Visualization();

    void updateBoardDisplay();  // Updates the display with the current game state

signals:
    void tileClicked(int row, int col);  // Signal emitted when a tile is clicked
    void keyPressed(int key);           // Signal emitted when a key is pressed

protected:
    void keyPressEvent(QKeyEvent* event) override;   // Handles key press events

private:
    Game* game;                            // The game controller
    QGridLayout* gridLayout;               // Grid layout for tiles
    std::vector<QPushButton*> buttons;     // Push buttons representing tiles
    int tileSize;                          // Size of each tile (pixels)
    int margin;                            // Margin between tiles

    void initializeBoard();                // Sets up the grid layout and buttons
    void clearBoard();                     // Removes existing buttons
    void adjustTileSize();                 // Adjusts the size of the buttons dynamically
    void handleClick(int row, int col);    // Handles the click event of a tile
};

#endif // MAINWINDOW_H

