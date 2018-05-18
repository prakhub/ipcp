#include <stdio.h>
#include <math.h>

#define precision pow(10,-7)


double fAt (double x){
    return 1/sqrt(2*M_PI)*exp(-x*x/2);
}

double getI (double a, double b, int n) {
    double h = (b-a)/n;
    double I = 0;
    I += fAt(a) + fAt(b);
    for (int i = 1; i <= n-1; i++){
        if (i % 2 == 0){
            I += 2 * fAt(a +h*i);
        } else {
            I += 4 * fAt(a +h*i);
        }
    }
    return  I* 1.0/3.0 * h;

}

double getNewI (double a, double b){
    double I1 = 0, I2 = 100;
    int n = 3;
    while (fabs(I1- I2) > I2 * precision){
        I1 = I2;
        I2 = getI(a,b,n);
        n++;
    }
    printf("I1 = %.10lf, I2 = %.10lf\n", I1, I2 );
    return I2;
}

int main () {

    for (int i = 1; i <= 5; i++) {
        printf("I from %i to %i = %lf\n", -i ,i , getNewI(i,-i));
    }



    return 0;
}
