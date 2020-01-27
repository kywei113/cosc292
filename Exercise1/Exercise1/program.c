#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_NAME_SIZE 20

//Author: Kyle Wei - CST234
//Date: January 20, 2020
//Exercise 1


//1A) Defines a set of values and constants to associate with a given enumeration label
//1B) Can print the enum as an integer but not as a string
//1C) Yes, C reads anything that is not 0 as "true".

//enum BOOL { false, true };
//
//void enumerations()
//{
//	int i = 1;
//
//	//Instance of enumeration.
//	enum BOOL done = false;
//
//	do
//	{
//		printf("%d\n", i);
//		i++;
//		if (i > 15)
//		{
//			done = true;
//		}
//
//	} while (!done);
//}

//2
void enter_name(char* cNamePtr, char* cPrompt)
{
	printf("%s ", cPrompt);
	scanf("%10s", cNamePtr);
}

void test_enter_name()
{
	char cFirstName[MAX_NAME_SIZE];
	char cLastName[MAX_NAME_SIZE];

	enter_name(cFirstName, "Enter a first name:");
	enter_name(cLastName, "Enter a last name:");

	printf("First Name: %s\n", cFirstName);
	printf("Last Name: %s\n", cLastName);
}

void string_funcs()
{
	char string1[] = "Hello World";
	char string2[] = "You are great";
	char string3[40];
	char string4[] = "Bob";

	//strlen - lenggth of string without the null terminator
	printf("The length of string1 is %d\n", strlen(string1));

	//For fun, overwrite the null termiator of string 4
	//string4[3] = '1';	//Don't normally do this, strlen will return unpredicatble results
	printf("Length of string4 is: %d\n", strlen(string4));

	//strcpy - Parameters: First is destination, second is source
	//Stirng3 contains 40 spaces, unused space is still reserved
	//Note that the destination string's null terminator is copied over
	strcpy(string3, string1);
	printf("String3 = %s\n", string3);
	strcpy(string3, string2);
	printf("String3 = %s\n", string3);

	//strcat - Concatenates th etwo strings
	strcat(string3, " ");
	strcat(string3, string1);
	strcat(string3, " ");
	strcat(string3, string2);
	printf("%s\n", string3);

	//strcmp returns 0 if equal
	//Resassign string3 to an empty
	string3[0] = '\0';
	strcpy(string3, string1);

	if (strcmp(string3, string1) == 0)
	{
		printf("Equal\n");
	}
	else
	{
		printf("Not equal");
	}


	//printf("%d\n", strlen("Test String"));	//Returns the size of a given string as size type (size of total chars?)

	//char copyString[] = "Copy Me!";
	//char destString[sizeof(copyString) + 2];	//Need to allocate enough size for destString otherwise it will overflow to other memory spots. Add two for \0
	//strcpy(destString, copyString);
	//printf("Copied String: %s\n", destString);

	//char firstPart[] = "Add to";
	//char lastPart[] = "me!";
	//char final[sizeof(firstPart) + sizeof(lastPart)] = "";

	//strcat(final, firstPart);
	//printf("Concatenated String: %s\n", final);

	//strcat(final, " ");
	//printf("Concatenated String: %s\n", final);

	//strcat(final, lastPart);
	//printf("Concatenated String: %s\n", final);

	//char strOne[] = "I'm a string";
	//char strTwo[] = "I'm also a string";
	//char strThree[] = "I'm a string";

	//int cmpResult = strcmp(strOne, strTwo);

	//if (cmpResult == 0)
	//{
	//	printf("Equal\n");
	//}
	//else
	//{
	//	if (cmpResult > 0)
	//	{
	//		printf("First is larger than second\n");
	//	}
	//	else
	//	{
	//		printf("First is smaller than second\n");
	//	}
	//}

	//cmpResult = strcmp(strOne, strThree);

	//if (cmpResult == 0)
	//{
	//	printf("Equal");
	//}
	//else
	//{
	//	if (cmpResult > 0)
	//	{
	//		printf("First is larger than second\n");
	//	}
	//	else
	//	{
	//		printf("First is smaller than second\n");
	//	}
	//}
}

void string_cat(char* leftPtr, char* rightPtr)
{
	int i = 0;

	//Create a pointer that points to the destination
	//Use pointer math to determine this position
	char* appendPtr = leftPtr + strlen(leftPtr);
	
	//Use a loop to copy characters over (can use strcpy)
	//Make sure your loop copies the null terminator
	do
	{
		appendPtr[i] = rightPtr[i];
	} while (rightPtr[i++] != '\0');

	//My stuff
	//int finalSize = sizeof(leftPtr) + sizeof(rightPtr) + 2;

	//printf("%d\n", finalSize);
}

void test_string_cat()
{
	char left[] = "Hello";
	char right[] = "World";
	char concat[20];

	concat[0] = '\0';

	string_cat(concat, left);
	string_cat(concat, " ");
	string_cat(concat, right);


	printf("%s\n", concat);

}

int main(int ac, char** av)
{
	//enumerations();
	//test_enter_name();
	//string_funcs();
	test_string_cat();

	return EXIT_SUCCESS;
}
