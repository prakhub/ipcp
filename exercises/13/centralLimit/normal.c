#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>

float getMeanFromNSamples (int n){
    float sum = 0;

    for (int i = 0; i < n; i++) {
        sum += fabs( (float) rand()/ RAND_MAX);
    }
    return (sum-6)/(float) n;
}

void sampleAndPrintToFile (int n, int sampleCount){
    char filename [10];
    sprintf(filename, "%i.txt", n);

    srand(time(NULL)+n+sampleCount);

    FILE *f = fopen(filename, "w");
    for (int i = 0; i < sampleCount; i++) {
        fprintf(f, "%f\n", getMeanFromNSamples(n));
    }


}

int main () {
    int sampleCount = pow(10,5);
    sampleAndPrintToFile (12, sampleCount);




}
