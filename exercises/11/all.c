#include <stdio.h>
#include <math.h>

#define f -x*x*y*y
#define a 0
#define b 1

double fAt (double x, double y){
    return -x*x*y*y;
}

//Solves the dgl with euler's method
double solve_euler (double dx){
    double y = 1;
    for (double x = a; x < b; x+=dx){
        y += dx * f;
    }
    return y;
}


double solve_rgIV (double dx){
    double y = y0;
    //double k1 = ..
    for (double x = a; x < b; x+= dx){
        /*
        k1 = dx * derAt(x,y);
        //printf("k1 = %f\n",k1 );
        k2 = dx * derAt(x + 1/2*dx , y + 1/2*k1);
        //printf("k2 = %f\n",k2 );
        y += k2;
        printf("x,y = %f, %f\n",x,y);
        x+=dx;
        i++;
        */
        //k1 = ...
        double k1 = dx * fAt(x,y);
        //printf("k1 = %lf\n", k1);
        double k2 = dx * fAt(x + 1/2*dx, y +1/2 * k1);
        double k3 = dx * fAt(x + 1/2*dx, y +1/2 * k2);
        double k4 = dx * fAt(x + dx, y +k3);
        //printf("k2 = %lf\n", k2);
        y += k1/6 + k2/3 + k3/3 + k4/6;
        //printf("y = %lf\n", y);
    }
    return y;
}


double solve_rgII (double dx){
    double y  = y0;

    //double k1 = ..
    for (double x = a; x < b; x+= dx){
        /*
        k1 = dx * derAt(x,y);
        //printf("k1 = %f\n",k1 );
        k2 = dx * derAt(x + 1/2*dx , y + 1/2*k1);
        //printf("k2 = %f\n",k2 );
        y += k2;
        printf("x,y = %f, %f\n",x,y);
        x+=dx;
        i++;
        */
        //k1 = ...
        double k1 = dx * fAt(x,y);
        //printf("k1 = %lf\n", k1);
        double k2 = dx * fAt(x + 1/2*dx, y +1/2*k1);
        //printf("k2 = %lf\n", k2);
        y += k2;
        //printf("y = %lf\n", y);
    }
    return y;
}


int main () {

}
