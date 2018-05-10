#include <stdio.h>
#include <math.h>

int main(){

  FILE *f = fopen("weather_ger.txt","r");
  int amountOfStations = 4;
  int measurementTime = 60*24;
  int amountOfMeasurments = 2;
  float nullValue = -1000;
  // stationId, type of measurment (0 = temperature, 1 = humidity), time in min.
  float data [amountOfStations][amountOfMeasurments][measurementTime];
  //initialize data with nullvalue
  for (int a = 0; a < amountOfStations; a++) {
      for (int b = 0; b < amountOfMeasurments; b++) {
          for (int c = 0; c < measurementTime; c++) {
              data[a][b][c] = nullValue;
          }
      }
  }
  float arrrivedMeasurements [amountOfStations];
  int time = 0;

  while( !feof(f) ) {
      int receivedSignals = 0;
      fscanf(f,"%i %i",&time, &receivedSignals);
      for (int i = 0; i < receivedSignals; i++) {
          int stationId;
          float temperature = nullValue, humidity = nullValue;
          fscanf(f,"%i %f %f",&stationId, &temperature, &humidity);
          arrrivedMeasurements[stationId-1]++;
          //use stationId-1, because the numbering starts at 1 and not 0 as in the array
          data[stationId-1][0][time] = temperature;
          data[stationId-1][1][time] = humidity;
      }
      time++;
  }
  fclose(f);


  /* Calculate averages of all measurements
  * i = stationId
  * k = measurment type
  * t = time
  */
  float averages [amountOfStations][amountOfMeasurments];
  for (int i = 0; i < amountOfStations; i++) {
      for (int k = 0; k < amountOfMeasurments; k++) {
          float sum = 0;
          for (int t = 0; t < measurementTime; t++) {
             if ( data[i][k][t] != nullValue){
                 sum += data[i][k][t];
             }

          }
          averages [i][k] = sum / arrrivedMeasurements[i];
          //printf("Average for station %i for measurment %i: %.2f\n", i, k, averages[i][k] );
      }
  }

  /* Calculate standard deviations of all measurements
  * The averages and standard deviations can unfortunately not be done in one
  * single loop.
  * i = stationId
  * k = measurment type
  * t = time
  */
  float stddevs [amountOfStations][amountOfMeasurments];
  for (int i = 0; i < amountOfStations; i++) {
      for (int k = 0; k < amountOfMeasurments; k++) {
          float sum = 0;
          for (int t = 0; t < measurementTime; t++) {
              if (data[i][k][t] != nullValue) {
                 sum += pow (data[i][k][t]-averages[i][k],2);
              }
          }
          stddevs[i][k] = sqrt(sum / arrrivedMeasurements[i]);
        //  printf("Standard deviation for station %i for measurment %i: %.2f\n", i, k, stddevs[i][k] );

      }
  }
  // calculate transmission efficiency for every station
  float efficiencies [amountOfStations];
  for (int i = 0; i < amountOfStations; i++) {
      efficiencies[i] = arrrivedMeasurements[i] / measurementTime;
      //printf("Transmission efficiency for station %i: %.2f \n", i, efficiencies[i]);
  }
  printf("Station |T av.| T stdev | Hm av. | Hm stdev| Transmission efficiency \n");
  for (int i = 0; i < amountOfStations; i++) {
    printf("%i \t |%.2f\t|%.2f\t|%.2f\t|%.2f\t|%.2f \n",i+1, averages[i][0], stddevs[i][0], averages[i][1], stddevs[i][1], efficiencies[i] );
  }
  return 0;
}
