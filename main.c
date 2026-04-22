#include <stdio.h>
#include <time.h>
#include "board.h"
#include "file.h"
#include "game.h"
#include "login.h"
#include "leaderboard.h"

int main() {

    int row, col, num;
    char username[50];

    int original[SIZE][SIZE];

    // LOGIN
    login(username);

    loadRandomPuzzle();

    for(int i = 0; i < SIZE; i++) {
        for(int j = 0; j < SIZE; j++) {
            original[i][j] = board[i][j];
        }
    }

    time_t start, end;
    start = time(NULL);

    while(!isComplete()) {

        printBoard(original);

        printf("\nEnter row (1-9): ");
        scanf("%d", &row);

        printf("Enter column (1-9): ");
        scanf("%d", &col);

        printf("Enter number (1-9): ");
        scanf("%d", &num);

        row--;
        col--;

        if(original[row][col] != 0) {
            printf("Cannot change original cell!\n");
        }

        else if(isValid(row, col, num)) {
            board[row][col] = num;
        }
        else {
            printf("Invalid move!\n");
        }
    }

    end = time(NULL);

    int timeTaken = (int)(end - start);
    int score = calculateScore(timeTaken);
    
    printBoard(original);

    printf("\n🎉 Congratulations %s!\n", username);
    printf("Time Taken: %d seconds\n", timeTaken);
    printf("Score: %d\n", score);

    saveScore(username, score, timeTaken);
    displayLeaderboard();


    return 0;
}