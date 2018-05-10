#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main () {

    srand(time(NULL));

    void printTip (int guess, int target){
        
        if (guess > target) {
            printf("too high!\n");
        } else{
            printf("too low!\n");
        }

    }
    int target = rand()%1000;
    printf("target = %i\n", target );
    int guess = -1;
    int tries = 10;
    printf("Please enter your guess between 1 and 1000\n");
    int guessCounter = 0;

    while (guessCounter <= tries) {
        printf("enter guess\n");
        scanf("%i", &guess);
        if (target == guess){
            printf("You won!\n");

            break;
        }else{
            printTip (guess, target);
        }
        guessCounter++;
    }
    if (guessCounter > tries) {
        printf("You lost! \n");
    }
    return 0;
}
