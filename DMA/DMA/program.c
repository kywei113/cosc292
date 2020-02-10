#include <stdio.h>
#include <stdlib.h>
#include "DMA.h"


void TestPrintInts()
{
	int iArray[] = { 12, 37, 21 };
	printInts(iArray, 3);
}

void TestIntDMA()
{
	int iSize = 3;
	int* iBufferPtr = getInts(iSize);
	printInts(iBufferPtr, iSize);

	//Demo buffer overflow - Results may be unpredicatble if you overflow
	//Sometimes you might get an error message but it is not guaranteed
	//It is up to you to stay within the bounds of your allocated memory

	//iBufferPtr[4] = 9;
	//printInts(iBufferPtr, iSize + 2);

	//Add an integer to then ed of the existing array
	iBufferPtr = addInt(iBufferPtr, &iSize);
	printInts(iBufferPtr, iSize);

	//Once done with dynamically allocated memory, free it using the "free" function
	//Note that in release mode, the data is sometimes still there
	free(iBufferPtr);

	//Address still exists after being freed, but prior data is gone
	//printInts(iBufferPtr, iSize);

	//Note, you may want to overwrite (memset) if it the addresses contain sensitive data before freeing

	//Set your pointers to NULL after freeing
	iBufferPtr = NULL;	
}

void TestDynamicString()
{
	char* cFirstPtr = NULL;
	char* cLastPtr = NULL;


	//Read in names
	cFirstPtr = getStringDynamic("Enter first name: ");
	cLastPtr = getStringDynamic("Enter last name: ");

	if (cFirstPtr)
	{
		printf("The first name is %s\n", cFirstPtr);
		//free(cFirstPtr);
		//cFirstPtr = NULL;
	}

	if (cLastPtr)
	{
		printf("The last name is %s\n", cLastPtr);
		//free(cLastPtr);
		//cLastPtr = NULL;
	}


}

void TestStringConcat()
{
	char* cCatPtr = NULL;

	cCatPtr = concatenateStrings("Hello ", "World");
	if (cCatPtr)
	{
		printf("Combined they make %s\n", cCatPtr);
	}
	free(cCatPtr);
	cCatPtr = NULL;
}

void TestGetNameAndSIN()
{
	char* cRecord = getNameAndSIN();
	printNameAndSIN(cRecord);

	free(cRecord);
	cRecord = NULL;
}


int main(int ac, char** av)
{
	//TestPrintInts();
	//TestIntDMA();
	//TestDynamicString();
	//TestStringConcat();
	TestGetNameAndSIN();

	return EXIT_SUCCESS;
}
