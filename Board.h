#ifndef BOARD_H
#define BOARD_H

#include <QPair>
#include <vector>

class Board {
public:
    Board(int size = 3);
    ~Board();
    void initialize();
    bool isBoardSolved() const;
    int getTile(int row, int col, int d) const;
    bool swap(int row1, int col1, int row2, int col2);
    bool isSolvable(int numbers[]) const;
    QPair<int, int> findZero() const;
    int getSize() const;

    void setSize(int size);

private:
    int SIZE;
    std::vector<std::vector<int>> grid;
};

#endif // BOARD_H
