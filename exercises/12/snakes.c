#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define sides 6
#define a 85

int getRoll (int previousRoll){
    return (a*previousRoll % (8191));
}


int getSteps (int seed){
    int x = 0;
    int roll = seed;
    int counter = 0;
    while (x != 100) {
        roll = getRoll(roll);
        x += roll % 6;
        if (x > 100) x = 100 -(x%100);
        //printf("x = %i\n", x);
        counter ++;
    }
    return counter;
}

int getSteps_c (int seed){
    srand(seed);
    int x = 0;
    int counter = 0;

    while (x != 100) {
        int roll = rand() % 6;
        x+= roll;
        if (x == 50) x = 45;
        if (x == 20) x = 30;
        if (x > 100) x = 100 -(x%100);
        counter++;
    }
    return counter;
}
int main (){

    FILE *f = fopen("histo_snakes_myrandom","w");
    for (int i = 1; i <= 5000; i++) {
        fprintf(f, "%i\n", getSteps(i));
    }

    FILE *g = fopen("histo_snakes_crandom","w");

    for (int i = 1; i <= 1000000; i++) {
        fprintf(g, "%i\n", getSteps_c(i));
    }
}
