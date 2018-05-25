#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define fIn arccos(1- 2*x)


float getF (float x){
    if (x >= 0 && x <= M_PI) return sin(x)/2;
    else return 0.0;
}

float getFInverse (float x){
    if (x < 0 ) return 0;
    if (x >= 0 && x<= M_PI) return acos(1-2*x);
    else return 1;
}

void writeHistogramF (int N, int sampleSize){
    char filename [10];
    sprintf (filename, "%i.txt",N);
    FILE *f = fopen(filename, "w");
    srand(time(NULL));

    for (int i = 0; i < sampleSize; i++) {
        float x = fabs((float) rand() / RAND_MAX * M_PI);
        fprintf(f,"%f\n", fabs(getF(x)));
    }
}

void writeHistogramFInverse (int N, int sampleSize){
    char filename [10];
    sprintf (filename, "%i.txt",N);
    FILE *f = fopen(filename, "w");
    srand(time(NULL));

    for (int i = 0; i < sampleSize; i++) {
        float x = fabs((float) rand() / RAND_MAX * M_PI);
        fprintf(f,"%f\n", fabs(getFInverse(x)));
    }
}
int main () {
    int sampleSize = (int) pow(10,5);
    writeHistogramFInverse(12, sampleSize);

}
