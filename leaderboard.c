#include <stdio.h>
#include "leaderboard.h"

void saveScore(char username[], int score, int timeTaken) {
    FILE *fp = fopen("leaderboard.txt", "a");

    if (fp == NULL) {
        printf("Error saving score!\n");
        return;
    }

    fprintf(fp, "%s %d %d\n", username, score, timeTaken);
    fclose(fp);
}

void displayLeaderboard() {
    FILE *fp = fopen("leaderboard.txt", "r");

    if (fp == NULL) {
        printf("\nNo leaderboard data found.\n");
        return;
    }

    char name[50];
    int score, time;

    printf("\n===== Leaderboard =====\n");
    printf("Name\tScore\tTime(s)\n");

    while (fscanf(fp, "%s %d %d", name, &score, &time) != EOF) {
        printf("%s\t%d\t%d\n", name, score, time);
    }

    fclose(fp);
}