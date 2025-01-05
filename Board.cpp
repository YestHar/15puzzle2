#include "Board.h"
#include <QTime>
#include <QRandomGenerator>
#include <algorithm>
#include <random>
#include <cstdlib>
#include <iostream>
Board::Board(int size) : SIZE(size) {
    for (int i = 0; i < SIZE; i++) {
        std::vector<int> a;
        grid.push_back(a);
        for (int j = 0; j < SIZE; j++)
        {
            grid[i].push_back(0);
        }
    }
    initialize();
}

Board::~Board() {
}

void Board::initialize() {
    int numbers[SIZE * SIZE];
    for (int i = 0; i < SIZE * SIZE; i++) {
        numbers[i] = i;
    }

    std::random_device rd;
    std::mt19937 gen(QRandomGenerator::global()->generate());
    do {
        std::shuffle(numbers, numbers + SIZE * SIZE, gen);
    } while (!isSolvable(numbers));

    int index = 0;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            grid[i][j] = numbers[index++];
        }
    }
}

bool Board::isBoardSolved() const {
    int counter = 1;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (grid[i][j] != counter && !(i == SIZE - 1 && j == SIZE - 1)) {
                return false;
            }
            counter++;
        }
    }
    return true;
}

int Board::getTile(int row, int col, int size) const {
    if (row >= 0 && row < size && col >= 0 && col < size) {
        return grid[row][col];
    }
    return -1;  // Invalid index
}

bool Board::swap(int row1, int col1, int row2, int col2) {
    if (row1 >= 0 && row1 < SIZE && col1 >= 0 && col1 < SIZE &&
        row2 >= 0 && row2 < SIZE && col2 >= 0 && col2 < SIZE) {
        std::swap(grid[row1][col1], grid[row2][col2]);
        return true;
    }
    return false;
}

bool Board::isSolvable(int numbers[]) const {
    int inversions = 0;
    int emptyRow = 0; // Row of the empty tile (0-based)

    // Count inversions
    for (int i = 0; i < SIZE * SIZE - 1; i++) {
        for (int j = i + 1; j < SIZE * SIZE; j++) {
            if (numbers[i] > numbers[j] && numbers[i] != 0 && numbers[j] != 0) {
                inversions++;
            }
        }
    }

    // Find the row of the empty tile (0-based indexing)
    for (int i = 0; i < SIZE * SIZE; i++) {
        if (numbers[i] == 0) {
            emptyRow = i / SIZE; // Determine the row of the empty space
            break;
        }
    }

    if (SIZE % 2 != 0) {
        // Odd grid size: solvable if inversions are even
        return inversions % 2 == 0;
    } else {
        // Even grid size: additional check with the empty tile row
        return (inversions % 2 == 0) == (emptyRow % 2 != 0);
    }
}

QPair<int, int> Board::findZero() const {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (grid[i][j] == 0) {
                return QPair<int, int>(i, j);
            }
        }
    }
    return QPair<int, int>(-1, -1);
}

int Board::getSize() const {
    return SIZE;
}

void Board::setSize(int size) {
    initialize();
}
