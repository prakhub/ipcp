#include <stdio.h>

//marathon length in m
#define length 42195
void printTime(float t, char  temp  [50]);

float calculateTimeFromSpeed (float speed){
	//run one hour at the initial speed
    float distance = speed * 60 * 60;
    float time = 60*60;
    
    //Run 10 minutes and then reduce the speeed until the target is reached.
    while (distance <= length){
        speed *= 0.99;
        distance += speed * 60 * 10;
        //printf("distance %im at time %.2fs\n", distance, time);
        time += 10*60;
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
	char time [10];
	//First part of the exercise
    printTime(calculateTimeFromSpeed(17.0 / 3.6), time);
    printf("Time for marathon with a starting speed of 17 km/h: %s \n", time);

	/*Second part of the exercise:
	 * We start with a velocity too slow for completing the marathon in
	 * 3 hours and then increase it and try again until we get a time of
	 * 3 hours +- 0.1 s.
	 */
	 
	//Velocity increase.
    float vStep = 0.00001;
    //Desired accuracy of total time in s.
    float accuracy = 0.1;
    //Desired total time in s.
    float targetTime = 60*60*3;
    
    /* Initially, we guess the speed the constant speed to run the marathon
	 * in 3 hours without the runner slowing down. This speed is surley
	 * lower than the required speed with the runner gradually slowing
	 * down and this means that we can our iteration here.
	 */
	  
    float v = length / targetTime;
    
    do {
        v +=vStep;
       // printf ("time = %f \n", calculateTimeFromSpeed(v));
    } while (calculateTimeFromSpeed(v) > targetTime +accuracy);
    //v-=vStep;
    printf("Starting speed = %.3f km/h for a time of %.2fs\n",v * 3.6, calculateTimeFromSpeed(v) );
    printTime(calculateTimeFromSpeed(v), time);
    printf("Time = %s \n", time);
    
    return 0;
}

void printTime(float time, char temp [50]){
	int hours = (int) time/3600;
	time -= 3600*hours;
	int minutes = (int) time/60;
	time -= 60*minutes;
	int seconds = (int) time;
	sprintf(temp, "%02i:%02i:%02i", hours,minutes,seconds);
}
