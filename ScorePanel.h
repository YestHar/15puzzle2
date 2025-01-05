#ifndef SCOREPANEL_H
#define SCOREPANEL_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include <QString>

class ScorePanel : public QWidget {
    Q_OBJECT

public:
    explicit ScorePanel(QWidget* parent = nullptr);
    void updateScore(int score);
    void setPlayerName(const QString &name);
    void resetScore();

private:
    QLabel* playerNameLabel;
    QLabel* scoreLabel;
    QPushButton* restartButton;

    int currentScore;

    void setupLayout();

signals:
    void restartGame();
};

#endif // SCOREPANEL_H
