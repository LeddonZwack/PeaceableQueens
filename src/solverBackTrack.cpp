//
// Created by Leddon Zwack on 9/25/23.
//

#include "../include/solverBackTrack.h"

solverBackTrack::solverBackTrack() : bSize(1), nQueens(0), nUnattacked(1), maxSF(0) {
    board.resize(1);
    board[0].resize(1);
}

solverBackTrack::solverBackTrack(int n) : bSize(n), nQueens(0), nUnattacked(n*n), maxSF(0) {
    board.resize(n);
    for (int i = 0; i < n; ++i) {
        board[i].resize(n);
    }
}

void solverBackTrack::printManager(const std::string& type) {
    if (type == "ALL") {
        while (!solutions.empty()) {
            if (solutions.top().max == maxSF) {
                printBoard(solutions.top().pBoard);
            }
            solutions.pop();
        }
    }
    else {
        printBoard(solutions.top().pBoard);
    }
    std::cout << "Maximum number of queens on board: " << maxSF << std::endl;
}

void solverBackTrack::printBoard(std::vector<std::vector<Square>> printBoard) const {
    for (int i = 0; i < bSize; i++) {
        for (int j = 0; j < bSize; j++) {
            if (printBoard[i][j].getQueen())
                std::cout << "W ";
            else if (!printBoard[i][j].getAttack())
                std::cout << "B ";
            else
                std::cout << ". ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

bool solverBackTrack::updateBoard(int row, int col) {
    // Temp Variable to store number of unattacked squares
    int count(bSize*bSize);

    // Set attacked squares in the same row and column
    for (int i = 0; i < bSize; ++i) {
        board[row][i].setAttack(true);
        board[i][col].setAttack(true);
    }

    // Set attacked squares on diagonals:
    // U/L
    for (int i = row, j = col; i >= 0 && j >= 0; --i, --j) {
        board[i][j].setAttack(true);
    }
    // U/R
    for (int i = row, j = col; i >= 0 && j < bSize; --i, ++j) {
        board[i][j].setAttack(true);
    }
    // D/L
    for (int i = row, j = col; i < bSize && j >= 0; ++i, --j) {
        board[i][j].setAttack(true);
    }
    // D/R
    for (int i = row, j = col; i < bSize && j < bSize; ++i, ++j) {
        board[i][j].setAttack(true);
    }

    // Count number of unattacked squares
    for (int i = 0; i < bSize; ++i) {
        for (int j = 0; j < bSize; ++j) {
            if (board[i][j].getAttack()) {
                --count;
            }
        }
    }

    // Update number of unattacked squares
    nUnattacked = count;

    // See if there are a valid number of unattacked squares remaining
    return nUnattacked >= nQueens;
}

bool solverBackTrack::isSafe(int row, int col) {
    // First condition
    if (board[row][col].getQueen()) {
        return false;
    }

    // Save a temp copy of our board
    std::vector<std::vector<Square>> tBoard(board);
    // Save pre value of number of unattacked squares
    int tUA = nUnattacked;

    // Add queen to the board
    board[row][col].setQueen(true);
    ++nQueens;

    // Second condition
    if (!updateBoard(row, col)) {
        // Doesn't meet condition - return class to previous state
        revertBoard(tBoard, tUA);
        return false;
    }
    return true;
}

void solverBackTrack::revertBoard(const std::vector<std::vector<Square>> &revertBoard, int revertNUnattacked) {
    board = revertBoard;
    nUnattacked = revertNUnattacked;
    --nQueens;
}

void solverBackTrack::saveBoard(const std::vector<std::vector<Square>>& saveBoard, int maxQueens) {
    maxSF = maxQueens;
    solutions.emplace(maxQueens, saveBoard);
}

bool solverBackTrack::checkEquals() {
    if (solutions.empty()) {
        return false;
    }
    else {
        return board == solutions.top().pBoard;
    }
}

void solverBackTrack::solveBoard(int count) {
    // Save a pre copy of our board
    std::vector<std::vector<Square>> tBoard;
    // Save pre value of number of unattacked squares
    int tUA;

    for (int i = count; i < bSize*bSize; ++i) {
        // Save board state
        tBoard = board; tUA = nUnattacked;
        // Check if it's safe to place Queen at spot on board
        if (isSafe(count/bSize, count%bSize)) {
            // Recursively find solution with Queen at spot
            solveBoard(i);
            // Backtrack
            revertBoard(tBoard, tUA);
        }
        else {
            // Save valid solution
            if (nQueens >= maxSF && !checkEquals()) {
                saveBoard(board, nQueens);
            }
        }
    }
}
