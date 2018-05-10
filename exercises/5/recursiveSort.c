#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main (){
    srand(time(NULL));
    int size = 11;
    int originalArray[size];

    printf("Sorting this Array: \n");

    for (size_t i = 0; i < size; i++) {
        originalArray[i]  = rand() %100;
        printf("%i, ", originalArray[i]);
     }
     printf("\n");




    return 0;
}
