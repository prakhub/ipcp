#include <stdio.h>
#include <math.h>

int main (){

  double seed = 8190;
  double y = 0;
  int a = 85; //81,83
  double myrand (double x){
    return fmod(a*x,pow(2,13)-1);
  }

  double first = myrand(seed);
  y = first;
  int i =0;
  do {
    y = myrand(y);
    i++;
  } while(y!= first);

  printf("i =%i \n",i);

  return 0;
}
