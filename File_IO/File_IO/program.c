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

int main(int ac, char** av)
{
	//TestOpenClose();
	TestRead();
	return EXIT_SUCCESS;
}