#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define truevalue 0.68268949


float getf (float x ){
  return 1/sqrt(2*M_PI)*exp(-(x*x)/2);
}


//Monte Carlo Method for the Integral 1/sqrt(2*pi)*exp(-x^2/2) from -1 to 1
int main () {

    float total = 0;
    int N = (int) pow(10,6);
    //sample the function 10^6 times at random places between -1 and 1.
    for (int i = 0; i < N; i++) {
        total += getf( (float) rand() /RAND_MAX);
    }
    //*2 is from the length of [-1,1]
    total *= 2/(float)N;
    printf("Total = %f\n",total);
    printf("Error = %f\n", total-truevalue);

    return 0;
}
