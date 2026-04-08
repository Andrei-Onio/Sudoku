#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "board.h"
#include "file.h"

#define PUZZLES 50

void loadRandomPuzzle() {

    FILE *fp = fopen("sudoku50.txt", "r");

    if (fp == NULL) {
        printf("Error opening file\n");
        exit(1);
    }

    srand(time(NULL));
    int target = rand() % PUZZLES;
    int row = 0, col = 0;
    int ch;
    int puzzlesFound = 0;
    int cellsFound = 0;

    while (puzzlesFound < target) {
        ch = fgetc(fp);
        if (ch == EOF) break;

        if (ch == '.' || (ch >= '1' && ch <= '9')) {
            cellsFound++;
            if (cellsFound == SIZE * SIZE) {
                puzzlesFound++;
                cellsFound = 0;
            }
        }
    }

    while (row < SIZE) {
        col = 0;
        while (col < SIZE) {
            ch = fgetc(fp);

            if (ch == '.') {
                board[row][col++] = 0;
            }
            else if (ch >= '1' && ch <= '9') {
                board[row][col++] = ch - '0';
            }
        }
        row++;
    }

    fclose(fp);

    printf("Loaded puzzle #%d\n", target);
}