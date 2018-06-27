#include "single_roots.h"

double fAt (double x) {
	return exp(-x) - x;
}

int main () {
	double (*function)(double) = &fAt;
	
	double x = getBisectionRoot(function, 0.00000001, 0.0, 1);
	
	printf("x = %.10lf", x);
	return 0;
}
