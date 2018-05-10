#include <stdio.h>
#include <math.h>

int randu (int input){
    return (input *65539) % (int) pow(2,31);
}

int main ()  {

    FILE *f = fopen ("points.txt", "w");

    int x = 1, y,z;

    float nMin = pow(2,20);
    float nMax = 0;
    //  fprintf(f,"{");

    for (int i = 0; i < 200000; i++) {

        x = randu (x);
        float xf = x / pow(2,31);
        y = randu(x);
        float yf = y / pow(2,31);
        z = randu(y);
        float zf = z/ pow(2,31);
        float n = 9 *xf - 6 * yf + zf;

    //    printf("n = %f\n", n );
        if (n > nMax){
            //printf("n = %i\n", n );
            nMax = n;
        }
        if (n < nMin) {
            //printf("n = %i\n", n );
            nMin = n;
        }
        fprintf(f,"%f %f %f \n",xf,yf,zf );
        //printf("%i %i %i\n",x,y,z );
    }
//    fprintf(f,"}\n");
    printf("nMax =  %.f \n", nMax);
    printf("nMin =  %.f \n", nMin);

    return 0;
}
