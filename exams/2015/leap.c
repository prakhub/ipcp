#include <stdio.h>

//Reads a year from the user and checks if it is a leap year
//The programm will read years until a valid one (>0) is entered.
int main () {
    printf("Please enter a year to check for beig a leap year\n");
    int input = -10;
    while (input < 0) {
        printf("Please enter a year >= 0\n");
        scanf("%i",&input);
    }
    if( input % 4 == 0 && input % 100 != 0 || input % 400 == 0){
        printf("The year %i is a leap year\n", input);
    } else{
        printf("The year %i is not a leap year\n", input);
    }
    return 0;
}
