#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

float arrayToNumber (int * arr, int length){
	
    int result = 0;
    for (int i = 0; i < length; i++) {
        result += *(arr+i) * pow(2,i);
    }
    //printf("result = %i\n", result);
    return result/1048575.0;
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

void randomInitialize (int * arr, int length){
	//printf("Original Array = \n");
    for (int i = 0; i < length; i++) {
		if ((int)rand()%2 == 1){
            *(arr+i) = 1;
        } else{
			*(arr+i) = 0;
		}
		//printf("%i, ",*(arr+i));
	}
	//printf("\n");
}
int main () {
    int length = 20;
    int arr [length];
    srand(time(NULL));
    
    //random initialization
	randomInitialize(arr, length);
	
    printf("Printing the first five generated numbers\n");
    for (int j = 0; j < 5; j++) {
        printf("Number %i = %f\n", j, arrayToNumber(arr,length));
        shuffle (arr,length);
    }
    
    
    printf("Calculating the mean of the first 10^4 numbers\n");
    int count = pow(10,4);
    /* the maximum of the sum is 1048575 (max value of array as number) * 10^4
    *  which is equal to 10 485 750 000.
    *  This is bigger than INT_MAX, therefor we have to use a bigger integer type
    */
	float sum = 0;
    for (int i = 0; i < count; i++) {
        sum += arrayToNumber (arr, length);
        shuffle (arr,length);
    }
    float mean = sum / count;
    printf("Mean = %f \n", mean);

    printf("Evaluating period:\n");
    float start = arrayToNumber(arr,length);
    int periodLength = 0;
    do {
        shuffle (arr,length);
        periodLength++;
    } while (arrayToNumber(arr,length) != start);

    printf("Period length = %i \n", periodLength);
    return 0;
}
