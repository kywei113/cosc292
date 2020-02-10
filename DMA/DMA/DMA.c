#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include "DMA.h"

//Methods to print an arrayof integers
void printInts(int* iBufferPtr, int iSize)
{
	int i = 0;
	printf("The integers are: ");

	for (; i < iSize - 1; i++)
	{
		printf("%d, ", *(iBufferPtr++));
	}

	printf("%d\n",*iBufferPtr);
}

/*
	The following function demonstrates how to dynamically allocated memory (DMA)
	Memory allocated dynamically is allocated on the heap.
	It is yours until it is released back to the system
	THERE IS NO GARBAGE COLLECTION
*/
int* getInts(int iNumInts)
{
	/*
		Create a memory space for integers using the function "malloc"
		Malloc takes size of memory in BYTES as a parameter
		It returns a pointer to the first byte of requested memory
		Note - The pointer's type is a (void *). It must be cast to the correct pointer data type
		Contents of the allocated block are not initialized (could use memset)
		A null pointer is returned if the function failed to allocated the requested memory block of memory
	*/

	//For cross platform compatibiltiy, we multiple by sizeof(int), not 4
	int* iBufferPtr = (int*)malloc(iNumInts * sizeof(int));

	
	for (int i = 0; i < iNumInts; i++)
	{
		//Prompt the user for input
		printf("Enter int %d: ", i);
		scanf("%d", iBufferPtr + i);

	}

	return iBufferPtr;

}

/*
	Add an int to the end of a dynamic array
	Takes in an array and increases its size by one.
	Asks the user for an int and adds it to the end.
	iArrayPtr --> The original dynamically alocated array
	iSizePtr --> Pointer to the original size of the array passed in
*/
int* addInt(int* iArrayPtr, int* iSizePtr)
{
	//Create a new array
	int* iNewPtr = (int*)malloc((*iSizePtr + 1) * sizeof(int));

	//Copy data from the old array to the new array using the memcpy function
	memcpy(iNewPtr, iArrayPtr, (*iSizePtr) * sizeof(int));
	
	//You MUST free the old array's memory to avoid a memory leak
	free(iArrayPtr);
	iArrayPtr = NULL;

	//Add an int to the end of the array
	printf("Enter another integer: ");
	scanf("%d", iNewPtr + *iSizePtr);

	//Increment the size
	(*iSizePtr)++;

	return iNewPtr;
}

//Get a dynamic string
//Returns NULL if failure to allocate memory
char* getStringDynamic(char* cPrompt)
{
	//Pointer to a dynamically allocated temporary array
	char* cTempPtr = NULL;

	//Pointer to dynamically allocated array of exact size required
	char* cReturnPtr = NULL;

	//Allocate memory for the temp buffer
	cTempPtr = (char*)malloc(MAX_STRING_SIZE * sizeof(char));

	//Malloc can fail. If it does, it reutnrs null. We should be checking this return value but won't always in class
	if (cTempPtr)
	{
		//Prompt the user for input
		printf("%s", cPrompt);
		//Scan in a string with spaces potentially
		fgets(cTempPtr, MAX_STRING_SIZE, stdin);

		//Allocate a new buffer based on the actual size of the input
		//Always remember to allocate space for the null terminator
		cReturnPtr = (char*)malloc(strlen(cTempPtr) + 1);

		if (cReturnPtr)
		{
			//Copy the data from temp array to the return array
			strcpy(cReturnPtr, cTempPtr);
		}

		free(cTempPtr);
	}

	return cReturnPtr;
}

char* concatenateStrings(char* cFirstPtr, char* cSecondPtr)
{
	char* cReturnPtr = NULL;

	cReturnPtr = (char*)malloc((strlen(cFirstPtr) + strlen(cSecondPtr) + 1) * sizeof(char));

	if (cReturnPtr)
	{
		strcpy(cReturnPtr, cFirstPtr);
		strcpy(cReturnPtr + strlen(cFirstPtr), cSecondPtr);
	}

	return cReturnPtr;
}


//A function  that creates a buffer with (MAX_NAME_SIZE) and SIN#
char* getNameAndSIN()
{
	//Allocate memory for a record
	char* cArray = (char*) malloc(sizeof(char) * MAX_NAME_SIZE + sizeof(int));

	//Read in the name:
	printf("Enter the name: ");
	fgets(cArray, MAX_NAME_SIZE, stdin);

	//fgets reads in a newline character which we might not want
	//You can overwrite it with the null terminator
	cArray[strlen(cArray) - 1] = '\0';

	//Read in the SIN #
	printf("Enter the SIN #: ");
	scanf("%d", (int*)(cArray + MAX_NAME_SIZE));

	return cArray;
}

//A function to display a name and SIN#
void printNameAndSIN(char* cRecordPtr)
{
	printf("The name is %s\n", cRecordPtr);

	//Since cRecordPtr is normally a char*, need to cast to int* so it will read the 4 bytes needed
	printf("The SIN is %d\n", *((int*)(cRecordPtr + MAX_NAME_SIZE)));
}