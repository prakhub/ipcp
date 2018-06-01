#include <stdio.h>
#include <math.h>

//A state holds the all needed data for a current iteration step.
typedef struct {
	float x,y;
	float yA, yB;
	float h;
} iteration;

float fAt (float x, float y);
float iterateAndGetError (iteration * st);
int iterationWillReachEndWithH (float x, float h);
void printIteration (iteration *st);

//starting values
const float yZero = 2/3.0;
const float x0 = 0.;
const float xmax = 3;
const float h0 = 0.1;
const float tolerance = 0.000001;



//Returns f(x,y)
float fAt (float x, float y){
	return y-x;
}

int main () {
	
	iteration st;
	st.x = x0;
	st.y = yZero;
	st.h = h0;
	
	while (st.x < xmax) {
		/*
		 * If we will step over xmax with the current h and x, reduce
		 * the stepsize h.
		 */
		if (iterationWillReachEndWithH(st.x, st.h)){
			st.h = xmax-st.x;
		}
		
		/*
		 * 1. Call iterateAndGetError to iterate our state.
		 * 2. Check if we need to reduce our stepsize in order
		 * to meet tolerance demands, else advance x and y.
		 */
		if(iterateAndGetError (&st) > tolerance){
			st.h *= 0.9 * pow(tolerance /(fabs(st.yA -st.yB)), 1/3.0);
		} else{
			st.x += st.h;
			st.y = st.yB;
		}
	}
	
	printIteration(&st);
	
	return 0;
}

//Checks if the iteration will step over xmax in the next iteration step.
//returns 1 if the iteration will step over xmax, 0 otherwise.
int iterationWillReachEndWithH (float x, float h){
	if (x+h > xmax) return 1;
	return 0;
}

//Iterates the state handed to it and returns the error (fabs(yA-yB)
float iterateAndGetError (iteration* st){
	float k1 = fAt(st->x,st->y);
	float k2 = fAt(st->x+st->h, st->y + st->h*k1);
	float k3 = fAt(st->x + 0.5 *st->h, st->y + st->h * (k1+k2)/4.0);
	
	st->yA = st->y + st->h * (k1 + k2) *0.5;
	st->yB = st->y + st->h * 1/6.0 * (k1 + k2 + 4*k3);
	
	return fabs(st->yA - st->yB);
}

void printIteration (iteration *st){
	printf ("{x = %f, y = %f, yA = %f, yB = %f, h = %f} \n" , st->x, st->y, st->yA, st->yB, st->h);
}

