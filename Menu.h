#ifndef MENU_H
#define MENU_H

#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>

class Menu : public QWidget {
    Q_OBJECT

public:
    explicit Menu(QWidget* parent = nullptr);
    ~Menu();

signals:
    void startGameClicked(int size, const QString& playerName);
    void showRecordsClicked();
    void exitGameClicked();
private slots:
    void onStartGame(int size, const QString& playerName);

private:
    QPushButton* startButton;
    QPushButton* recordsButton;
    QPushButton* exitButton;

    void setupUI();
};

#endif // MENU_H














// #ifndef MENU_H
// #define MENU_H

// #include <QWidget>
// #include <QPushButton>
// #include <QLineEdit>
// #include <QVBoxLayout>
// #include <QHBoxLayout>
// #include <QLabel>
// #include <QFile>
// #include <QTextStream>
// #include "Game.h"

// class Menu : public QWidget {
//     Q_OBJECT

// public:
//     explicit Menu(QWidget* parent = nullptr);
//     ~Menu();

// private:
//     QPushButton *startButton;
//     QPushButton *recordsButton;
//     QWidget *nameEntryWindow;
//     QWidget *sizeSelectionWindow;
//     QLineEdit *nameInput;

//     void setupMenu();
//     void setupNameEntryWindow();
//     void setupSizeSelectionWindow();
//     void openNameEntryWindow();
//     void openSizeSelectionWindow();
//     void saveNameToFile(const QString &name);
//     void startGame(int size);

// private slots:
//     void onStartButtonClicked();
//     void onRecordsButtonClicked();
//     void onNameEntered();
//     void onMatrixSizeSelected(int size);
// };

// #endif // MENU_H
