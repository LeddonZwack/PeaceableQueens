//
// Created by Leddon Zwack on 9/25/23.
//

#ifndef TESTPQ_SOLVERBACKTRACK_H
#define TESTPQ_SOLVERBACKTRACK_H

#include <vector>
#include <iostream>
#include <stack>

#include "Square.h"

struct Solution {
    int max;
    std::vector<std::vector<Square>> pBoard;

    Solution(int n, const std::vector<std::vector<Square>> &p) {
        max = n;
        pBoard = p;
    }
};

class solverBackTrack {
public:
    // Default constructor
    solverBackTrack();
    // Alternate constructor
    explicit solverBackTrack(int n);
    // Destructor
    ~solverBackTrack() = default;

    // Recursive function to find our solutions
    void solveBoard(int squares);

    // Print one solution or all solutions
    void printManager(const std::string& type);
    // Function to print the chessboard
    void printBoard(std::vector<std::vector<Square>> printBoard) const;

private:
    // Is it safe to place a Queen at [row][column]
    bool isSafe(int row, int col);
    // Update the board given that we try to place a queen at the given [row][col]
    // Return if placement is valid
    bool updateBoard(int row, int col);
    // Revert board to previously saved state
    void revertBoard(const std::vector<std::vector<Square>> &revertBoard, int revertNUnattacked);
    // Save our new solution
    void saveBoard(const std::vector<std::vector<Square>>& saveBoard, int maxQueens);
    // Check if current board is equal to first board in solution stack
    bool checkEquals();

    std::vector<std::vector<Square>> board; // Current board

    std::stack<Solution> solutions; // Stack of solutions

    int bSize;  // Board size
    int nQueens;    // Number of queens on the board
    int nUnattacked;    // Number of squares unattacked on the board
    int maxSF;  // Current highest maximum number of queens on board
};


#endif //TESTPQ_SOLVERBACKTRACK_H
