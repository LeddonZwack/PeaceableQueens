# PeaceableQueens
Hello, this is the Peaceable Queens problem!
Given an n X n chessboard what's the maximum number of m white queens and m black queens that can coexist without attacking each other?
Note that the number of queens of each color placed on the board should be equal and that queens of the same color can attack each other (just not the other color).

My implementation uses recursive backtracking and attempts to place more queens on the board wherever is possible to find the maximum number of each color that can coexist.
Instead of trying to place a white queen, then a black queen, then a white queen, etc., I continue to place queens (doesn't matter the color) on the board with the constraint that the number of queens currently on the board does not exceed the number of unattacked squares left on the board.
This way, there is always a greater than or equal amount of unattacked squares (attacked meaning being in the same row, column, or diagonal as a queen). These unattacked squares themsevles can be thought of places where queens of the opposite color to that currently on the board can be placed.

* When printing all possible solutions, it may be possible that a board has more black queens than white queens. This is simply due to the fact that I am assigning the unattacked squares as black queens when printing the solution boards.
* For these cases, you can imagen the set of solutions being if you removed each black queen such that the number of black queen is equal to the number of white queens.
