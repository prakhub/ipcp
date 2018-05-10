#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int getMax (int * array , int size){
    int max = -1;
    int maxIndex;
    for (int i = 0; i < size; i++) {
        if (max < *(array+i)) {
            max = *(array+i);
            maxIndex = i;
        }
    }
    *(array + maxIndex) = -1;
    return max;
}

int main (){
    srand(time(NULL));
    int size = 20;
    int originalArray[size];

    printf("Sorting this Array: \n");

    for (size_t i = 0; i < size; i++) {
        originalArray[i]  = rand() %100;
        printf("%i, ", originalArray[i]);
     }
     printf("\n");

     int sortedArray[size];

     for (int i = size -1; i >= 0; i--) {
         int temp = getMax (originalArray, size);
         sortedArray[i] = temp;
     }

     printf("Sorted array:\n");
     for (size_t i = 0; i < size; i++) {
         printf("%i, ", sortedArray[i]);
      }
      printf("\n");

    return 0;
}
