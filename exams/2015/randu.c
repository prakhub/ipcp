#include <stdio.h>
#include <math.h>

//returns the next number in the random sequence.
int randu (int input){
    return (input *65539) % (int) pow(2,31);
}

int main ()  {

    FILE *f = fopen ("points.txt", "w");
	
	//initial seed
    int x = 1;

	//nMin, nMax to store maximum/minimum of 9x-6y+z
    float nMin = pow(2,20);
    float nMax = 0;
    
    //generate 10k points in 3D-Coordinates and write them to a file.
    for (int i = 0; i < 100000; i++) {
       
		x = randu(x);
        float xf = x / pow(2,31);
        x = randu(x);
        float yf = x / pow(2,31);
        x = randu(x);
        float zf = x / pow(2,31);
   
        float n = 9.0 *xf - 6.0 * yf + zf;
		
        if (n > nMax){
            nMax = n;
        }
        if (n < nMin) {
            nMin = n;
        }
        fprintf(f,"%f %f %f \n",xf,yf,zf );
    }
    printf("nMax =  %.2f \n", nMax);
    printf("nMin =  %.2f \n", nMin);

    return 0;
}
