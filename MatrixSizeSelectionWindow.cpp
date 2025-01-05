#include "MatrixSizeSelectionWindow.h"
#include <QVBoxLayout>

MatrixSizeSelectionWindow::MatrixSizeSelectionWindow(QWidget* parent)
    : QWidget(parent) {
    setupUI();
}

void MatrixSizeSelectionWindow::setupUI() {
    // Initialize the buttons
    size3x3Button = new QPushButton("3x3", this);
    size4x4Button = new QPushButton("4x4", this);
    size5x5Button = new QPushButton("5x5", this);

    // Set up the layout
    layout = new QVBoxLayout(this);
    layout->addWidget(size3x3Button);
    layout->addWidget(size4x4Button);
    layout->addWidget(size5x5Button);

    // Connect buttons to the respective handler function
    connect(size3x3Button, &QPushButton::clicked, this, &MatrixSizeSelectionWindow::onMatrixSizeButtonClicked);
    connect(size4x4Button, &QPushButton::clicked, this, &MatrixSizeSelectionWindow::onMatrixSizeButtonClicked);
    connect(size5x5Button, &QPushButton::clicked, this, &MatrixSizeSelectionWindow::onMatrixSizeButtonClicked);
}

void MatrixSizeSelectionWindow::onMatrixSizeButtonClicked() {
    QPushButton* button = qobject_cast<QPushButton*>(sender());
    if (button) {
        // Emit the selected size based on the button clicked
        if (button == size3x3Button) {
            emit matrixSizeSelected(3);
        } else if (button == size4x4Button) {
            emit matrixSizeSelected(4);
        } else if (button == size5x5Button) {
            emit matrixSizeSelected(5);
        }
    }
}

void MatrixSizeSelectionWindow::selectSize(int size, const QString& name) {
    playerName = name;
    emit sizeSelected(size, playerName);  // Emit the signal with the selected size and player name
}
