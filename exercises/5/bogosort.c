#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include <math.h>

void permuteArray (int * originalArray, int size, int *pTemp) {
//array to store the sorted array
int sortedArray [size];
//copy of originalArray
int Orig [size];

int * pOrig = &Orig[0];
int * pSortedArray = &sortedArray[0];
//initialize values
for (int i = 0; i < size; i++) {
        sortedArray[i] = -1;
        *(pOrig+i) = *(originalArray + i);
}

for (int i = 0; i < size; i++) {
        while (*(pSortedArray + i) == -1){
            int tempIndex = (int) rand () % size;
            //printf("tempIndex = %i\n", tempIndex);
            if(* (pOrig + tempIndex) != -1){
                /*
                *Set the value in the Sorted array to the element at the
                * tempIndex of the originalArray.
                * Then remove the element of that index from the originalArray.
                */
                *(pSortedArray+i) = * (pOrig + tempIndex);
                *(pOrig + tempIndex) = -1;
            }

        }
    }
    for (int i = 0; i < size; i++) {
    *(pTemp+i) = *(pSortedArray+i);
    }
}

/**
* This function checks if the array is correctly sorted by size.
* @param pArray pointer to the Array
* @param size size of the array
*/
int validateSort (int * pArray ,int size){
    int count = 0;

    for (size_t i = 0; i < size -1; i++) {

        if (*(pArray+ i) > *(pArray + i + 1) ){
            count ++;
        }
    }

    if(count == 0){
        return 1;
    } else {
        return 0;
    }
}

// use  for i in {1..1000}; do ./bogosort >> b; done
// for benchmarking
int main () {
    //set seed for  rand
    srand (time(NULL));
    // Main Logic
    int size = 8;
    int originalArray[size];

    //pointer to array
    //int originalArray[] = { 1, 10, 9,  7, 3, 0, 45, 12, 34, 19 , 17 };
    FILE *f = fopen("/dev/urandom", "r");
    fread (originalArray,1,size*sizeof(int),f);

    //printf("Sorting this Array: \n");
    for (size_t i = 0; i < size; i++) {
        originalArray[i]  = rand() ;
        originalArray[i] = abs(originalArray[i] * originalArray[i]) % 100;
        //printf("%i, ", originalArray[i]);
     }

    // printf("\n");
     if (validateSort(originalArray, size) == 1){
         printf("Array is sorted\n");
     }

     int steps = 0;
     int temp [size];
     int * pTemp = &temp[0];

     while (validateSort(temp, size) != 1) {
        permuteArray (originalArray, size, pTemp);
        steps++;
    }

     //printf("Array is Sorted!\n");
     printf("%i\n",steps);
     //printf("Solving took %i steps!\n",steps);

    // printf("The Sorted Array is:\n");
     for (int i = 0; i < size; i++) {
         printf("%i, ",*(temp+i) );
     }
    // printf("\n");

    return 0;
}
