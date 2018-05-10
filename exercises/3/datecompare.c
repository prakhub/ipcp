#include <stdio.h>

int main () {

    int d1, m1, y1, d2, m2, y2;
    printf("Please enter the first date in the format of *.*.*\n");
    scanf("%d.%d.%d",&d1, &m1, &y1);
    printf("Please enter the second date in the format of *.*.*\n");
    scanf("%d.%d.%d",&d2, &m2, &y2);
    if ( y1 < y2 ) {
        printf("2 is more recent\n");
    }
    if ( y1 > y2 ) {
        printf("1 is more recent\n");
    }
    if (y1 == y2) {
        if ( m1 < m2 ) {
            printf("2 is more recent\n");
        }
        if ( m1 > m2 ) {
            printf("1 is more recent\n");
        }
        if (m1 == m2) {
            if ( d1 < d2 ) {
                printf("2 is more recent\n");
            }
            if ( d1 > d2 ) {
                printf("1 is more recent\n");
            }
            if (d1 == d2) {
                printf("Both are the same dates!\n");
            }
        }
    }
    //printf("%02d.%02d.%04d \n",d,m,y);


    return 0;
}
