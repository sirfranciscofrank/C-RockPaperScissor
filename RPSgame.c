#include <stdio.h> 
#include <string.h>
#include <stdlib.h>   // for rand() and srand()
#include <time.h>     // for time() to seed the RNG

struct Choices {
    char question[100];
    char options[4][100]; 
    int userChoice;
    int computerChoice;
};

int main(void) {
    printf("Welcome to Classic Rock Paper Scissors\n\n");

    struct Choices game;
    strcpy(game.question, "Choose your weapon:");
    strcpy(game.options[1], "Rock");
    strcpy(game.options[2], "Paper");
    strcpy(game.options[3], "Scissors");

    printf("%s\n", game.question);
    for (int i = 1; i <= 3; i++) {
        printf("[%d] %s\n", i, game.options[i]);
    }

    printf("\nEnter your choice (1-3): ");
    scanf("%d", &game.userChoice); 

    // Guard against invalid input BEFORE we use it as an array index
    if (game.userChoice < 1 || game.userChoice > 3) {
        printf("\nInvalid choice. Please run again and pick 1, 2, or 3.\n");
        return 1;
    }

    // Seed the random generator once, then pick 1-3 for the computer
    srand(time(NULL));
    game.computerChoice = (rand() % 3) + 1;

    printf("\nYou chose:      %s\n", game.options[game.userChoice]);
    printf("Computer chose: %s\n", game.options[game.computerChoice]);

    // Decide the winner
    if (game.userChoice == game.computerChoice) {
        printf("\nIt's a draw!\n");
    } else if (
        (game.userChoice == 1 && game.computerChoice == 3) ||  // Rock beats Scissors
        (game.userChoice == 2 && game.computerChoice == 1) ||  // Paper beats Rock
        (game.userChoice == 3 && game.computerChoice == 2)     // Scissors beats Paper
    ) {
        printf("\nYou win!\n");
    } else {
        printf("\nComputer wins!\n");
    }

    return 0;
}
