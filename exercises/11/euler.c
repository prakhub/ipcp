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



/*
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
  while (i<= n) {
    y -= dx*(x*x)*(y*y);
    x += dx;
    printf("y = %f\n", y);
    printf("x = %f\n", x);
    i++;
  }

  return 0;
}
*/
