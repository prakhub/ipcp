#include <stdio.h>
#include <string.h>

typedef struct {
  unsigned int date;
  char firstname[30];
  char lastname[30];
  unsigned int year;
  char nation[30];
  float time;
  float wind;
} record;

void printInfos (int index,int lines, record data [lines]){
    printf("%s %s \n",data[index].firstname , data[index].lastname);
}
int main () {

    FILE *lineCounter = fopen("records_ger.txt","r");
    int lines = 0;
    char ch;
    while(!feof(lineCounter))
    {
        ch = fgetc(lineCounter);
        if(ch == '\n')
        {
            lines++;
        }
    }

    
    FILE *f = fopen("records_ger.txt","r");

    record data [lines];

    for (int i = 0; i < lines; i++) {
        fscanf(f,"%i %s %s %i %s %f %f", &data[i].date, &data[i].firstname, &data[i].lastname, &data[i].year, &data[i].nation, &data[i].time, &data[i].wind );
    }
    fclose(f);

    float correctedTimes [7];
    //memset(correctedTimes,0,lines*sizeof(float));

    for (int i = 0; i < lines; i++) {
        float v = 100 / data[i].time;
        v -= data[i].wind * 0.1;
        //printf("v = %f\n", v);
        *(correctedTimes + i)= 100 / v;
        //printf("correctedTimes[%i]\n", correctedTimes[i] );
        //printf("corrected time %.2f \n",correctedTimes[i] );
        //printf("difference: %.2f\n", correctedTimes[i] - data[i].time);
    }
    //printf("correctedTimes[1] = %f\n", correctedTimes[1]);
    for (int i = 0; i < lines; i++) {
    //    printf("correctedTimes[%i] = %.3f \n",i,correctedTimes[i] );
    //    printf("data[%i].time = %.3f\n",i,data[i].time );
    }

    //initial values
    int youngestIndex = 0;
    int minAge = 1000;
    float minTime = 1000;
    int fastestIndex = 0;
    float minTimeCorrected = 1000;
    int fastestIndexCorrected = 0;

    for (int i = 0; i < lines; i++) {
        if (data[i].date -data[i].year <= minAge){
             minAge = data[i].date -data[i].year;
             youngestIndex = i;
         }
         //printf("data[%i].time = %f\n",i,data[i].time );
         //printf("data[].time = \n");
         //printf("data[%i].time = %f\n",i,data[i].time);
         if (data[i].time <= minTime) {
             minTime = data[i].time;
             fastestIndex = i;
         }
         //printf("correctedTimes[%i] = %f\n",i,correctedTimes[i] );
         if (correctedTimes[i] <=minTimeCorrected) {
             minTimeCorrected = *(correctedTimes+i);
             fastestIndexCorrected = i;
         }

    }
    printf("youngest age = %i, index = %i \n",minAge, youngestIndex );
    printInfos (youngestIndex, lines, data);

    printf("fastest time = %.4f, index = %i \n",minTime, fastestIndex );
    printInfos (fastestIndex, lines, data);

    printf("fastest corrected time at index %i = %.4f \n",fastestIndexCorrected,minTimeCorrected );
    printInfos (fastestIndexCorrected, lines, data);

    return 0;
}
