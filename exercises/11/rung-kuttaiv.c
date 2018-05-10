#include <stdio.h>
#include <math.h>

#define a 0.0
#define b 1.0
#define y0 1.0
//y' (x,y)
//#define f  -x*x*y*y

double fAt (double x, double y){
    return -x*x*y*y;
}

double solve (double dx){
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
        double k2 = dx * fAt(x + 1/2*dx, y +1/2 * k1);
        double k3 = dx * fAt(x + 1/2*dx, y +1/2 * k2);
        double k4 = dx * fAt(x + dx, y +k3);
        //printf("k2 = %lf\n", k2);
        y += k1/6 + k2/3 + k3/3 + k4/6;
        //printf("y = %lf\n", y);
    }
    return y;
}

//Solves the DGL y'= -x^2 *y^2
int main () {

    for (int i = 1; i < 8; i++){
        double dx = 1/pow(10,i);
        double sol = solve(dx);
        printf("With stepsize 10^-%i: %lf\n", i, sol);
        printf("Delta = %.15lf\n", 0.75 - sol );
    }
    /*
    printf("With stepsize %.1lf: %lf\n", 0.1, solve(0.1));
    printf("With stepsize %.2lf: %lf\n", 0.01, solve(0.01));
    printf("With stepsize %.3lf: %lf\n", 0.001, solve(0.001));
    printf("With stepsize %.3lf: %lf\n", 0.0001, solve(0.0001));
    */
    return 0;
}


/*
#include <stdio.h>

//Solves the DGL y'= -x^2 *y^2
int main () {
  float a = 0;
  float b = 0;
  float dx;
  while (a>=b) {
    printf("Please enter Intervall start \n");
    scanf("%f",&a);
    printf("Please enter Intervall end \n");
    scanf("%f",&b);
    printf("a = %f , b = %f \n",a,b );
    if (a>b) {printf("Intervall-Error, please try again:\n \n");}
  }
  printf("Please enter Stepsize:\n");
  scanf("%f", &dx);
  printf("b-a = %f", b-a);
  while (dx >= b-a) {
    printf("Stepsize too big! Please enter a smaller one:\n");
    scanf("%f", dx);
  }
  int n = (int) (b-a)/dx;
  printf("Performing %i steps\n",n);
  float y = 1;
  int i =0;
  float x = a;
  float k1,k2,k3,k4;

  float derAt (float x, float y){
    return -(x*x)*(y*y);
  }

  while (i<= n) {
    k1 = dx * derAt(x,y);
    k2 = dx * derAt(x + dx/2 , y + k1/2);
    k3 = dx * derAt(x + dx/2 , y + k2/2);
    k4 = dx * derAt(x +dx , y +k3);

    y += (k1+k4)/6 + (k2+k3)/3;
    printf("x,y = %f, %f\n",x,y);
    x+=dx;
    i++;
  }

  return 0;
}
*/
