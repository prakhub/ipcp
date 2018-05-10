#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int arrayToNumber (int * arr, int length){
    int result = 0;
    for (int i = 0; i < length; i++) {
        result += *(arr+i) * pow(2,i);
    }
    //printf("result = %i\n", result);
    return result;
}

void shuffle (int * arr, int length){
    int tempArray [length];
    memset(tempArray,0,length * sizeof(int));

    int temp = *(arr + 2) + *(arr + 19);
    //printf("temp = %i \n", temp);
    *(tempArray) = temp%2;

    for (int i = 1; i < length  ; i++) {
        *(tempArray + i) = *(arr+i-1);
    }

    memcpy(arr,tempArray, length * sizeof(int));
}
int main () {
    int length = 20;
    int arr [length];
    srand(time(NULL));
    //random initialization

    //printf("Original Array = \n");
    for (int i = 0; i < length; i++) {
        float temp = (float) rand()/RAND_MAX;
        //printf("temp = %f\n", temp);

        if (temp > 0.5){
            arr [i] = 1;
        }
        if (temp < 0.5) {
            arr[i] = 0;
        }
        //printf("%i, ", *(arr+i));
    }
    //printf("\n");
    /*
    int test[] = {1,0,1};
    printf("1,0,1 equals the number %i\n", arrayToNumber(test,3));
    (should equal 5)
    */
    /*
    printf("Equals the number %i\n", arrayToNumber(arr,length));
    printf("Shuffling ....\n");
    shuffle(arr, length);

    printf("New array: \n");
    for (int i = 0; i < length; i++) {
        printf("%i, ", arr[i] );
    }
    printf("\n");
    printf("Equals the number %i\n", arrayToNumber(arr,length));
    */
    printf("Printing the first five generated numbers\n");
    for (int j = 0; j < 5; j++) {
        printf("Number %i = %i\n", j, arrayToNumber(arr,length));
        shuffle (arr,length);
    }
    printf("Calculating the mean of the first 10^4 numbers\n");
    int count = pow(10,4);
    /* the maximum of the sum is 1048575 (max value of array as number) * 10^4
    *  which is equal to 10 485 750 000.
    *  This is bigger than INT_MAX, therefor we have to use a bigger integer type
    */
    unsigned long long int sum = 0;
    for (int i = 0; i < count; i++) {
        sum += arrayToNumber (arr, length);
        shuffle (arr,length);
    }
    int mean = sum / count;
    printf("Mean = %i \n", mean);

    printf("Evaluating period:\n");
    int start = arrayToNumber(arr,length);
    int periodLength = 0;
    do {
        shuffle (arr,length);
        periodLength++;
    } while (arrayToNumber(arr,length) != start);

    printf("Period length = %i \n", periodLength);
    return 0;
}
