#include <stdio.h>
#include <stdlib.h>
#include "array_pointers.h"

void TestIntArray()
{
	int iArray[] = { 2, 7, 9 };
	
	//Calculate the size of the array
	int iArraySize = sizeof(iArray) / sizeof(int);
	//intArrayPrinter(iArray, iArraySize);
	intArrayPrinterWithPointers(iArray, iArraySize);
}

void TestCharArrayPrinter()
{
	charArrayPrinterWithPointers("Hello Cruel World");
}

void TestIntBytePrinter()
{
	int x = 6451026;
	intBytePrinter(x);
}

void TestEncodeDecode()
{
	double x = encode();
	decode(x);
}

int main()
{
	//TestIntArray();
	//TestCharArrayPrinter();
	//TestIntBytePrinter();
	TestEncodeDecode();

	return EXIT_SUCCESS;
}