#include <stdio.h>
#include <string.h>
#include "login.h"

void login(char username[]) {
    printf("===== Sudoku Login =====\n");
    printf("Enter your name: ");
    scanf("%s", username);

    printf("\nWelcome, %s! Let's play Sudoku.\n", username);
}

int calculateScore(int seconds) {
    // Faster time = higher score
    if (seconds <= 60) return 100;
    else if (seconds <= 180) return 80;
    else if (seconds <= 300) return 60;
    else return 40;
}