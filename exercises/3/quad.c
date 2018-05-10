#include <stdio.h>
#include <math.h>

int main() {

    float a,b,c;
    printf("Please enter the coefficents of the quadratic equation int the format a,b,c \n");
    scanf("%f,%f,%f", &a,&b,&c);
    if (a == 0) {
        printf("a can't be zero, because the equation wouldn't be of degree 2 otherwise\n");
    }
    float dis = b*b -4*a*c;
    printf("dis = %f\n",dis);
    if (dis == 0) {
        printf("Because the discriminant is zero, there is only one solution\n");
        printf("This Solution is %f\n", -b/(2*a) );
    }
    if (dis > 0) {
        printf("Because the discriminant is posivitve, there are two solutions\n");
        printf("These Solutions are %f and %f", -b+sqrt(dis)/(2*a), -b-sqrt(dis)/(2*a) );
    }
    if (dis < 0 ) {
        printf("Because the discriminant is negative, there are no solutions in R\n");
    }

    return 0;
}
