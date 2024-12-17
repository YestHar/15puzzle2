#include "Board.h"
#include <QTime>
#include <QRandomGenerator>
#include <algorithm>
#include <random>
#include <cstdlib>
#include <iostream>
Board::Board(int size) : SIZE(size) {//change to dynamic
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

    // Use std::shuffle with QRandomGenerator to shuffle the numbers
    std::random_device rd;  // Obtain a random number from the system
    std::mt19937 gen(QRandomGenerator::global()->generate());  // Use Qt's global random generator for std::mt19937
    do {
        std::shuffle(numbers, numbers + SIZE * SIZE, gen);  // Shuffle using std::shuffle and the Qt random generator
    } while (!isSolvable(numbers));  // Check if the board is solvable

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
    for (int i = 0; i < SIZE * SIZE - 1; i++) {
        for (int j = i + 1; j < SIZE * SIZE; j++) {
            if (numbers[i] > numbers[j] && numbers[i] != 0 && numbers[j] != 0) {
                inversions++;
            }
        }
    }
    return inversions % 2 == 0;
}

QPair<int, int> Board::findZero() const {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (grid[i][j] == 0) {
                return QPair<int, int>(i, j);
            }
        }
    }
    return QPair<int, int>(-1, -1);  // Return invalid index if not found
}

int Board::getSize() const {
    return SIZE;
}

void Board::setSize(int size) {
    // Deallocate existing grid memory
    // Set new size and allocate new grid
    /*SIZE = size;*/
    /*grid = new int*[SIZE];*/
    /*for (int i = 0; i < SIZE; i++) {*/
    /*    grid[i] = new int[SIZE];*/
    /*}*/

    initialize();  // Reinitialize the grid with shuffled numbers
}
