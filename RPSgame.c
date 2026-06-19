#include <stdio.h> 
#include <string.h>

struct Choices {
    char question[100];
    // We make the array size 4, so indices 1, 2, and 3 are perfectly valid
    char options[4][100]; 
    int userChoice;
};

int main(void) {
    printf("Welcome to Classic Rock Paper Scissors\n\n");

    struct Choices game;
    strcpy(game.question, "Choose your weapon:");
    
    // We leave index 0 empty/unused so 1, 2, and 3 match the user's input perfectly
    strcpy(game.options[1], "Rock");
    strcpy(game.options[2], "Paper");
    strcpy(game.options[3], "Scissors");

    // Display options to the user
    printf("%s\n", game.question);
    for(int i = 1; i <= 3; i++) {
        printf("[%d] %s\n", i, game.options[i]);
    }

    // Direct logging without any math alterations
    printf("\nEnter your choice (1-3): ");
    scanf("%d", &game.userChoice); 

    // Confirm exactly what was stored
    printf("\nLogged choice number: %d\n", game.userChoice);
    printf("Logged choice weapon: %s\n", game.options[game.userChoice]);

    return 0;
}

