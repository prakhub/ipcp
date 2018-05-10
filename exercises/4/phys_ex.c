#include <stdio.h>
#include <math.h>
#define g 9.81
int main () {
    float h = 2;
    float x = 0, y = h;
    float t = 0, dt = 0.1;
    float v = -1, alpha = -1;
    while (v<0) {
        printf("Please enter a positive throwing velocity v \n");
        scanf("%f",&v);
    }
    while (alpha > 90 || alpha < 0) {
        printf("Please enter the throwing angle alpha in degrees [0,90]\n");
        scanf("%f",&alpha);
    }
    alpha = (2 * M_PI * alpha) /360;
    //printf("alpha = %f\n", alpha);
    float vx = v * sin(alpha);
    //printf("vx = %f\n",vx );
    float vy = v * cos(alpha);
    //printf("vy = %f\n",vy );
    printf("(x,y)(t) = (%.2f,%.2f)(%.2f)\n", x,h,t);

    while (y>=0) {
        t += dt;
        printf("(x,y)(t) = (%.2f,%.2f)(%.2f)\n", x,y,t);

        x += vx*dt;
        y += vy * dt;
        vy =vy - g*dt;
        if (y < 0) {
            //Implement flight time (y0, v0y, 1/2at^2)
            float temp = (-vy + sqrt(-2*g*h+ (vy*vy)))/g;
            printf("Hit the ground after %.3f s\n", temp);
            break;
        }


    }
    return 0;
}
