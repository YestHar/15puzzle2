// #ifndef RECORDSWINDOW_H
// #define RECORDSWINDOW_H

// #include <QMainWindow>
// #include <QListWidget>
// #include <QVBoxLayout>

// class RecordsWindow : public QMainWindow {
//     Q_OBJECT

// public:
//     explicit RecordsWindow(QWidget* parent = nullptr);
//     ~RecordsWindow();
// signals:
//     void backToMenu();
// private:
//     QListWidget* recordsList;
//     void setupUI();

// private slots:
//     void updateRecords();
// };
// #endif // RECORDSWINDOW_H


#ifndef RECORDSWINDOW_HPP
#define RECORDSWINDOW_HPP

#include <QWidget>
#include <QListWidget>
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QString>
#include <vector>
#include <utility> // for std::pair
#include <fstream>

class RecordsWindow : public QWidget {
    Q_OBJECT

public:
    explicit RecordsWindow(QWidget* parent = nullptr);
    ~RecordsWindow();

    void updateRecords(const QString& playerName, int score);

private:
    QListWidget* recordsList;
    QLabel* titleLabel;
    QPushButton* backButton;
    QVBoxLayout* layout;

    std::vector<std::pair<QString, int>> records; // Holds player names and scores
    const QString recordsFile = "records.txt";

    void loadRecords();
    void saveRecords();
    void refreshDisplay();

signals:
    void backToMenu();

private slots:
    void onBackButtonClicked();
};

#endif // RECORDSWINDOW_HPP
