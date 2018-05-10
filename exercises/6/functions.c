#include <stdio.h>
#include <math.h>
int sign (float x){
    if (x < 0){
        return -1;
    }
    if (x == 0) {
        return 0;
    }
    if (x > 0){
        return 1;
    }
}

int factorial (int n){
    if (n > 1) return n* factorial(n-1);
    else return n;
}
float mysqrt (float x){
    long double xMorePrecise = x;
    long double result = sqrt(xMorePrecise);
    return (float) result * sign(x);

}
int main () {
    /*
    for (int i = 0; i < 10; i++) {
        printf("factorial(%i) = %i \n",i,factorial(i) );
    }
    */
    for (size_t i = 0; i < 5; i++) {
        printf("sqrt(%i) = %f \n",i, mysqrt(i) );
    }
}
