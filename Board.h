#ifndef BOARD_H
#define BOARD_H

#include <QPair>
#include <vector>

class Board {
public:
    Board(int size = 3);  // Constructor with default size 3x3
    ~Board();  // Destructor to free memory
    void initialize();     // Initialize the board with random tiles
    bool isBoardSolved() const;  // Check if the board is in the solved state
    int getTile(int row, int col, int d) const;  // Get tile value at a specific position//delete it
    bool swap(int row1, int col1, int row2, int col2);  // Swap two tiles
    bool isSolvable(int numbers[]) const;  // Check if the puzzle configuration is solvable
    QPair<int, int> findZero() const;  // Find the position of the empty tile (0)
    int getSize() const;  // Get the size of the board

    // Additional helper methods
    void setSize(int size);  // Set the size of the board dynamically

private:
    int SIZE;  // Size of the board
    std::vector<std::vector<int>> grid;  // 2D array to store the board state
};

#endif // BOARD_H
