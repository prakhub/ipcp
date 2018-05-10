#include <stdio.h>
#include <math.h>

int main(){

  FILE *f = fopen("data_ger.txt","r");
  FILE *h = fopen("filtered.txt","w");
  float x,y,z;
  while( !feof(f) ) {
    fscanf(f,"%f %f %f",&x,&y,&z);
    float v = sqrt((x*x)+(y*y)+(z*z));
    if(v>=30) {
        fprintf(h,"%.3f %.3f %.3f \n",x,y,z);
    }

  }
  fclose(h);
  fclose(f);



  return 0;
}
