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
  int sign (double x){
    if (x>0) {return 1;}
    if (x<0) {return -1;}
    if (x==0) {return 0;}
  }

  printf("Please enter b and a\n");
  double a,b;
  scanf("%lf\n%lf",&a,&b);

  while(valueat(a)*valueat(b)>=0){
    printf("No root in Intervall!\n");
    printf("Please enter b and a\n");
    scanf("%lf\n%lf",&a,&b);
  }

  //Amount of needed steps for calculation wih precision epsilon
  double n = log((b-a)/epsilon)/log(2 );
  printf("n = %lf\n",n);

  // Do the bisection for n steps
  for (int i = 0; i <= n; i++) {
    double c = (a+b)/2;

    //If the value at c has the same signum as the value at a, the root is in
    //intervall [c,b], if else it is in [a,c]

    if (sign(valueat(c))== sign(valueat(a))) {
      a = c;
    }else{
      b = c;
    }

  }
  printf("a = %.18lf\n",a);
  printf("b = %.18lf \n",b);
  printf("a-b = %.18lf\n",a-b);
  return 0;
}
