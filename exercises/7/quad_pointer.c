#include <stdio.h>
#include <math.h>

int square_equation(float a, float b, float c, float* r1, float* r2){

    float dis = b*b -4*a*c;
    if (dis == 0) {
        * (r1) =  -b/(2*a);
        return 1;
    }
    if (dis > 0) {
        *(r1) = -b+sqrt(dis)/(2*a);
        *(r2) = -b-sqrt(dis)/(2*a);
        return 2;
    }
    if (dis < 0 ) {
        return 0;
    }
}

int main() {

    float a = 0,b,c;
    while (a == 0) {
        printf("Please enter the coefficents of the quadratic equation int the format a,b,c \n");
        scanf("%f,%f,%f", &a,&b,&c);
        if (a == 0) {
            printf("a can't be zero, because the equation wouldn't be of degree 2 otherwise\n");
        }
    }

    float r1, r2;
    int solutions = square_equation (a,b,c,&r1,&r2);
    if (solutions == 0) {
        printf("No solution in R because discriminant is complex\n");
    }
    if (solutions == 1) {
        printf("Only 1 Solution because the discriminant is zero\n");
        printf("This Solution is %.3f \n", r1);
    }
    if (solutions == 2) {
        printf("2 solutions exist\n");
        printf("The solutions are %.3f and %.3f \n", r1,r2);
    }
    return 0;
}
