#include <stdio.h>
#include <math.h>
#define truevalue 0.68268949

//Monte Carlo Method for the Integral 1/sqrt(2*pi)*exp(-x^2/2)
int main () {
  float a = -1;
  float b = 1;
  int n = pow(10,6);
  float dx = (b-a)/n;

  float getf (float x ){
    return 1/sqrt(2*M_PI)*exp(-(x*x)/2);
  }

  int i =0;
  float x = a;
  float total = 0;


  while (i<= n) {
    total += getf(x);
    x += dx;
    i++;
  }
  total *= (b-a)/n;
  printf("Total = %f\n",total);
  printf("Error = %f\n", total-truevalue);
  return 0;
}
