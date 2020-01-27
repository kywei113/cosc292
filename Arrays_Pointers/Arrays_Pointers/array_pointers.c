#include <stdio.h>
#include "array_pointers.h"


void intArrayPrinter(int iArray [], int iArraySize)
{
	//Note that the array is passed in as a pointer. If we do sizeof(iArray) it will now return the size of the pointer (4), not the sizeof the array's data
	for (int i = 0; i < iArraySize; i++)
	{
		printf("The value of loop counter is %d and the array value is %d\n", i, iArray[i]);
	}
}

void intArrayPrinterWithPointers(int* iArrayPtr, int iArraySize)
{
	for (int i = 0; i < iArraySize; i++)
	{
		//To retrieve the value where a pointer points, we "dereference" it using the deference operator (*)
		printf("The value of loop counter is %d and the array value is %d\n", i, *(iArrayPtr + i));	//This statement is same as the previous one in intArrayPrinter
		//"[ ]" are used to offset and deference

		//Alternatively, we can "walk the pointer". The pointer now points just past the end of the array when the loop is done
		//printf("The value of loop counter is %d and the array value is %d\n", i, *iArrayPtr++);
	}
}

void charArrayPrinter(char cArray [])
{

}

void charArrayPrinterWithPointers(char* cArrayPtr)
{
	printf("The address of cArrayPtr is %x\n", &cArrayPtr);		//Gets address stored in text segment
	printf("The address stored by cArrayPtr is %x\n", cArrayPtr);	//Gets address passed into function
	printf("The address of charArrayPrinterWithPointers is %x\n", charArrayPrinterWithPointers);	//Gets address of the function

	//note that the address was passed in was that of a string literal. This string literal is located in the "Text Segment"
	//It is OK to go to the text segment to get a value, but you should not manipulate values there
	while (*cArrayPtr)	//Remember, any value other than 0 is true, 0 is false
	{
		printf("%c", *cArrayPtr++);
	}
}

void intBytePrinter(int iValue)
{
	//Creating a smaller "knife" 
	char* cPtr = (char*)&iValue;
	int size = sizeof(iValue);

	for (int i = 0; i < size; i++)
	{
		printf("The byte value is %x and the char equivalent is %c\n", *cPtr, *cPtr);
		cPtr++;
	}
}

//Encode a 3 letter name, an age, and an amount for a student loan
//Note that this can all be stored in a double
double encode()
{
	//Allocate the buffer
	double x = 0;
	char* cNamePtr = (char*)&x;

	//Prompt the user for input
	printf("Enter a 3 letter name: ");
	scanf("%3s", cNamePtr);

	//Enter the age of the person
	printf("Enter your age: ");
	scanf("%d", (int*)(cNamePtr + NAME_SIZE));

	//Enter the amount for the student loan
	printf("Enter your student loan: ");
	scanf("%hu", (short*)(cNamePtr + NAME_SIZE + AGE_SIZE));

	//Return the buffer
	return x;
}

void decode(double x)
{
	//Pointer to the name
	char* cNamePtr = (char*)&x;
	short* loanPtr = (short*)(cNamePtr + NAME_SIZE + AGE_SIZE);

	//Print the encoded information from the passed in double
	printf("The name is %s \n", cNamePtr);

	//Note that the age is stored in one byte. Therefore can leave it as a char pointer for deferencing
	//Converting it to an int pointer will cause it to read 4 bytes, more than we want
	printf("The age is %d \n", *(cNamePtr + NAME_SIZE));

	//Print the student loan
	printf("The student loan is %hu \n", *loanPtr);
}
