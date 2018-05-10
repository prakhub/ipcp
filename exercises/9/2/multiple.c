#include <stdio.h>
#include <math.h>

#define precision pow(10,-10)
#define w1 1.5
#define w2 17.0/4.0
#define gamma 0.3
#define a0 2.0

/*
 This method finds multiple roots for a given function in an interval a to b
 and prints them to the console.
 The idea behind the root-finding is to iterate over the interval with a
 (comparatively) big stepsize and apply the Newton-Cotes method as soon the
 signum of the function changes.
*/

//Returns the function value at a given position t.
double fAt (double t){
     return a0 * exp(-gamma * t)*(cos(w1*t)+sin(w2*t));
}
//Returns the derivative of the function at a given position t.
double fAtder (double t){
   return a0* exp(-gamma*t)*-gamma*(cos(w1*t)+sin(w2*t))
   + exp(-gamma *t)* a0 *(-sin(w1*t)*w1 + cos(w2*t)*w2);
}

//Returns the signum of a value
int sign (double x){
  if (x>0) {return 1;}
  if (x<0) {return -1;}
  if (x==0) {return 0;}
}

/*
  Finds the root of the function with a given starting position a.
  The function and the precision are defined above.
*/
double findRoot (double a){
    double x1 = 0, x = a;
    while (fabs(x1-x) > precision){
        x1 = x - (fAt (x)/ fAtder(x));
        x = x1;
    }
    return x;
}

/*
 Calculates and prints all roots between 0 and 5.
*/
int main () {
    double a = 0;
    double b = 5;
    double stepsize = pow(10,-5);

    int tempSign = sign(fAt(a));
    int counter = 0;
    //iterate over the interval
    for (double i = a; i < b; i += stepsize){
        int tempSignNew = sign(fAt(i));
        //find the root if the signum changes.
        if (tempSign !=  tempSignNew){
            printf("Root at %lf\n", findRoot(i));
        }
        tempSign = tempSignNew;
    }

}
