#include <stdio.h>
#include <math.h>
#define g 9.81f

//Calculates falltime for a dropped stone, without air resistance
//s = 1/2 a* t ^2
// => t = sqrt(2s/a)
int main (){

 	float h = -1;
	float t;
	while (h<0) {
		printf("Enter starting height > 0 \n");
		scanf("%f",&h);
	}
	t = sqrt(2*h/g);
	printf("Time for falling stone = %.4f s\n",t);
	return 0;
}
