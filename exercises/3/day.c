#include <stdio.h>

int main () {
    //Switch for amount of days in month (int month between 0 and 11)
    int daysInMonth (int month){
        switch (month) {
            case 0: return 31;
            case 1: return 28;
            case 2: return 30;
            case 3: return 30;
            case 4: return 31;
            case 5: return 30;
            case 6: return 31;
            case 7: return 31;
            case 8: return 30;
            case 9: return 31;
            case 10: return 30;
            case 11: return 31;
        }
    }
    int d,m;
    printf("Please enter a date in the format DD.MM \n");
    scanf("%i.%i",&d, &m);
    int days = 0;
    for (int i = 0; i < m-1; i++) {
        days += daysInMonth(i);
    }
    days += d-1;
    printf("days between start and date = %i\n",days );
    days = days % 7;
    printf("the weekday is %i\n", days);
    /*
    for (int i = 0; i < 12; i++) {
        printf("Month %i has %i days\n", i+1, daysInMonth(i));
    }
    */    //switch for printing day (gets an int between 0 and 6)
    return 0;
}
