#include <stdio.h>

int main () {

    printf("This programm solves the linear equation a*x + b = 0 for x\n");
    double a = 0, b = 0;
    double x= 0;
    printf("Please input a\n");
    scanf("%f",&a);
    printf("Please input b\n");
    scanf("%f",&b);
    x =  -1 * b /a ;
    printf("The solution for x is %.3f\n",x);
    return 0;
}
