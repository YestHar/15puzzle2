#include "NameInputWindow.h"
#include <QVBoxLayout>

NameInputWindow::NameInputWindow(QWidget* parent)
    : QWidget(parent) {

    setupUI();
}

void NameInputWindow::setupUI() {
    nameInput = new QLineEdit(this);
    enterButton = new QPushButton("Enter", this);

    layout = new QVBoxLayout(this);
    layout->addWidget(nameInput);
    layout->addWidget(enterButton);

    connect(enterButton, &QPushButton::clicked, this, &NameInputWindow::onEnterButtonClicked);
}

void NameInputWindow::onEnterButtonClicked() {
    emit playerNameEntered(nameInput->text());
}
