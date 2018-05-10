#include <stdio.h>
#include <math.h>

//This Programm sovles the problem e^-x -x = 0 for x

int main (){

float a0 = 2.0f, gamma = 0.3f, w1 = 1.5f, w2 = 4.25f;
  //precision
  double epsilon = 0.00000001;

  //Returns the value of the function at x
  double valueat (double t){
    return a0 * exp(-gamma* t)*(cos(w1*t)+sin(w2*t));
  }
  double valueat_der (double t){
     double temp = a0* exp(-gamma*t)*-gamma*(cos(w1*t)+sin(w2*t));
     temp += exp(-gamma *t)* a0 *(-sin(w1*t)*w1 + cos(w2*t)*w2);
     return temp;
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

  double root_distance = 0.1;
  int amountOfPoints = (b-a)/root_distance;
  float results [amountOfPoints];

  for (int j = 0; j < amountOfPoints; j++) {
      for (int i = 0; i <= n; i++) {
        x -= valueat(x)/valueat_der(x);
      }
      if (a<x && x<b) {
          results[j] = x;
      } else{
          results[j] = -10;
      }
      j++;
      x= a+ j*root_distance;
  }
  for (int i = 0; i < amountOfPoints; i++) {
      printf("%f\n",results[i] );
  }
 // group roots together

  return 0;
}
