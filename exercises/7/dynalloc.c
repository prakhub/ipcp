#include <stdio.h>
#include <stdlib.h>

int main () {

    int size = 2;
    int * array = (int *) calloc (size,sizeof(int));

    //copy and Array to a new one
    void copyArray (int * oldArray, int * newArray, int oldSize ){
        for (int t = 0; t < oldSize; t++){
            * (newArray + t)= *(oldArray + t);
        }
    }
    //counter for accesing array[t]
    int t = 0;
    //main logic
    while (1){
        printf("enter next int(t = %i)\n",t);
        scanf("%i", array + t);
        t++;

        if (t > size/2) {

            printf("array is filled by more than half, Increasing size from %i to %i \n",size, 2*size );
            int * tempArray = (int *) calloc (2*size,sizeof(int));
            copyArray (array, tempArray , size);
            free (array);
            int * array = tempArray;
            printf("Array is: \n");
            for (int i = 0; i < t; i++) {
                printf("%i, ", *(tempArray + i) );
            }
            printf("\n");
            size *= 2;
        }
    }

    free(array);
    return 0;
}
