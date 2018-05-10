#include <math.h>
#include <stdio.h>
#define end  M_PI / 4
double fAt (double x){
    return 3 * tan (x) / (1 + pow(cos(x),2));
}

/*
h = end/iterations;
double sum = 0;
for (int i = 0; i < iterations; i++) {
    x0 = x0 + h;
    printf("x0 = %f\n", x0);
    double hTemp = h/4;
    sum += 2/45 * (7 * fAt(x0) + 32 * fAt (x0 +hTemp) +12 * fAt (x0 +2*hTemp)
            +32 * fAt (x0 +3*hTemp)  + 7 * fAt (x0 +4*hTemp));
            printf("sum = %f\n", sum);
}
return sum;
*/
void Istrip (double x0, double h, int iterations, int * sum){
    if () {
        Istrip(x0,h/4,)
    } else  {
        sum += 2/45 * (7 * fAt(x0) + 32 * fAt (x0 +hTemp) +12 * fAt (x0 +2*hTemp)
                +32 * fAt (x0 +3*hTemp)  + 7 * fAt (x0 +4*hTemp));
        return;
    }
}

int main () {
    double T = pow(10,-6);
    double h = M_PI / 4  / 4;
    printf("h = %f\n", h);
    double i1 =0, i2 = 1;
    double x0 = 0;
    printf("start = %f, end = %f\n", x0,end);
    for (int i = 0; i < 10; i++) {
        printf("istrip (%i) = %f\n",i, Istrip(x0,h,i) );
    }

    double i1 = 0, i2 = 1;
    while (fabs(i1-i2)< T){


    }
    return 0;
}
