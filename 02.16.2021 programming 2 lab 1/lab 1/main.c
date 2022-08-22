#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//*************************************************** Made by: **************************************************************
//
//                                               Yusupov Yuldashbek
//
//***************************************************************************************************************************
//
//                                                  Hello World!

int main(void)
{
	//pat 1
	int num1 = 10, num2 = 100, num3 = 1000;
	printf ("N\t 10*N\t 100*N\t 1000*N\n\n");
	for (int i = 1; i <= 10; i++)
	{
		num1 *= i;
		num2 *= i;
		num3 *= i;
		printf("%d\t %d\t %d\t %d\t\n", i, num1, num2, num3);
		num1 = 10, num2 = 100, num3 = 1000;
	}

	//part 2
	int p2, num21, small=10000000;
	printf("Enter the length of the sequence: ");
	scanf("%d", &p2);
	if (p2 <= 0)
		return -1;
	for (int q = 0; q < p2; q++)
	{
		scanf("%d", &num21);
		if (num21 < small)
			small = num21;
	}
	printf("The smallest value of %d is: %d\n", p2, small);

	//part 3
	int num31, num32;
	printf("Enter the size of triangle pattern: ");
	scanf("%d", &num31);
	if (num31 < 0)
		return -2;
	num32 = num31;
	for (int s = 0; s < num31; s++)
	{
		for (int c = 0; c < s; c++)
			printf(" ");
		for (int j = 0; j < num32; j++)
			printf("*");
		printf("\n");
		num32--;
	}

	printf("\nBye!");
	printf("\nThank you for your attention!");
	printf("\nHope you like it!");
	printf("\nWaiting for max points :)\n");
	return 0;
}


