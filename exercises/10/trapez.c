#include <stdio.h>
#include <math.h>

//integration precision
#define precision pow(10,-7)

//function to integrate
#define f 1/sqrt(2*M_PI)*exp(-x*x/2)

/*
 * Implements the trapeziodal rule for numeric Integration
 */

double fAt (double x){
    return f;
}
//calculates the integral from a to b
double getI (double a, double b) {
    double c = b-a;
    //dummy initialization
    double J = 100, Jnext = 0;
    //counter for steps
    int n = 0;

    while (fabs(2*J-Jnext)*c/pow(2,n) > precision* Jnext){
        n++;
        J = Jnext;
        //trapeziodal rule, see lecture 10 slide 12
        for (double i =(double) 1.0/pow(2,n); i < 1; i+= 1/pow(2,n-1)){
            Jnext += fAt (a + i*c);
        }
    }
    return Jnext/pow(2,n)*c;
}

int main () {
    //calculate integrals of -1,1 -2,2, ....
    for (int i = 1; i <= 5; i++) {
        printf("I from %i to %i = %.7lf\n", -i ,i , getI((double) -i, (double) i));
    }
    return 0;
}
