#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <math.h>

int main () {
	
	int cache_size = 1000;
	int * cache = malloc(cache_size * sizeof(int));
	memset(cache, -1, cache_size*sizeof(int));
	
	unsigned long long int i;
	
	int counter_max = 0;
	int number_max = 0;
	
	for (int j = 1; j <= pow(10,6); j++){
		i = j;
		int counter = 0;
		while (i != 1){
			
			if (i < cache_size){
				if (cache[i] != -1){
					counter += cache[i];
					break;
				}
			}
			
			if(i%2 == 0){
				i /= 2;
			} else {
				i = 3*i + 1;
			}
		counter++;
		}
		if (i < cache_size){
			if(cache[i] == -1){
				cache[i] = counter;
			}
		}
		if (counter > counter_max){
			counter_max = counter;
			number_max = j;
		} 
		
	}
	
	printf("counter_max = %i \n", counter_max);
	printf("number_max = %i \n",number_max);
	
	
	return 0;
}
