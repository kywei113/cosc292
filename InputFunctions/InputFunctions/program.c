#include <stdio.h>
#include <string.h>



//Note the declaration of a pointer. In C it uses a *
void PrintString(char* cPtr);
void ReadString(char* cPtr, char* cLengthPtr);
void ReadNumbers(int* iPtr);
void PrintNumbers(int* iPtr, int iSize);
void ReadStringGets(char* cPtr);
char* ReadStringReturnBuffer();


int main()
{

	//Create a buffer to put data into
	char cArray[10];
	char cArray2[10];
	char cBuffer[255];

	//Test 1 - Use scanf to input a string
	//ReadString(cArray, "8");
	//PrintString(cArray);

	//Test 2 - scanf with multiple values
	//The format specifier specifies two strings in this case
	//scanf("%4s %4s", cArray, cArray2);
	//PrintString(cArray);
	//PrintString(cArray2);

	////Must calculate the size of the array if we need it
	//int iSizeOfiArray = sizeof(iArray) / sizeof(int);	//Overall size of array divided by size of a single instance of data
	//ReadNumbers(iArray);
	//PrintNumbers(iArray, iSizeOfiArray);

	//Test 4 - Using gets
	//ReadStringGets(cBuffer);
	//PrintString(cBuffer);

	//Test 5 - Returning an array (buffer)
	char* cPtr = ReadStringReturnBuffer();
	printf("%s\n", cPtr);
	PrintString(cPtr);

	return 0;
}


char* ReadStringReturnBuffer()
{
	//When alocating a buffer on the call stack, the address SHOULD NOT BE RETURNED
	//This memory space will be overwritten and using the return address will result in weird data
	//The solution is to pass the buffer address in as an address OR dynamically allocate memory on the heap
	char cBuffer[256];

	gets(cBuffer);

	return cBuffer;
}

void ReadStringGets(char* cPtr)
{
	int x = 0;
	printf("Enter an int: ");
	scanf("%d", &x);

	//Note that scanf does NOT read the \n from stdin buffer. It leaves it there.
	//gets reads up to a newline \n. So it seems the leftover \n in buffer and immediately quits
	//Should be able to flush the buffer using fflush(stdin)
	//Fix --> Read the \n using a different function
	getc(stdin); 

	printf("Enter a big honkin' string:\n");
	gets(cPtr);
	//Note that is not a safe version of the function. You could overflow the buffer
	//The following is the safe version:
	//gets_s(cPtr, 9);
	//fgets(cPtr, 10, stdin);

}
void ReadNumbers(int* iPtr)
{
	printf("enter your numbers: \n");

	//Note that scanf returns the number of reads that were successful
	//If it returns 0, it will exit out of the loop
	//0 is False in C, not 0 is True
	//There is no Boolean in C
	while (scanf("%d", iPtr))
	{
		//Must do Pointer math to increment the pointer to the next int
		//NOTE: ++ adds "one integer" or 4 bytes 
		iPtr++;
	}

}

void PrintNumbers(int* iPtr, int iSize)
{
	//Cannot calculate sizeof an array based on the pointer. sizeof returns the pointer's size (4), not the array
	//int iSizeofiPtr = sizeof(iPtr) / sizeof(int);

	//Changed function signature to take the size of the array as an argument. The size MUST be passed in

	for (int i = 0; i < iSize; i++)
	{
		printf("%d\n", iPtr[i]);	//Pointers can be treated as Arrays in C. Pointer is pointing to an Array memory address
	}
	
}

void PrintString(char* cPtr)
{
	printf("%s\n", cPtr);
}

void ReadString(char* cPtr, char* cLengthPtr)
{
	char cFormat[4];

	//Initialize and empty string
	cFormat[0] = '\0';

	//Use string concatenation to build up the format specifier
	strcat(cFormat, "%");
	strcat(cFormat, cLengthPtr);
	strcat(cFormat, "s");

	printf("Enter a string:\n");

	//scanf will read a string in this case. It will be null terminated
	//scanf will only read up until the first space. Enterign a string with spaces will read as multiple strings, space delimited
	//Adding numbers in front of the s in %s will restrict input to the number of characters not including the null terminator
	scanf(cFormat, cPtr);
}

