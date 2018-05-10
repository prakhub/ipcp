#include <stdio.h>
#include <math.h>

int main(){
  FILE *g = fopen("sequence.txt","w");

  int N = pow(2,5);
  int i =1;
  while ( i<=N )  {
      fprintf(g, "%i \n",i);
      i *= 2;
  }
  fclose(g);

  FILE *f = fopen("sequence.txt","r");
  int temp = -5;

  while (!feof(f)) {
      temp = fscanf(f,"%i \n",&temp);
      printf("%li \n", temp);
  }

  fclose(g);

  return 0;
}
