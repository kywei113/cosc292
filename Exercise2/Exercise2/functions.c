#include <stdio.h>
#include "functions.h"

//Since we pass in pointers to int's rather than the actual int, this is called Indirection.
//In this case, we have one level of indirection
void swap(int* p1, int* p2)
{
	int swap = *p1;
	*p1 = *p2;
	*p2 = swap;
}

void hideString(int* iArrPtr, char* cArrPtr)
{
	char* addr = NULL;

	for(int i = 0; i < ARRAY_SIZE; i++)
	{
		addr = ((char*)(&iArrPtr[i])) + 2;	//Setting the pointer to the address of the 3rd byte of the current integer
		*addr = *(cArrPtr + i);				//Set the value of the pointer
	}
	
}

void unhideString(int* iArrPtr)
{
	char* addr = NULL;

	for (int i = 0; i < ARRAY_SIZE; i++)
	{
		addr = ((char*)(&iArrPtr[i])) + 2;
		printf("%c", *addr);
	}

	//Alternate code
	/*
		char *cPtr = (char*) iArrPtr;	//Create character pointer to intiialize a value
		cPtr += 2;	//Walk the pointer to 3rd byte

		for(int i = 0; i < ARRAY_SIZE; i++)
		{
			printf("%c", *cPtr);	//Print current character
			cPtr += 4;				//Move the pointer to next integer's third byte (adding 1 int's worth of memory space)
		}
	*/
}

int* newInteger()
{
	int iNew = 5555;
	return &iNew;

	/*
		Technically a legal function. Compiler doesn't throw errors, 
		but it's a bad idea to do since once the stack frame is collapsed, 
		if another stack frame is created it could corrupt the
		data held at the previously saved address in memory
	*/
}
