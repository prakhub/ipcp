#include <stdio.h>
#include <math.h>

//This Programm sovles the problem e^-x -x = 0 for x

int main (){
  //precision
  double epsilon = 0.00000001;

  //Returns the value of the function at x
  double valueat (double x){
    return exp(-x) - x;
  }
  double valueat_der (double x){
    return -exp(-x) - 1;
  }
  int sign (double x){
    if (x>0) {return 1;}
    if (x<0) {return -1;}
    if (x==0) {return 0;}
  }

  printf("Please enter b and a\n");
  double a,b;
  scanf("%lf\n%lf",&a,&b);
  double x = a;

  //Amount of needed steps for calculation wih precision epsilon
  double n = log((b-a)/epsilon)/log(2 );
  printf("n = %lf\n",n);
  double root_distance = 0.5;

  for (int j = a; x < b; j++) {
      for (int i = 0; i <= n; i++) {
        if (valueat_der(x) == 0) {
            continue;
        }
        x -= valueat(x)/valueat_der(x);
      }
      printf("Root at x = %f\n", x);
      x= a+ j*root_distance;
  }
  return 0;
}
