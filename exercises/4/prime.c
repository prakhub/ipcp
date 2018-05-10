#include <stdio.h>

int main () {
    int input;
    printf("Please enter a number to check for being a prime\n");
    scanf("%i",&input );
    int p_flag = 0;
    for (int i = 2; i < input-1; i++) {
        if (input % i == 0) {
            p_flag =1;
        }
    }
    if (p_flag == 0) {
        printf("Your number is prime\n");
    }else {
        printf("Your number is not prime\n");
    }
}
