#include "Menu.h"
#include <QMessageBox>
#include <QFileDialog>
#include <QPushButton>
#include <QVBoxLayout>
#include <QLabel>
#include <QTextStream>
#include <QFile>

Menu::Menu(QWidget* parent)
    : QWidget(parent) {
    setupMenu();
}

Menu::~Menu() {}

void Menu::setupMenu() {
    // Create the buttons for the main menu
    startButton = new QPushButton("Start", this);
    recordsButton = new QPushButton("Records", this);

    // Connect buttons to slots
    connect(startButton, &QPushButton::clicked, this, &Menu::onStartButtonClicked);
    connect(recordsButton, &QPushButton::clicked, this, &Menu::onRecordsButtonClicked);

    // Set up the layout for the menu
    QVBoxLayout* layout = new QVBoxLayout(this);
    layout->addWidget(startButton);
    layout->addWidget(recordsButton);
    setLayout(layout);
}

void Menu::setupNameEntryWindow() {
    // Create a new window for name entry
    nameEntryWindow = new QWidget();
    QVBoxLayout* layout = new QVBoxLayout(nameEntryWindow);

    QLabel* label = new QLabel("Enter your name:", nameEntryWindow);
    layout->addWidget(label);

    nameInput = new QLineEdit(nameEntryWindow);
    layout->addWidget(nameInput);

    QPushButton* enterButton = new QPushButton("Enter", nameEntryWindow);
    layout->addWidget(enterButton);

    // Connect the Enter button to the slot
    connect(enterButton, &QPushButton::clicked, this, &Menu::onNameEntered);

    nameEntryWindow->setLayout(layout);
    nameEntryWindow->show();
}

void Menu::setupSizeSelectionWindow() {
    // Create a new window for matrix size selection
    sizeSelectionWindow = new QWidget();
    QVBoxLayout* layout = new QVBoxLayout(sizeSelectionWindow);

    QLabel* label = new QLabel("Select matrix size:", sizeSelectionWindow);
    layout->addWidget(label);

    QPushButton* size3x3 = new QPushButton("3x3", sizeSelectionWindow);
    QPushButton* size4x4 = new QPushButton("4x4", sizeSelectionWindow);
    QPushButton* size5x5 = new QPushButton("5x5", sizeSelectionWindow);

    layout->addWidget(size3x3);
    layout->addWidget(size4x4);
    layout->addWidget(size5x5);

    // Connect buttons to the slot for matrix size selection
    connect(size3x3, &QPushButton::clicked, [this](){ onMatrixSizeSelected(3); });
    connect(size4x4, &QPushButton::clicked, [this](){ onMatrixSizeSelected(4); });
    connect(size5x5, &QPushButton::clicked, [this](){ onMatrixSizeSelected(5); });

    sizeSelectionWindow->setLayout(layout);
    sizeSelectionWindow->show();
}

void Menu::openNameEntryWindow() {
    setupNameEntryWindow();
}

void Menu::openSizeSelectionWindow() {
    setupSizeSelectionWindow();
}

void Menu::saveNameToFile(const QString &name) {
    QFile file("records.txt");
    if (file.open(QIODevice::Append | QIODevice::Text)) {
        QTextStream out(&file);
        out << name << "\n";
        file.close();
    }
}

void Menu::startGame(int size) {
    Game* game = new Game(size); // Create a new game with the selected size
    game->startGame(); // Start the game (assumes Game has a start method)

    // You can now start the game, you can pass it to the visualization and logic
}

void Menu::onStartButtonClicked() {
    openNameEntryWindow();  // Open the name entry window when Start is clicked
}

void Menu::onRecordsButtonClicked() {
    // Handle records button click (You can show the records in a new window or load from the file)
    QFile file("records.txt");
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream in(&file);
        QString records = in.readAll();
        file.close();
        QMessageBox::information(this, "Records", records);
    }
}

void Menu::onNameEntered() {
    QString name = nameInput->text();
    if (!name.isEmpty()) {
        saveNameToFile(name);  // Save the entered name
        nameEntryWindow->close();  // Close the name entry window
        openSizeSelectionWindow(); // Open the size selection window
    } else {
        QMessageBox::warning(this, "Invalid Input", "Please enter a valid name.");
    }
}

void Menu::onMatrixSizeSelected(int size) {
    sizeSelectionWindow->close();  // Close the size selection window
    startGame(size);  // Start the game with the selected size
}
