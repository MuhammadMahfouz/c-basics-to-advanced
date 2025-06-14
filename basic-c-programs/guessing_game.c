//guessing game to guess the number 42
#include <stdio.h>

int mainn() {
    int guess;
    while(scanf("%d", &guess) != EOF) {
        if (guess == 42) {
            printf("Congratulations! You guessed the number!\n");
            break;
        }
        else if (guess < 42) {
            printf("Too low! Try again.\n");
        } 
        else {
            printf("Too high! Try again.\n");
        }
    }
}