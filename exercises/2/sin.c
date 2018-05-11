#include <stdio.h>
#include <math.h>

int main () {
    //sin uses radians
    float x;
    printf("Please enter number to calculate sin() of\n");
    scanf("%f",&x);
    printf("Result = %f\n",sin(x));
    return 0;
}
