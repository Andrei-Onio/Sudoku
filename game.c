#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 9
#define PUZZLES 50

int board[SIZE][SIZE];

void loadRandomPuzzle() {
    FILE *fp = fopen("sudoku50.txt", "r");

    if (fp == NULL) {
        printf("Error opening file\n");
        exit(1);
    }

    srand(time(NULL));
    int target = rand() % PUZZLES;
    int current = 0;
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
            if (ch == EOF) {
                printf("\n[Error] Reached EOF while loading puzzle %d\n", target);
                fclose(fp);
                return;
            }

            if (ch == '.') {
                board[row][col++] = 0;
            } else if (ch >= '1' && ch <= '9') {
                board[row][col++] = ch - '0';
            }
        }
        row++;
    }

    fclose(fp);
    printf("Successfully loaded puzzle #%d\n", target);
}


void printBoard() {
    int i, j;
    printf("\nSudoku Board:\n");

    for(i = 0; i < SIZE; i++) {
        for(j = 0; j < SIZE; j++) {
            if(board[i][j] == 0)
                printf(". ");
            else
                printf("%d ", board[i][j]);

            if((j+1) % 3 == 0 && j != 8)
                printf("| ");
        }
        printf("\n");

        if((i+1) % 3 == 0 && i != 8)
            printf("---------------------\n");
    }
}

int isValid(int row, int col, int num) {
    int i, j;

    for(i = 0; i < SIZE; i++) {
        if(board[row][i] == num)
            return 0;
    }

    for(i = 0; i < SIZE; i++) {
        if(board[i][col] == num)
            return 0;
    }

    int startRow = row - row % 3;
    int startCol = col - col % 3;

    for(i = 0; i < 3; i++) {
        for(j = 0; j < 3; j++) {
            if(board[startRow+i][startCol+j] == num)
                return 0;
        }
    }

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