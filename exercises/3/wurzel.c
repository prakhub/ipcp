#include <stdio.h>
#include <math.h>

int main()
{
        /*
        float a;
        float b;

        a=103;
        b=-78;

        float wurzela = sqrt(a);
        float wurzelb = sqrt(b);

        printf("%f\n",wurzela);
        printf("%f\n",wurzelb);
        */
        printf("Please enter a number to calculate the squareroot of\n");
        float c;
        scanf("%f", &c);
        //check if c<0 and tell the user
        if (c<0) {
            printf("The entered number is smaller than zero and thus the squareroot cannot be calculated in R. \n");
            return -1;
        }
        printf("The sqrt is %f\n", sqrt(c));
        return 0;
}
