#include <stdio.h>

int main()
{
	int a, max;
	printf("Please enter how often you want to print Hello World \n");
	scanf("%i",&max);
	for (a=0; a<max; a++)
	{
		printf("Hello World %d\n" , a);
	}
	return 0;
}
