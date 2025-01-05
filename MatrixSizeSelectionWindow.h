#ifndef MATRIXSIZESELECTIONWINDOW_H
#define MATRIXSIZESELECTIONWINDOW_H

#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>

class MatrixSizeSelectionWindow : public QWidget {
    Q_OBJECT

public:
    explicit MatrixSizeSelectionWindow(QWidget* parent = nullptr);
    void selectSize(int size, const QString& name);


signals:
    void matrixSizeSelected(int size);
    void sizeSelected(int size, const QString& name);

private:
    QPushButton* size3x3Button;
    QPushButton* size4x4Button;
    QPushButton* size5x5Button;
    QString playerName;
    QVBoxLayout* layout;

    void setupUI();


private slots:
    void onMatrixSizeButtonClicked();
};

#endif // MATRIXSIZESELECTIONWINDOW_H
