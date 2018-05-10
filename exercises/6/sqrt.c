#include <stdio.h>
#include <math.h>

float my_sqrt (float number, float precision){
    float xnext = number, x = 0;
    while( xnext*xnext -number > precision){
        x = xnext;
        xnext = 0.5 * (x + number/x);
    }
    return xnext;
}


int main () {
    for (int i = 1; i <= 10; i++) {
        printf("sqrt(%i) with precision 10^-5 = %f\n",i, my_sqrt(i,pow(10,-5)) );

    }
    return 0;
}
