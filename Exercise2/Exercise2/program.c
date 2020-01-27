#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

void testHideUnhide()
{
	int iArray[] = { 32842938,9329823,8439339, 7943085 };
	char cArray[] = "Jack";

	//for (int i = 0; i < ARRAY_SIZE; i++)
	//{
	//	printf("%d\n", iArray[i]);
	//}

	hideString(iArray, cArray);

	//Could print out integer array to see how the integers changed after values were hidden
	//for (int i = 0; i < ARRAY_SIZE; i++)
	//{
	//	printf("%d\n", iArray[i]);
	//}

	unhideString(iArray);
}

void testSwap()
{
	int x = 10;
	int y = 20;

	//Figure out how to call swap
	swap(&x, &y);

	//Should print x:20, y:10
	printf("x:%d, y: %d\n", x, y);
}

void testNewInt()
{
	int* iPtr = newInteger();
	//printf("Hello Cruel World\n");	//Causes the previously stored memory address vlaue on the stack to be overwritten
	printf("New Integer: %d\n", *iPtr);
}
int main()
{
	testSwap();
	testNewInt();
	testHideUnhide();

	return EXIT_SUCCESS;
}