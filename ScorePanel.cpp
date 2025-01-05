#include "ScorePanel.h"
#include <QVBoxLayout>
#include <QPushButton>

ScorePanel::ScorePanel(QWidget* parent)
    : QWidget(parent), currentScore(0) {
    setupLayout();
}

void ScorePanel::setupLayout() {
    QVBoxLayout* layout = new QVBoxLayout(this);


    playerNameLabel = new QLabel("Player: ", this);
    layout->addWidget(playerNameLabel);

    scoreLabel = new QLabel("Score: 0", this);
    layout->addWidget(scoreLabel);

    restartButton = new QPushButton("Restart Game", this);
    connect(restartButton, &QPushButton::clicked, this, &ScorePanel::restartGame);
    layout->addWidget(restartButton);

    setLayout(layout);
}

void ScorePanel::updateScore(int score) {
    currentScore = score;
    scoreLabel->setText(QString("Score: %1").arg(currentScore));
}

void ScorePanel::setPlayerName(const QString &name) {
    playerNameLabel->setText("Player: " + name);
}

void ScorePanel::resetScore() {
    currentScore = 0;
    scoreLabel->setText("Score: 0");
}
