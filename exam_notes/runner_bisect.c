#include <stdio.h>
#include "single_roots.h"

#define length 42195

double calculateTimeFromSpeed (double speed);
void printTime(double time);


void printTime(double time){
	int hours = time/ (3600.0);
	time -= 3600* hours;
	int minutes = time/ (60);
	time -= 60 * minutes;
	double seconds = time;
	printf("%2i:%02i:%02.2lf \n",hours,minutes,seconds);
	}

double calculateTimeFromSpeed (double speed){
    double distance = speed * 60.0 * 60.0;
    double time = (double)60*60;
    int counter = 0;
    //run the loop until the target is reached
    while (distance <= length){
        speed *= 0.99;
        distance += speed * 60 * 10;
        //printf("distance %im at time %.2fs\n", distance, time);
        time += 10*60;
        counter ++;
        if (counter > 1000) return 100000;
    }
    //go one step back in front of the target in order to accurately calculate
    // the time for the runner to arrive
    distance -= speed * 60 * 10;
    time -= 10 *60;
    time += (length -distance) /speed;
    distance += length -distance;
    //printf("distance %im at time %.2fs\n", distance, time);
    return time;
}

int main () {
	printf("Time with starting speed of 17 km/h = ");
	printTime(calculateTimeFromSpeed(18/(3.6)));
	
	double targetTime = (double) 3*3600;
	
	double differenceToTargetTime (double speed){
		return calculateTimeFromSpeed(speed)- targetTime;
	}
	/*because the bisection works on the starting speed and not on the
	* the resulting time, we cant specifiy the resolution of 0.1 in the
	* call of the bisection method and have to go with a higher value.
	* 
	*/
	double targetSpeed = getBisectionRoot (&differenceToTargetTime, 0.0001, 0, 20);
	
	printf("Target speed is %lf km/h with a time of ", targetSpeed* 3.6);
	printTime(calculateTimeFromSpeed(targetSpeed));
	
	return 0;
}
