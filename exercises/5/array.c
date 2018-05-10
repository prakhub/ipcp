#include <stdio.h>
#include <math.h>
int main () {

    float numbers[10];

    printf("Please enter 10 Numbers\n");
    for (int i = 0; i < 10; i++) {
        printf("Number %i\n",i );
        scanf("%f", &numbers[i]);
    }
    float total = 0;

    for (int i = 0; i < 10; i++) {
        printf("number %i = %f \n",i, numbers[i]);
        total += numbers[i];
    }
    float mean = total / 10;
    float stddev = 0;
    for (int i = 0; i < 10; i++) {
        stddev += pow((numbers[i]-mean),2);
    }
    stddev = sqrt (stddev);
    printf("Average = %f \n", total /10 );
    printf("stddev = %f \n", stddev);
    return 0;
}
