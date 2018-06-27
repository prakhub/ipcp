#include <stdio.h>
#include <math.h>


#include <stdio.h>
#include <math.h>

int sign (double x);
double getBisectionRoot (double (*fAt)(double), double epsilon, double a, double b);
//double getNewtonRoot (double (*fAt)(double), double (*fDer)(double), double epsilon, double a, double b);


int sign (double x){
    if (x>0) {return 1;}
    if (x<0) {return -1;}
    return 0;
 }

double getBisectionRoot (double  (*fAt)(double), double epsilon, double start, double end){
	//required steps for accuracy
	double n = log((end-start)/epsilon)/log(2);
	
	double a = start, b = end;
	
	for (int i = 0; i <= n; i++) {
		double c = (a+b)/2;
		//If the value at c has the same signum as the value at a, the root is in
		//intervall [c,b], if else it is in [a,c]
		
		//printf("[a,b] = [%lf, %lf] \n",a,b);
		if (sign((*fAt)(c))== sign((*fAt)(a))) {
		  a = c;
		}else{
		  b = c;
		}
  }
  return (a+b)/2;
}

/*
double getNewtonRoot (double (*fAt)(double), double (*fDer)(double), double epsilon, double a, double b){
	
}
*/
