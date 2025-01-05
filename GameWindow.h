#ifndef GAMEWIDGETANDWINDOW_H
#define GAMEWIDGETANDWINDOW_H

#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QKeyEvent>
#include <QMouseEvent>
#include "Game.h"

#include "mainwindow.h"

class Visualization;


class Game;

class GameWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit GameWindow(QWidget* parent = nullptr);
    ~GameWindow();

    void startGame(int size, const QString& playerName);
    void restartGame();
    void updateBoardDisplay();

signals:
    void menuRequested();
    void gameFinished();
    void tileClicked(int row, int col);
    void keyPressed(int key);
    void sendUpdateScore();

protected:
    void mousePressEvent(QMouseEvent* event) override;
    void keyPressEvent(QKeyEvent* event) override;

private slots:
    void onRestartClicked();
    void onMenuClicked();
    void handleTileClicked(int row, int col);
    void incrementScore();

private:
    void setupUI();
    void updateScore();

    // UI components
    QWidget* centralWidget;
    QLabel* scoreLabel;
    QPushButton* restartButton;
    QPushButton* menuButton;

    Visualization* visualizationWidget;

    Game* game;
    int gridSize;
    int stepsCount;
    QString playerName;
};

#endif // GAMEWIDGETANDWINDOW_H


