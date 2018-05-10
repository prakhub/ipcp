#include <stdio.h>
#include <math.h>

double f (double x, double y){
    return y-x;
}
int main () {
    double x = 0;
    double y = 2/3;
    double h = 0.1;
    double T=0.0001;
    double ya,yb;
    double k1,k2,k3;
    double yOld;
    while (x < 3){
        k1 = f (x,y);
        k2 = f(x +h, y +h*k1);
        k3 = (x+ 1/2 *h, y + h*(k1+k2)/4);
        ya = y + h/2 *(k1+k2);
        yb = y + h/6 *(k1+k2+4*k3);
        if (fabs(yb-ya)< T) {
            x += h;
            yOld = y;
            y = yb;
        } else{
            h = 0.9 *h *pow(T/fabs(yb-ya),1/3);
        }
        //printf("h = %f\n",h);
    }
    //go back and hit x = 3 exactly
    x -= h;
    y = yOld;
    h = 3-x;
    k1 = f (x,y);
    k2 = f(x +h, y +h*k1);
    k3 = (x+ 1/2 *h, y + h*(k1+k2)/4);
    ya = y + h/2 *(k1+k2);
    yb = y + h/6 *(k1+k2+4*k3);
    x += h;
    y = yb;
    printf("x,y = %lf, %lf\n",x,y );

    return 0;
}
