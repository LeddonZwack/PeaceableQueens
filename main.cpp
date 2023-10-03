#include <iostream>
#include <chrono>
using namespace std::chrono;

#include "include/solverBackTrack.h"

int main() {
    int n;
    std::cout << "\nPlease enter your desired board size: ";
    std::cin >> n;

    std::string solutions;
    std::cout << "Would you like to see one solution or all possible solutions? Please enter ONE or ALL: ";
    std::cin >> solutions;

    auto start = high_resolution_clock::now();

    if (n > 2) {
        solverBackTrack Puzzle(n);
        Puzzle.solveBoard(0);
        std::cout << "\nSolution found!" << std::endl;
        Puzzle.printManager(solutions);
    }
    else {
        std::cout << "There are no possible solutions." << std::endl;
    }

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    std::cout << "Runtime in seconds: " << float(duration.count())/1000000 << std::endl;

    return 0;
}