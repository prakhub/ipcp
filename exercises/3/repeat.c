#include <stdio.h>
#include <math.h>
int main () {
    /*
    // Works only for repetitons smaller than an int.
    // a = number to repeated
    // b = how often to repeat number
    //save an approximation of 0.1111....
    long double f = (long double) 1/9;
    */
    int a,b;

    printf("Please enter a number and then how many times you would like to repeat it\n");
    scanf("%i",&a);
    scanf("%i",&b);
    int limit = 15;
    void recursive (int a, int b){
        if (b>limit) {
            unsigned long long int result = (pow(10,limit)-1)/9 * a;
            printf("%li", result);
            recursive (a, b-limit);
        } else{
            unsigned long long int result = (pow(10,b)-1)/9 * a;
            printf("%li \n", result);
        }
    }

    printf("result = " );
    recursive(a,b);

    /*
    unsigned long long int result = (pow(10,b)-1)/9 * a;
    printf("result = %li \n", result);
    */
    return 0;
}
