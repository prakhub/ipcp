#include <math.h>
#include <stdio.h>

double iterate (double x){
    return cos(x) /exp (x);
}
int main () {

    double x1 = 2;
    double x2 = iterate(x1);
    int counter = 1;
    while (! (fabs(x1-x2)<pow(10,-5))) {
        x1 = x2;
        x2 = iterate(x1);
        //printf("x1 = %f, x2 = %f\n", x1);

        counter++;
    }
    printf("Solving took %i steps.\n", counter);
    printf("Result: x1 = %f\n", x1);

    return 0;
}
