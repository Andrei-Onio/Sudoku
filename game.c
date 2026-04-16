#include "board.h"

int isValid(int row, int col, int num) {
    int i, j;

    for(i = 0; i < SIZE; i++)
        if(board[row][i] == num)
            return 0;

    for(i = 0; i < SIZE; i++)
        if(board[i][col] == num)
            return 0;

    int startRow = row - row % 3;
    int startCol = col - col % 3;

    for(i = 0; i < 3; i++)
        for(j = 0; j < 3; j++)
            if(board[startRow+i][startCol+j] == num)
                return 0;

    return 1;
}

int isComplete() {
    int i, j;

    for(i = 0; i < SIZE; i++)
        for(j = 0; j < SIZE; j++)
            if(board[i][j] == 0)
                return 0;

    return 1;
}