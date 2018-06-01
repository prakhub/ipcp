#include <stdio.h>
#include <math.h>


int getPeriod (int a, int start){

    int x = start ,x0;
    int counter = 0;
    do {
        x0 = x;
        x = x0*a %((int) pow(2,13)-1);
        counter++;
        //printf("%i\n", x0);
    } while(x != start);
    return counter;
}

void printValues (int a, FILE *f, int limit, int modulo, int start){

    int x = start ,x0;
    int counter = 0;
    for (int i = 0; i < limit; i++) {
        x0 = x;
        x = x0*a %((int) pow(2,13)-1);
        counter++;
        fprintf(f, "%i\n", x&modulo);
    }

}

int main (){

    int a_arr [] = {81,83,85};

    for (int i = 0; i < 3; i++) {

        char filename[2];
        sprintf(filename, "%i", a_arr[i]);
        FILE *f = fopen(filename,"w");
        printValues(a_arr[i], f, 3000, 6, 1);

        //printf("Period for %i: %i\n",a_arr[i], getPeriod(a_arr[i]));
    }

    printf("finding longest starting value\n");
    int max  = 0;
    int maxlength = 0;
    for (int i = 1; i < 8190; i++) {
        int tempPeriod = getPeriod(85,i);

        if (tempPeriod > maxlength){
            max = i;
            maxlength = tempPeriod;
        }
      //  printf("tempPeriod = %i\n", tempPeriod);
    }
    printf("max = %i with a period of %i\n", max, getPeriod(85,max));

    printf("getPeriod(85,40) = %i\n", getPeriod(85,40) );
}
