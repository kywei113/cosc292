#include <stdio.h>
#include <stdlib.h>
#include "fileio.h"

void TestOpenClose()
{
	int iErr = demoOpenClose("foo.txt", "r");
	printf("The error number returned was %d\n", iErr);
}

void TestRead()
{
	int iErr = demoRead("foo.txt", "r");
	printf("The error number returned was %d\n", iErr);
}

void TestWrite()
{
	int iErr = demoWrite("foobar.txt", "w", "Hallowurld");
	printf("The error number returned was %d\n", iErr);
}

void TestWriteBinary()
{
	int x = 123456789;
	int iErr = demoWriteBinary("foobar.bin", "wb", &x);

	printf("x in hex is %x\n", x);
	printf("The error number returned was %d\n", iErr);
}

void TestExerciseWrite()
{
	exerciseBinaryWrite("exerciseWrite.bin", "wb");
}

void TestExerciseRead()
{
	int retVal = 0;
	int sin = 0;
	printf("Enter a SIN value to find\n");
	retVal = scanf("%d", &sin);
	exerciseBinaryRead("exerciseWrite.bin", "rb", sin);

}

int main(int ac, char** av)
{
	//TestOpenClose();
	//TestRead();
	//TestWrite();
	//TestWriteBinary();
	TestExerciseWrite();
	TestExerciseRead();

	return EXIT_SUCCESS;
}