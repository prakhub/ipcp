#include <stdio.h>

int main () {
    /*
    *  With 1 for capital, 100% interest rate and continuous compounding
    *  (interval very short) one gets e as the captial after a year
    */
    float capital;
    float rate, years;
    float interval;

    printf("Please enter your statring capital \n");
    scanf("%f",&capital);
    printf("Please enter the rate of interest in percent\n");
    scanf("%f", &rate);
    printf("Please enter a number of years to wait\n");
    scanf("%f", &years );
    printf("Please enter a payment interval (n time per year) for the interest\n");
    scanf("%f", &interval);

    interval = 1/ interval;
    float i = 0;
    while (i < years) {

        capital += interval * capital * rate / 100 ;
        i += interval;
    }
    printf("captial = %f \n", capital);
    return 0;
}
