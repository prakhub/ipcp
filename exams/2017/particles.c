#include <math.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define N 20000
#define mu 0
#define sigma 0.02

typedef struct {
    float x [3];
    float v [3];
    float t;
} particle;

void printParticle (particle * p){
    printf("x,y,z = \n");
    for (int i = 0; i < 3; i++) {
        printf("%f, ",  (*p).x[i]);
    }
    printf("\n");
    printf("vx,vx,vz = \n");
    for (int i = 0; i < 3; i++) {
        printf("%f, ",  (*p).v[i]);
    }
    printf("\n");
}

void initializeParticle (particle *p , int offset) {
    srand(time(NULL)+ offset);
    for (int i = 0; i < N; i++) {
        float theta = 2.0 * M_PI * rand() / RAND_MAX;
        float phi = acos(2.0*rand() / RAND_MAX -1);
        float r = pow(rand()/(float)RAND_MAX, 1/3.0);
        /*
        printf("theta = %f\n", theta);
        printf("phi =%f\n",phi );
        printf("r = %.20f\n", r);
        */
        p->x[0] = r * cos(theta)*sin(phi);
        p->x[1] = r * sin(theta)*sin(phi);
        p->x[2] = r * cos(theta);

        //velocities
        float u1 = fabs(rand()) / RAND_MAX;
        //printf("u1 = %f\n",u1 );
        float u2 = fabs(rand()) / RAND_MAX;
        //printf("u1 = %f\n",u2 );

        p->v[0] = sqrt(-2*log(u1)) * cos (2 * M_PI * u2) * sigma;
        p->v[1] = sqrt(-2*log(u1)) * sin (2 * M_PI * u2) * sigma;
        u1 = fabs(rand()) / RAND_MAX;
        p->v[2] = sqrt(-2*log(u1)) * sin (2 * M_PI * u2) * sigma;

    }
}

void computeTimeForParticleToLeave (particle * p){
    //do as long as the particle is int the sphere.
    float t = 0;
    float dt = 1;
    while (fabs(p->x[0]) < 1 && fabs(p->x[1]) < 1 && fabs(p->x[2]) < 1){
        for (int i = 0; i < 3; i++) {
            p->x[i] += p->v[i] * dt;
        }
        t += dt;
    }
    p->t = t;
}

float computeAverage (float array [N]){
    float sum = 0;
    for (int i = 0; i < N; i++) {
        sum += array[i];
    }
    return sum/N;
}

float computeStdev (float array [N], float average){
    float sum = 0;
    for (int i = 0; i < N; i++) {
        sum += pow( array[i] - average, 2);
    }
    return sqrt(sum/N);
}
int main () {

    float time [N];
    for (int i = 0; i < N; i++) {
        particle temp;
        initializeParticle(&temp, i);

        computeTimeForParticleToLeave(&temp);
    //    printf("t = %f\n",  temp.t);
        time[i] = temp.t;
    }

    printf("Result: %f s with a stddev of %f s\n", computeAverage(time), computeStdev(time, computeAverage(time)) );



    return 0;
}
