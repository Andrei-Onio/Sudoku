#include <stdio.h>
#include "board.h"

int board[SIZE][SIZE];

void printBoard(int original[SIZE][SIZE]) {
    int i, j;

    printf("\nSudoku Board:\n");

    for(i = 0; i < SIZE; i++) {
        for(j = 0; j < SIZE; j++) {

            if(original[i][j] != 0) {
                // original fixed cell → show in brackets
                printf("[%d] ", board[i][j]);
            }
            else {
                // user cell or empty
                if(board[i][j] == 0)
                    printf(".   ");
                else
                    printf(" %d  ", board[i][j]);
            }

            if((j+1)%3==0 && j!=8)
                printf("| ");
        }

        printf("\n");

        if((i+1)%3==0 && i!=8)
            printf("--------------------------------\n");
    }
}