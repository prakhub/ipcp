#include <math.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define N 2
typedef struct {
    float x [3];
    float v [3];
    float t;
} particle;


int main () {

    particle particles [N];
    particle * p = malloc(N * sizeof(particle));
    srand(time(NULL));

    for (int i = 0; i < N; i++) {
        float theta = 2 * M_PI * rand() / RAND_MAX;
        float phi = acos(2*rand() / RAND_MAX -1);
        float r = pow(rand() / RAND_MAX, 1/3.0);
        particles[N].x[0] = r * cos(theta)*sin(phi);
        particles[N].x[1] = r * sin(theta)*sin(phi);
        particles[N].x[2] = r * cos(theta);
    }
    printf("%f", particles[1].x[1]);


    return 0;
}
