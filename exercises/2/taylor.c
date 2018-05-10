#include <stdio.h>
#include <math.h>

int main () {
// The taylor series only matches well for small values (around 0)
    float i = 0;
    int steps = 5;
    // Taylor series around x = 0
    float taylor(float x){
        return 1 - x*x/2 + (x*x*x*x)/24;
    }

    while (i <= steps) {
        float a = cos(2*M_PI*i/steps);
        float b = taylor(2*M_PI*i/steps);
        printf("Cos = %f, ",a);
        printf("Taylor = %f \n",b);
        printf("Difference = %f \n ",a-b);
        i++;
    }

    return 0;
}
