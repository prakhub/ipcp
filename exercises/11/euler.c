#include <stdio.h>
#include <math.h>

#define f -x*x*y*y
#define a 0
#define b 1

double solve (double dx){
    double y = 1;
    for (double x = a; x < b; x+=dx){
        y += dx * f;
    }
    return y;
}
int main () {
    printf("Exact Result: %lf\n", 3/4.0);

    for (int i = 1; i < 8; i++){
        double dx = 1/pow(10,i);
        double sol = solve(dx);
        printf("With stepsize 10^-%i: %lf\n", i, sol);
        printf("Delta = %.15lf\n", 0.75 - sol );
    }
}
