#include <stdio.h>

//Defining function/conditionals to be evaluated
int my_exp1 (int a, int b, int c){
    return a && b;
}

int my_exp2 (int a, int b, int c){
    return a || b;
}

int my_exp3 (int a, int b, int c){
    return !a && !b;
}

int my_exp4 (int a, int b, int c){
    return !(a || b );
}

int my_exp5 (int a, int b, int c){
    return 	!a && ( b || c );
}

int my_exp6 (int a, int b, int c){
    return b || (!a && c);
}

//prints a truthtable for a conditional depending on 3 values

void printTruthTable (int (*funcp)(int,int,int)){

    for (size_t i = 0; i <= 1; i++) {
        for (size_t j = 0; j <= 1; j++) {
            for (size_t k = 0; k <= 1; k++) {
                printf("%i   %i    %i\t   ", i, j,k);
                if( (*funcp)(i,j,k) ) printf("%i\n",1);
                else printf("%i\n",0);
            }
        }
    }
    return;
}
int main () {

    //define pointers to all functions
    int (*fp1)(int,int,int) = &my_exp1;
    int (*fp2)(int,int,int) = &my_exp2;
    int (*fp3)(int,int,int) = &my_exp3;
    int (*fp4)(int,int,int) = &my_exp4;
    int (*fp5)(int,int,int) = &my_exp5;
    int (*fp6)(int,int,int) = &my_exp6;

    //print truth tables for functions
    printf("a   b   c\t a && b\n");
    printTruthTable (fp1);

    printf("a   b    c\t a || b\n");
    printTruthTable (fp2);

    printf("a   b    c\t !a && !b\n");
    printTruthTable (fp3);

    printf("a   b    c\t !(a || b )\n");
    printTruthTable (fp4);

    printf("a   bn   c\t !a && ( b || c )\n");
    printTruthTable (fp5);

    printf("a   b    c\t !a b || (!a && c)\n");
    printTruthTable (fp6);



    return 0;
}
