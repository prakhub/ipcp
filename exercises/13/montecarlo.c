#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define truevalue 0.68268949

//Monte Carlo Method for the Integral 1/sqrt(2*pi)*exp(-x^2/2) from -1 to 1


float getf (float x ){
  return 1/sqrt(2*M_PI)*exp(-(x*x)/2);
}

int main () {
	
	//iterations
	int N = (int) pow(10,6);
	//intervall
	float a = -1, b = 1;
	//stddev
	float sigma;
	
	//temporary values for monte carlo method.
    float total = 0;
    float squareTotal =0;
    
    //sample the function N times at random places between a and b.
    for (int i = 0; i < N; i++) {
        float f = getf((b-a)*rand() /RAND_MAX + a);
        total += f;
        squareTotal+= f*f;
    }
    sigma = sqrt(fabs(1/N *squareTotal - pow(total/N,2)));
	
	//Scale integral values
    total *= (b-a)/(float)N;
    printf("Integral Value = %f\n",total);
    printf("Actual error = %f\n", truevalue-total);
    printf("Estimated error = %f \n", sigma/sqrt(N-1));
	printf("Error difference = %f \n",  fabs(fabs(truevalue-total) -sigma/sqrt(N-1)));
    return 0;
}
