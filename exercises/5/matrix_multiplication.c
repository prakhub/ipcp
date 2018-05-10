#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//dimensions
#define a 2
#define b 2

void print (double matrix [a][b]){
    for (int i = 0; i < a; i++) {
        for (int j = 0; j < b; j++) {
            printf("| %3.1lf ", matrix[i][j] );
        }
        printf("|\n");
    }
}

int main () {
    srand (time(NULL));

    double m1 [a][b], m2[a][b];
    for (int i = 0; i < a; i++) {
        for (int j = 0; j < b; j++) {
            m1 [i][j] = (double) rand() / RAND_MAX * 9.9;
            m2 [i][j] = (double) rand() / RAND_MAX * 9.9;
        }
    }

    //double m1[a][b] = {{1,2},{3,1}}, m2[a][b] = {{1,3},{5,1}};

    print(m1);
    printf("\n");
    print(m2);

    double c [a][b];
    memset (c,0,a*b*sizeof(double));

    //matrix multiplication:
    // m1 (l x m) * m2 (m x n) = c (l x n)
    for (int i = 0; i < a; i++) {
        for (int k = 0; k < b; k++) {
            //printf("k = %i\n",k );
            for (int j = 0; j < b; j++) {
            //    printf("m1[i][j] = m1[%i][%i] = %3.1lf\n",i,j, m1[i][j]);
            //    printf("m2[j][k] = m2[%i][%i] = %3.1lf\n",j,k, m1[j][k]);
                c[i][k] += m1[i][j] * m2[j][k];
            }
        }
    }
    printf("Product: \n");
    print(c);

    return 0;
}
