// #include "RecordsWindow.h"
// #include <QVBoxLayout>
// #include <QPushButton>

// RecordsWindow::RecordsWindow(QWidget* parent)
//     : QMainWindow(parent) {
//     QWidget* centralWidget = new QWidget(this);
//     setCentralWidget(centralWidget);

//     recordsList = new QListWidget(this);

//     QVBoxLayout* layout = new QVBoxLayout();
//     layout->addWidget(recordsList);

//     centralWidget->setLayout(layout);

//     updateRecords();
// }

// RecordsWindow::~RecordsWindow() {}

// void RecordsWindow::updateRecords() {
//     recordsList->clear();
//     recordsList->addItem("Player 1 - 50 steps");
//     recordsList->addItem("Player 2 - 42 steps");

// }

// void RecordsWindow::setupUI() {
//     QPushButton* backButton = new QPushButton("Back to Menu", this);
//     connect(backButton, &QPushButton::clicked, this, &RecordsWindow::backToMenu);

//     QVBoxLayout* layout = new QVBoxLayout(this);
//     layout->addWidget(backButton);
//     setLayout(layout);
// }


#include "RecordsWindow.h"
#include <algorithm> // for std::sort
#include <QMessageBox>

RecordsWindow::RecordsWindow(QWidget* parent)
    : QWidget(parent),
    recordsList(new QListWidget(this)),
    titleLabel(new QLabel("Player Records", this)),
    backButton(new QPushButton("Back to Menu", this)),
    layout(new QVBoxLayout(this)) {

    loadRecords();
    refreshDisplay();

    layout->addWidget(titleLabel);
    layout->addWidget(recordsList);
    layout->addWidget(backButton);

    setLayout(layout);

    connect(backButton, &QPushButton::clicked, this, &RecordsWindow::onBackButtonClicked);
}

RecordsWindow::~RecordsWindow() {
    saveRecords();
}

void RecordsWindow::updateRecords(const QString& playerName, int score) {
    // Check if the player already has a record
    auto it = std::find_if(records.begin(), records.end(),
                           [&](const std::pair<QString, int>& record) {
                               return record.first == playerName;
                           });

    if (it != records.end()) {
        // Update the score if the new score is higher
        if (score > it->second) {
            it->second = score;
        }
    } else {
        // Add a new record
        records.emplace_back(playerName, score);
    }

    // Sort records by score in descending order
    std::sort(records.begin(), records.end(),
              [](const std::pair<QString, int>& a, const std::pair<QString, int>& b) {
                  return a.second > b.second;
              });

    // Limit the records list to the top 10 players
    if (records.size() > 10) {
        records.resize(10);
    }

    refreshDisplay();
}

void RecordsWindow::loadRecords() {
    records.clear();
    std::ifstream file(recordsFile.toStdString());

    if (file.is_open()) {
        QString name;
        int score;
        while (file >> name >> score) {
            records.emplace_back(name, score);
        }
        file.close();
    }
}

void RecordsWindow::saveRecords() {
    std::ofstream file(recordsFile.toStdString(), std::ios::trunc);

    if (file.is_open()) {
        for (const auto& record : records) {
            file << record.first.toStdString() << " " << record.second << "\n";
        }
        file.close();
    }
}

void RecordsWindow::refreshDisplay() {
    recordsList->clear();
    for (const auto& record : records) {
        recordsList->addItem(QString("%1 - %2 points").arg(record.first).arg(record.second));
    }
}

void RecordsWindow::onBackButtonClicked() {
    emit backToMenu();
}
