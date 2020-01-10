#include <stdio.h>
#include "pingpong.h"

void ping()
{
	printf("Ping\n");
	pong();
}

void pong()
{
	static int iCount = 0;

	iCount++;

	printf("Pong\n");
	if (iCount < 10)
	{
		ping();
	}
}