#include "MainWindow.h"
#include "NameInputWindow.h"
#include "MatrixSizeSelectionWindow.h"
#include "GameWindow.h"
#include "RecordsWindow.h"
#include <QStackedLayout>
#include <QPainter>
#include <QMouseEvent>
#include "Menu.h"
#include <QPushButton>



// MainWindow::MainWindow(QWidget* parent)
//     : QMainWindow(parent),
//     menu(new Menu(this)),
//     nameInputWindow(new NameInputWindow(this)),
//     matrixSizeSelectionWindow(new MatrixSizeSelectionWindow(this)),
//     gameWindow(new GameWindow(this)),
//     recordsWindow(new RecordsWindow(this)),
//     layout(new QStackedLayout),
//     currentGame(nullptr) {
//     setupUI();
// }

// MainWindow::~MainWindow() {
//     delete layout;
//     delete menu;
//     delete nameInputWindow;
//     delete matrixSizeSelectionWindow;
//     delete gameWindow;
//     delete recordsWindow;
//     delete currentGame;
// }

// void MainWindow::setupUI() {
//     centralWidget = new QWidget(this);
//     setCentralWidget(centralWidget);

//     layout->addWidget(menu);
//     layout->addWidget(nameInputWindow);
//     layout->addWidget(matrixSizeSelectionWindow);
//     layout->addWidget(gameWindow);
//     layout->addWidget(recordsWindow);

//     centralWidget->setLayout(layout);

//     // Connect signals to slots
//     connect(menu, &Menu::startGameFlowInitiated, this, &MainWindow::onStartGameFlow);
//     connect(menu, &Menu::showRecordsClicked, this, &MainWindow::showRecords);
//     connect(menu, &Menu::exitGameClicked, this, &QWidget::close);

//     connect(nameInputWindow, &NameInputWindow::playerNameEntered, this, &MainWindow::onPlayerNameEntered);
//     connect(matrixSizeSelectionWindow, &MatrixSizeSelectionWindow::sizeSelected, this, &MainWindow::onMatrixSizeSelected);

//     connect(gameWindow, &GameWindow::gameFinished, this, &MainWindow::onBackToMenu);
//     connect(recordsWindow, &RecordsWindow::backToMenu, this, &MainWindow::onBackToMenu);

//     layout->setCurrentWidget(menu);
// }

// void MainWindow::onStartGameFlow() {
//     layout->setCurrentWidget(nameInputWindow);
// }

// void MainWindow::onPlayerNameEntered(const QString& playerName) {
//     this->playerName = playerName;
//     layout->setCurrentWidget(matrixSizeSelectionWindow);
// }

// void MainWindow::onMatrixSizeSelected(int size) {
//     layout->setCurrentWidget(gameWindow);
//     if (currentGame) delete currentGame;  // Clean up previous game if it exists
//     currentGame = new Game(size);
//     gameWindow->startGame(size, playerName);
// }

// void MainWindow::onBackToMenu() {
//     layout->setCurrentWidget(menu);
// }

// void MainWindow::showRecords() {
//     layout->setCurrentWidget(recordsWindow);
// }



MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent),
    menu(new Menu(this)),
    nameInputWindow(new NameInputWindow(this)),
    matrixSizeSelectionWindow(new MatrixSizeSelectionWindow(this)),
    gameWindow(new GameWindow(this)),
    recordsWindow(new RecordsWindow(this)),
    layout(new QStackedLayout),
    currentGame(nullptr) {

    setupUI();
}

MainWindow::~MainWindow() {
    delete layout;
    delete menu;
    delete nameInputWindow;
    delete matrixSizeSelectionWindow;
    delete gameWindow;
    delete recordsWindow;
    delete currentGame;
}

void MainWindow::setupUI() {
    centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);

    layout->addWidget(menu);
    layout->addWidget(nameInputWindow);
    layout->addWidget(matrixSizeSelectionWindow);
    layout->addWidget(gameWindow);
    layout->addWidget(recordsWindow);

    centralWidget->setLayout(layout);

    // Connect signals to slots
    connect(menu, &Menu::startGameClicked, this, &MainWindow::startNewGame);

    connect(menu, &Menu::showRecordsClicked, this, &MainWindow::showRecords);
    connect(menu, &Menu::exitGameClicked, this, &QWidget::close);

    connect(nameInputWindow, &NameInputWindow::playerNameEntered, this, &MainWindow::onPlayerNameEntered);
    connect(matrixSizeSelectionWindow, &MatrixSizeSelectionWindow::sizeSelected, this, &MainWindow::onMatrixSizeSelected);

    connect(gameWindow, &GameWindow::gameFinished, this, &MainWindow::onBackToMenu);
    connect(recordsWindow, &RecordsWindow::backToMenu, this, &MainWindow::onBackToMenu);

    layout->setCurrentWidget(menu);
}

void MainWindow::onBackToMenu() {
    layout->setCurrentWidget(menu);
}
void MainWindow::onPlayerNameEntered(const QString& playerName) {
    this->playerName = playerName;
    // layout->setCurrentWidget(matrixSizeSelectionWindow);
    // int size = 3;
    // layout->setCurrentWidget(matrixSizeSelectionWindow);
    int size =  5;
    onStartGame(size, playerName);

}

void MainWindow::onMatrixSizeSelected(int size) {
    qDebug("size");
    // size = 3;
    // currentGame = new Game(size);
    // gameWindow->startGame(size, playerName);
    // layout->setCurrentWidget(gameWindow);
    onStartGame(size, playerName);
}

void MainWindow::onStartGame(int size, const QString& playerName) {
    // layout->setCurrentWidget(nameInputWindow);
    currentGame = new Game(size);
    gameWindow->startGame(size, playerName);
    layout->setCurrentWidget(gameWindow);
}


void MainWindow::showRecords() {
    recordsWindow->updateRecords(playerName, currentScore);
    layout->setCurrentWidget(recordsWindow);
}

void MainWindow::startNewGame() {
    layout->setCurrentWidget(nameInputWindow);
}




// #include "MainWindow.h"
// #include "ScorePanel.h"
// #include "GameWidget.h"
// #include <QPainter>
// #include "RecordsWidget.h"  // Include the RecordsWidget header
// #include <QStackedLayout>

// MainWindow::MainWindow(QWidget* parent)
//     : QMainWindow(parent) {
//     setupUI();
// }

// MainWindow::~MainWindow() {}

// void MainWindow::setupUI() {
//     // Initialize widgets
//     menuWidget = new Menu(this);
//     scorePanel = new ScorePanel(this);
//     gameWidget = new GameWidget(this);
//     recordsWidget = new RecordsWidget(this);  // Initialize the records widget

//     // Setup layout
//     centralWidget = new QWidget(this);
//     layout = new QStackedLayout(centralWidget);

//     layout->addWidget(menuWidget);   // First screen is the menu
//     layout->addWidget(scorePanel);   // Score panel (for later)
//     layout->addWidget(gameWidget);   // Game widget (after the game starts)
//     layout->addWidget(recordsWidget);  // Add the records widget

//     setCentralWidget(centralWidget);

//     // Connect signals
//     connect(menuWidget, &Menu::startGameRequested, this, &MainWindow::onStartGame);
//     connect(menuWidget, &Menu::showRecordsRequested, this, &MainWindow::showRecords);
// }

// void MainWindow::onStartGame(int size, const QString& playerName) {
//     // Hide menu, show score panel and game widget
//     layout->setCurrentWidget(scorePanel);
//     layout->addWidget(gameWidget);  // Adding the game widget after the score panel

//     // Start the game with the selected size and player name
//     gameWidget->startGame(size, playerName);
//     layout->setCurrentWidget(gameWidget);
// }

// void MainWindow::showRecords() {
//     // Switch to the records widget to display game records
//     layout->setCurrentWidget(recordsWidget);
// }


// MainWindow::MainWindow(QWidget *parent) : QWidget(parent)
// {
//     // Set up the main window layout
//     QVBoxLayout *layout = new QVBoxLayout(this);

//     // Initialize and set the Menu widget
//     menu = new Menu(this);
//     layout->addWidget(menu);

//     setLayout(layout);
//     setWindowTitle("15 Puzzle Game");

//     resize(400, 300);  // Adjust the window size
// }

// MainWindow::~MainWindow()
// {
//     delete menu;
// }

// Visualization::Visualization(Game* game, QMainWindow* parent)
//     : QMainWindow(parent), game(game), tileSize(100), margin(10) {
//     setFixedSize(game->getBoardSize() * tileSize + margin * 2, game->getBoardSize() * tileSize + margin * 2);
// }

// Visualization::~Visualization() {}

// void Visualization::updateBoardDisplay() {
//     update();  // Request a repaint of the widget to update the display
// }



// void Visualization::mousePressEvent(QMouseEvent* event) {
//     QPointF position = event->position();  // Get the position of the mouse click
//     int x = position.x() - margin;  // Subtract margin
//     int y = position.y() - margin;

//     if (x >= 0 && y >= 0) {
//         handleClick(x, y);  // Determine which tile was clicked and emit the signal
//     }
// }

// void Visualization::keyPressEvent(QKeyEvent* event) {
//     emit keyPressed(event->key());  // Emit the key press signal
// }

// void Visualization::paintEvent(QPaintEvent* ) {
//     QPainter painter(this);
//     painter.setRenderHint(QPainter::Antialiasing);

//     drawBoard(painter);  // Draw the game board
//     drawGrid(painter);   // Draw the grid lines
// }

// void Visualization::drawBoard(QPainter& painter) {
//     if (game)
//     {
//         int boardSize = game->getBoardSize();

//         for (int i = 0; i < boardSize; i++) {
//             for (int j = 0; j < boardSize; j++) {
//                 int tileValue = game->getBoard()->getTile(i, j, boardSize);  // Get the tile value from the game logic
//                 drawTile(i, j, tileValue, painter);  // Draw the tile using the painter
//             }
//         }
//     }
// }


// void Visualization::drawTile(int row, int col, int tileValue, QPainter& painter) {
//     int x = margin + col * tileSize;
//     int y = margin + row * tileSize;

//     QPen pen(Qt::black);
//     QBrush brush(Qt::lightGray);

//     painter.setPen(pen);
//     painter.setBrush(brush);

//     painter.drawRect(x, y, tileSize, tileSize);  // Draw tile background
//     if (tileValue != 0) {  // 0 is the empty space
//         QFont font = painter.font();
//         font.setPointSize(24);
//         painter.setFont(font);
//         painter.drawText(x, y, tileSize, tileSize, Qt::AlignCenter, QString::number(tileValue));  // Draw the tile number
//     }
// }

// void Visualization::drawGrid(QPainter& painter) {
//     QPen pen(Qt::black);
//     painter.setPen(pen);

//     int boardSize = game->getBoardSize();
//     for (int i = 0; i <= boardSize; i++) {
//         painter.drawLine(margin, margin + i * tileSize, margin + boardSize * tileSize, margin + i * tileSize);  // Horizontal lines
//         painter.drawLine(margin + i * tileSize, margin, margin + i * tileSize, margin + boardSize * tileSize);  // Vertical lines
//     }
// }


// void Visualization::handleClick(int x, int y) {
//     int row = (y - margin) / tileSize;
//     int col = (x - margin) / tileSize;

//     if (row >= 0 && col >= 0 && row < game->getBoardSize() && col < game->getBoardSize()) {
//         emit tileClicked(row, col);  // Emit the signal for the clicked tile
//     }

// }


Visualization::Visualization(Game* game, QMainWindow* parent)
    : QMainWindow(parent), game(game), tileSize(100), margin(10) {
    QWidget* centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);

    gridLayout = new QGridLayout(centralWidget);
    gridLayout->setSpacing(2);  // Spacing between tiles
    gridLayout->setContentsMargins(margin, margin, margin, margin);

    initializeBoard();
    updateBoardDisplay();
}

Visualization::~Visualization() {
    clearBoard();
}

void Visualization::initializeBoard() {
    clearBoard();

    if (!game) return;

    int boardSize = game->getBoardSize();
    // int buttonSize = 100;
    for (int row = 0; row < boardSize; ++row) {
        for (int col = 0; col < boardSize; ++col) {
            QPushButton* button = new QPushButton(this);
            setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
            button->setStyleSheet("font-size: 24px; color: black; background-color: lightgray;");
            connect(button, &QPushButton::clicked, [this, row, col]() {
                handleClick(row, col);
            });

            buttons.push_back(button);
            gridLayout->addWidget(button, row, col);
        }
    }
}

void Visualization::clearBoard() {
    for (QPushButton* button : buttons) {
        gridLayout->removeWidget(button);
        delete button;
    }
    buttons.clear();
}

void Visualization::updateBoardDisplay() {
    if (!game) return;

    int boardSize = game->getBoardSize();
    for (int row = 0; row < boardSize; ++row) {
        for (int col = 0; col < boardSize; ++col) {
            int tileValue = game->getBoard()->getTile(row, col, boardSize);
            QPushButton* button = qobject_cast<QPushButton*>(gridLayout->itemAtPosition(row, col)->widget());
            if (button) {
                if (tileValue == 0) {
                    button->setText("");  // Empty space
                    button->setStyleSheet("font-size: 24px, background-color: white;");
                } else {
                    button->setText(QString::number(tileValue));
                    button->setStyleSheet("font-size: 24px; color: black; background-color: lightgray;");
                }
            }
        }
    }
}



void Visualization::keyPressEvent(QKeyEvent* event) {
    emit keyPressed(event->key());
}

void Visualization::handleClick(int row, int col) {
    emit tileClicked(row, col);
}
