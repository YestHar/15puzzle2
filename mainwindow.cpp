#include "mainWindow.h"
#include <QVBoxLayout>
#include <QPushButton>
#include <QPainter>
#include <QPen>
#include <QBrush>
#include <QFont>
#include <iostream>

MainWindow::MainWindow(QWidget *parent) : QWidget(parent)
{
    // Set up the main window layout
    QVBoxLayout *layout = new QVBoxLayout(this);

    // Initialize and set the Menu widget
    menu = new Menu(this);
    layout->addWidget(menu);

    setLayout(layout);
    setWindowTitle("15 Puzzle Game");

    resize(400, 300);  // Adjust the window size
}

MainWindow::~MainWindow()
{
    delete menu;
}

Visualization::Visualization(Game* game, QWidget* parent)
    : QWidget(parent), game(game), tileSize(100), margin(10) {
    setFixedSize(game->getBoardSize() * tileSize + margin * 2, game->getBoardSize() * tileSize + margin * 2);
}

Visualization::~Visualization() {}

void Visualization::updateBoardDisplay() {
    update();  // Request a repaint of the widget to update the display
}

void Visualization::paintEvent(QPaintEvent* ) {
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    drawBoard(painter);  // Draw the game board
    drawGrid(painter);   // Draw the grid lines
}

void Visualization::mousePressEvent(QMouseEvent* event) {
    QPointF position = event->position();  // Get the position of the mouse click
    int x = position.x() - margin;  // Subtract margin
    int y = position.y() - margin;

    if (x >= 0 && y >= 0) {
        handleClick(x, y);  // Determine which tile was clicked and emit the signal
    }
}

void Visualization::keyPressEvent(QKeyEvent* event) {
    emit keyPressed(event->key());  // Emit the key press signal
}

void Visualization::drawBoard(QPainter& painter) {
    if (game)
    {
        int boardSize = game->getBoardSize();
        for (int i = 0; i < boardSize; i++) {
            for (int j = 0; j < boardSize; j++) {
                int tileValue = game->getBoard()->getTile(i, j, boardSize);  // Get the tile value from the game logic
                // std::cout << tileValue;
                drawTile(i, j, tileValue, painter);  // Draw the tile using the painter
            }
        }
    }
}


void Visualization::drawTile(int row, int col, int tileValue, QPainter& painter) {
    int x = margin + col * tileSize;
    int y = margin + row * tileSize;

    QPen pen(Qt::black);
    QBrush brush(Qt::lightGray);

    painter.setPen(pen);
    painter.setBrush(brush);

    painter.drawRect(x, y, tileSize, tileSize);  // Draw tile background
    if (tileValue != 0) {  // 0 is the empty space
        QFont font = painter.font();
        font.setPointSize(24);
        painter.setFont(font);
        painter.drawText(x, y, tileSize, tileSize, Qt::AlignCenter, QString::number(tileValue));  // Draw the tile number
    }
}

void Visualization::drawGrid(QPainter& painter) {
    QPen pen(Qt::black);
    painter.setPen(pen);

    int boardSize = game->getBoardSize();
    for (int i = 0; i <= boardSize; i++) {
        painter.drawLine(margin, margin + i * tileSize, margin + boardSize * tileSize, margin + i * tileSize);  // Horizontal lines
        painter.drawLine(margin + i * tileSize, margin, margin + i * tileSize, margin + boardSize * tileSize);  // Vertical lines
    }
}


void Visualization::handleClick(int x, int y) {
    int row = (y - margin) / tileSize;
    int col = (x - margin) / tileSize;

    if (row >= 0 && col >= 0 && row < game->getBoardSize() && col < game->getBoardSize()) {
        emit tileClicked(row, col);  // Emit the signal for the clicked tile
    }
}
