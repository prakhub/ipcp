#include <stdio.h>


int main()
{
	//Main Prolem: float inaccuracy
	//Fix: use double

	//We define the variables
	double balance = 0; 			//initial balance (to be read from user)
	double increase = 0;			//increase (to be read from user)
	double newbalance = 0;		//new balance (we will calculate this)

	printf("Enter starting balance in Swiss Francs\n");
	scanf("%lf", &balance); //reading the initial balance from user
													//VERY IMPORTANT: Notice the & in front of the variable
													//read slides from 27.2.2018, slide 10 for explanation

	printf("Enter increased to be credited to account in swiss Francs\n");
	scanf("%lf", &increase); //reading the increase

	newbalance = balance + increase; //calculating the nes balance

	printf("Account balance (Francs): %.2lf\n", newbalance); //printing the result


	return 0;
}
