#include <stdio.h>


int main()
{
	//Main problem : integer overflow in calculating and printing
	// Fix: use long int and specify %li for printf

	//We define the variables
	long int balance = 0; 			//initial balance (to be read from user)
	long int increase = 0;			//increase (to be read from user)
	long int newbalance = 0;		//new balance (we will calculate this)

	printf("Enter starting balance in Swiss centimes\n");
	scanf("%i", &balance); //reading the initial balance from user
													//VERY IMPORTANT: Notice the & in front of the variable
													//read slides from 27.2.2018, slide 10 for explanation

	printf("Enter increased to be credited to account in swiss centimes\n");
	scanf("%i", &increase); //reading the increase

	newbalance = balance + increase; //calculating the nes balance

	printf("Account balance (cents): %li\n", newbalance); //printing the result



	return 0;
}
