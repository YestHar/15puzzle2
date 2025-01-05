#include "GameWindow.h"
#include <QMessageBox>
#include <QMouseEvent>
#include <QDebug>

GameWindow::GameWindow(QWidget* parent)
    : QMainWindow(parent), game(nullptr), gridSize(3), stepsCount(0) {

    setupUI();
}

void GameWindow::setupUI() {
    // Set the window title
    setWindowTitle("15 Puzzle Game");

    // Create top section widgets
    scoreLabel = new QLabel("Score: 0", this);
    restartButton = new QPushButton("Restart", this);
    menuButton = new QPushButton("Menu", this);

    // Connect buttons to their respective slots
    connect(restartButton, &QPushButton::clicked, this, &GameWindow::onRestartClicked);
    connect(menuButton, &QPushButton::clicked, this, &GameWindow::onMenuClicked);
    connect(this, &GameWindow::tileClicked, this, &GameWindow::handleTileClicked);
    connect(this, &GameWindow::keyPressed, game, &Game::onKeyPressedSlot);
    connect(this, &GameWindow::sendUpdateScore, this, &GameWindow::incrementScore);

    // Create the Visualization widget (Game grid)
    visualizationWidget = new Visualization(game, this);

    // Set up the main layout
    QGridLayout* mainLayout = new QGridLayout();

    // Add the top section (score label and buttons)
    mainLayout->addWidget(scoreLabel, 0, 0, 1, 1);     // Score label in the top-left
    mainLayout->addWidget(restartButton, 0, 1, 1, 1);  // Restart button next to score
    mainLayout->addWidget(menuButton, 0, 2, 1, 1);     // Menu button next to Restart

    // Add the Visualization widget (game grid)
    mainLayout->addWidget(visualizationWidget, 2, 0, 1, 4); // Spans three columns

    // Set the layout for the central widget
    QWidget* mainWidget = new QWidget(this);
    mainWidget->setLayout(mainLayout);

    // Set the central widget for the main window
    setCentralWidget(mainWidget);

    // Update the score display initially
    updateScore();
}


// void GameWindow::setupUI() {
//     // Central widget setup
//     setWindowTitle("15 Puzzle Game");

//     scoreLabel = new QLabel("Score: 0");

//     // Create restart and menu buttons
//     restartButton = new QPushButton("Restart");
//     menuButton = new QPushButton("Menu");

//     // Connect buttons to their respective slots
//     connect(restartButton, &QPushButton::clicked, this, &GameWindow::onRestartClicked);
//     connect(menuButton, &QPushButton::clicked, this, &GameWindow::onMenuClicked);
//     connect(this, &GameWindow::tileClicked, this, &GameWindow::handleTileClicked);
//     connect(this, &GameWindow::keyPressed, game, &Game::onKeyPressedSlot);
//     connect(this, &GameWindow::sendUpdateScore, this, &GameWindow::incrementScore);

//     // Initialize the Visualization widget (GameWidget)
//     visualizationWidget = new Visualization(game, this);

//     // Set up the layout
//     QHBoxLayout* topLayout = new QHBoxLayout();
//     topLayout->addWidget(scoreLabel);
//     topLayout->addWidget(restartButton);
//     topLayout->addWidget(menuButton);

//     QVBoxLayout* mainLayout = new QVBoxLayout();
//     mainLayout->addLayout(topLayout);
//     mainLayout->addWidget(visualizationWidget);  // Add the visualization widget

//     // Set the layout for the main widget
//     QWidget* mainWidget = new QWidget(this);
//     mainWidget->setLayout(mainLayout);

//     // Set the central widget for the main window
//     setCentralWidget(mainWidget);

//     // Update the score display initially
//     updateScore();



// }


GameWindow::~GameWindow() {
    delete game;
}



// void GameWindow::setupUI() {
//     // Central widget setup
//     setWindowTitle("15 Puzzle Game");
//     centralWidget = new QWidget(this);
//     QVBoxLayout* mainLayout = new QVBoxLayout(this);

//     // Score label and buttons
//     scoreLabel = new QLabel("Steps: 0", this);
//     restartButton = new QPushButton("Restart", this);
//     menuButton = new QPushButton("Menu", this);

//     // Top bar layout: Score, Restart, Menu
//     QHBoxLayout* topBarLayout = new QHBoxLayout();
//     topBarLayout->addWidget(menuButton);
//     topBarLayout->addWidget(scoreLabel, 1);
//     topBarLayout->addWidget(restartButton);


//     // Main layout: Top bar and game board
//     mainLayout->addLayout(topBarLayout);
//     centralWidget->setLayout(mainLayout);
//     setLayout(mainLayout);

//     // Connect signals
//     connect(restartButton, &QPushButton::clicked, this, &GameWindow::onRestartClicked);
//     connect(menuButton, &QPushButton::clicked, this, &GameWindow::onMenuClicked);
//     connect(this, &GameWindow::tileClicked, this, &GameWindow::handleTileClicked);
//     connect(this, &GameWindow::keyPressed, game, &Game::onKeyPressedSlot);
//     connect(this, &GameWindow::sendUpdateScore, this, &GameWindow::incrementScore);
// }

void GameWindow::startGame(int size, const QString& playerName) {
    this->gridSize = size;
    this->playerName = playerName;
    stepsCount = 0;
    updateScore();

    game = new Game(size);

    game->startGame();
    updateBoardDisplay();
}

void GameWindow::restartGame() {
    if (game) {
        game->restartGame();
        updateBoardDisplay();
    }
}

void GameWindow::updateBoardDisplay() {
    update();
}

void GameWindow::mousePressEvent(QMouseEvent* event) {
    int row = event->y() / 100;
    int col = event->x() / 100;

    emit tileClicked(row, col);
}

void GameWindow::keyPressEvent(QKeyEvent* event) {
    emit keyPressed(event->key());
}

void GameWindow::onRestartClicked() {
    if (game) {
        game->restartGame();  // Restart game logic
        stepsCount = 0;       // Reset the score
        updateBoardDisplay(); // Update the board display
        emit sendUpdateScore(); // Emit to trigger score update
    }
}

void GameWindow::onMenuClicked() {
    emit menuRequested();
}

void GameWindow::handleTileClicked(int row, int col) {
    if (game) {
        game->onTileClicked(row, col);
        qDebug("SEND SCOREE");

        emit sendUpdateScore();
    }
}

void GameWindow::incrementScore() {
    stepsCount++;
    updateScore();
}

void GameWindow::updateScore() {
    scoreLabel->setText(QString("Steps: %1").arg(stepsCount));
}

