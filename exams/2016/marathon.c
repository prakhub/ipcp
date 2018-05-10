#include <stdio.h>

//marathon length
#define length 42195
//starting speed
#define v0 17 / 3.6f

float calculateTimeFromSpeed (float speed){
    int distance = speed * 60 * 60;
    float time = 60*60;
    //run the loop until the target is reached
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
    //printf("v0 = %f \n", v0);
    float normalTime = calculateTimeFromSpeed(v0);
    printf("Time for marathon with a starting speed of 17 km/h: %.2fs \n", normalTime);

    //calculate speed to finish marathon in exactly 3 hours = 10800 seconds
    float vStep = 0.001;
    float accuracy = 0.1;
    float targetTime = 10800;
    //because the speed is reduced, v has to be bigger than you would expect and
    // this is a good starting value
    float v = length / targetTime;
    printf("targetTime - accuracy = %.2f\n", targetTime - accuracy);
    printf("targetTime + accuracy = %.2f\n", targetTime + accuracy);

    while (calculateTimeFromSpeed(v) > targetTime - 20 )
     {

        v +=vStep;
        //printf("calculateTimeFromSpeed(%f) = %f\n", v,calculateTimeFromSpeed(v) );
        if (calculateTimeFromSpeed(v) <= (targetTime + accuracy)){
            //printf("wut\n");
            break;
            if ( calculateTimeFromSpeed(v) >= (targetTime - accuracy)){
                //printf("true\n");
                break;
            }
        }
    }
    v -=vStep;

    printf("Starting speed = %.2f km/h for a time of %.2fs\n",v * 3.6, calculateTimeFromSpeed(v) );


    return 0;


}
