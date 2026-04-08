#include <stdio.h>
#include "board.h"
#include "file.h"
#include "game.h"

int main() {

    int row, col, num;

    printf("=== Sudoku Game (C) ===\n");

    loadRandomPuzzle();

    while(!isComplete()) {

        printBoard();

        printf("\nEnter row (1-9): ");
        scanf("%d", &row);

        printf("Enter column (1-9): ");
        scanf("%d", &col);

        printf("Enter number (1-9): ");
        scanf("%d", &num);

        row--;
        col--;

        if(board[row][col] != 0) {
            printf("Cell already filled!\n");
        }
        else if(isValid(row, col, num)) {
            board[row][col] = num;
        }
        else {
            printf("Invalid move!\n");
        }
    }

    printf("\nCongratulations! You solved the Sudoku!\n");
    printBoard();

    return 0;
}