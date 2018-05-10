#include <stdio.h>
#include <string.h>
#define d 3

int lc (int i, int j, int k){
    if (i == j || j == k || i == k){
        return 0;
    }
    int array [d] = {i,j,k};

    for (int i = 0; i < d; i++) {
        //check if array
        if (array[0] == 1 && array[1] == 2 && array[2] == 3) return 1;
        if (array[0] == 3 && array[1] == 2 && array[2] == 1) return -1;
        //permute array
        int temparray [] = {array[2], array[0], array[1]};
        memcpy(array, temparray, d *sizeof(int));
    }
}

int main () {

    float v1 [3], v2[3];

    printf("Please enter a 3D-Vector in the format i,i,i\n");
    scanf("%f,%f,%f", &v1[0],&v1[1],&v1[2]);

    printf("Please enter another 3D-Vector in the format i,i,i\n");
    scanf("%f,%f,%f", &v2[0],&v2[1],&v2[2]);

    float scalarProduct = 0;
    for (int i = 0; i < d; i++) {
        scalarProduct += v1[i] * v2[i];
    }

    printf("The scalar product of both vectors is: %.2f\n",scalarProduct);

    float vectorProduct [d];
    //memset
    for (int i = 0; i < d; i++) {
        vectorProduct[i] = 0;
    }
    
    // a x b = lc(i,j,k) * aj * bk
    for (int i = 0; i < d; i++) {
        for (int j= 0; j < d; j++) {
            for (int k= 0; k < d; k++){
                //careful to call levi cevita with 1,2,3 instead of 0,1,2
                vectorProduct[i] += lc(i+1,j+1,k+1) * v1[j]* v2[k];
            }
        }
    }

    printf("The vector is : %.1f,%.1f,%.1f\n", vectorProduct[0],vectorProduct[1],vectorProduct[2]);


    /*
    printf("lc (1,2,3) = %i \n",lc(1,2,3) );
    printf("lc (1,2,2) = %i \n",lc(1,2,2) );
    printf("lc (2,3,1) = %i \n",lc(2,3,1) );

    printf("lc (3,2,1) = %i \n",lc(3,2,1) );
    printf("lc (3,1,2) = %i \n",lc(3,1,2) );
    printf("lc (2,1,3) = %i \n",lc(2,1,3) );
    printf("lc (1,3,2) = %i \n",lc(1,3,2) );
    */

    return 0;
}
