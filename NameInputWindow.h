#ifndef NAMEINPUTWINDOW_H
#define NAMEINPUTWINDOW_H

#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>

class NameInputWindow : public QWidget {
    Q_OBJECT

public:
    explicit NameInputWindow(QWidget* parent = nullptr);

signals:
    void playerNameEntered(const QString& playerName);

private:
    QLineEdit* nameInput;
    QPushButton* enterButton;
    QVBoxLayout* layout;

    void setupUI();
private slots:
    void onEnterButtonClicked();
};

#endif // NAMEINPUTWINDOW_H
