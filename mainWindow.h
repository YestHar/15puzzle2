// mainwindow.h
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QKeyEvent>
#include <QMouseEvent>
#include "Game.h"
#include "Menu.h"

class Menu;
class Game;

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Menu* menu;  // Declare menu as a pointer to Menu

};



class Visualization : public QWidget {
    Q_OBJECT

public:
    explicit Visualization(Game* game, QWidget* parent = nullptr);
    ~Visualization();

    void updateBoardDisplay();  // Updates the display with the current game state
    void drawTile(int row, int col, int tileValue,QPainter& painter);  // Draws a single tile on the board

protected:
    void paintEvent(QPaintEvent*) override;  // Handles painting the board on the widget
    void mousePressEvent(QMouseEvent* event) override;  // Handles mouse click events
    void keyPressEvent(QKeyEvent* event) override;  // Handles key press events

signals:
    void tileClicked(int row, int col);  // Signal emitted when a tile is clicked
    void keyPressed(int key);            // Signal emitted when a key is pressed

private:
    Game* game;  // The game controller
    int tileSize;  // Size of each tile (pixels)
    int margin;  // Margin between tiles

    void drawBoard(QPainter& painter);  // Draws the entire board
    void drawGrid(QPainter& painter);  // Draws the grid lines
    void handleClick(int x, int y);    // Determines which tile was clicked based on the mouse coordinates
};

#endif // MAINWINDOW_H

