#include <stdio.h>
#include <math.h>

 #define a 0.0
 #define b M_PI /4

double fAt (double x){
    return 3.0 *tan(x) / (1.0 + pow(cos(x),2));
}
int main () {

    double precision = pow (10, -6);
    double I1 = 1, I2 = 0;
    int stepCounter = 500;
    double I = 0;
    double Iorg = I;
    double dist = (b-a);
    I += 2.0/45.0 * dist /4.0  * (7 * fAt (dist/4) + 32 * fAt (dist/2) + 12 * fAt (3 * dist /4) + 7 * fAt (dist));
    //while (fabs(I1- I2) > precision) {
    for (int j = 0; j < 10; j++) {
        double Itemp = 0;
        for (int i = 1;  i <= stepCounter; i++){
            double dist = (b-a)/stepCounter;
            //printf("fAt (dist) = %lf\n",fAt(dist) );
            Itemp += 2.0 /45.0 * dist /4.0  * (32 * fAt (dist/(2* i)) + 12 * fAt (3 * dist / (4 * i)));

        //    printf("I = %f\n", I);
        }
        I = I * 45.0 /2 + Itemp;
        printf("I = %lf\n", I);
    }

    //}

}
