#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include "fileio.h"

//Study errno.h on wikipedia before proceeding
//There is a global variable caled "errno" which is set to indicate any errors
//Also see "strerror" function to get a message which is associated with errno
int demoOpenClose(const char* fileName, const char* fileMode)
{
	//Pointer to a file stream
	FILE* filePtr;

	//a variable to store potential error codes
	int iErr = EXIT_SUCCESS;

	//Use fopen to open a file. Note that it reutrns a FILE pointer
	//If it fails, it returns NULL and sets the errno variable to indicate an error
	//Parameters are a const char* indicating a path/filename
	//and the second is also a chonst char* indicating the mode (read, write, append, text vs binary)
	if ((filePtr = fopen(fileName, fileMode)) != NULL)
	{
		//Close the file when done
		fclose(filePtr);
		printf("%s was successfully opened and closed\n", fileName);
	}
	else	//Failed to open the file
	{
		iErr = errno;
		printf("Error accessing the file %s: %s\n", fileName, strerror(iErr));
	}

	return iErr;
}

int demoRead(const char* fileName, const char* fileMode)
{
	FILE* filePtr;				//Pointer to a file stream
	int iErr = EXIT_SUCCESS;	//Variable for potential exit codes

	int intChar, retVal;		//Creating some buffers (note two variables on one line)
	char cBuffer[MAX_SIZE];

	/*
	All read operations read data from the file to the memory location indicated (cBuffer)
	Only "fgets" adds an additional null terminator to the data in the buffer.
	Return types vary so testing for success depends on the function used.

	fscanf/fread - Return number of times assigned/read, fscanf returns EOF if a failure occurs before the first assignment
	fgets - returns a poitner the the string read or NULL
	fgetc - returns a character or EOF
	*/

	if ((filePtr = fopen(fileName, fileMode)) != NULL)	//Open a file and check if it opened OK
	{
		//How to initialize a buffer
		memset(cBuffer, '\0', MAX_SIZE);	//Remember to multiply MAX_SIZE by your data type size (if it was an int buffer, multiply by 4)

		//Read in from the file stream
		//retVal = fscanf(filePtr, "%s\n", cBuffer);	//Param 1 - Pointer to your stream, Param 2 - How to format data, Param 3 - Where to dump data to
		//fscanf quits at the first space

		//retVal = fgets(cBuffer, MAX_SIZE, filePtr);

		retVal = fread(cBuffer, sizeof(char), 8, filePtr);

		if (retVal > 0)
		{
			printf("%s\n", cBuffer);
		}
		else //Failed to read
		{
			//Tries to retrieve an error number from the file stream
			if (iErr = ferror(filePtr))
			{
				printf("Error reading from the file %s: %s\n", fileName, strerror(iErr));
			}
			else
			{
				printf("Could not retrieve the data\n");
			}
		}

		//Close the file when done
		fclose(filePtr);
		printf("%s was successfully opened and closed\n", fileName);
	}
	else	//Failed to open the file
	{
		iErr = errno;
		printf("Error accessing the file %s: %s\n", fileName, strerror(iErr));
	}

	return iErr;
}

int demoWrite(const char* fileName, const char* fileMode, const char* str)
{
	FILE* filePtr;
	int iErr = EXIT_SUCCESS;
	int retVal;


	if ((filePtr = fopen(fileName, fileMode)) != NULL)
	{
		/*Useful functions
			fwrite	- writes to a file
			fprintf	- similar to printf, but prints out to a file rather than the console
			fputs	- puts in a string
			fputc	- puts in a single char
		*/
		retVal = fwrite((void*)str, sizeof(char), strlen(str), filePtr);

		if (retVal > 0)
		{
			printf("File Written: %s\n", fileName);
		}
		else
		{
			if (iErr = ferror(filePtr))
			{
				printf("Error writing to the file %s: %s\n", fileName, strerror(iErr));
			}
			else
			{
				printf("Could not write the data\n");
			}
		}
		fclose(filePtr);
	}
	else
	{
		printf("Error accessing the file %s: %s", fileName, strerror(iErr));
	}
}

int demoWriteBinary(const char* fileName, const char* fileMode, const int* iPtr)
{
	FILE* filePtr;
	int iErr = EXIT_SUCCESS;
	int retVal;
	
	if ((filePtr = fopen(fileName, fileMode)) != NULL)
	{
		retVal = fwrite((void*)iPtr, sizeof(int), 1, filePtr);

		if (retVal > 0)
		{
			printf("File Written: %s\n", fileName);
		}
		else
		{
			if (iErr = ferror(filePtr))
			{
				printf("Error writing to the file %s: %s\n", fileName, strerror(iErr));
			}
			else
			{
				printf("Could not write the data\n");
			}
		}
		fclose(filePtr);
	}
	else
	{
		printf("Error accessing the file %s: %s", fileName, strerror(iErr));
	}
}

//Exercises
/*Write a function that will write out 3 records worth of information entered by the user.
Each record consists of:
	SIN# (Integer)
	Name (char array of Max_Name_Size)
This information is entered in using scanf and fgets (remember to flush the buffer after the scanf)

After entering a record, write the data out to a binary file
Repeat until 3 records have been written out.
Do some error checking after each write
Close the file

Write code to read in the from the file and display the information contained within

Wait until 11:50 AM
Go for lunch
*/
int exerciseBinaryWrite(const char* fileName, const char* fileMode)
{
	FILE* filePtr;
	int iErr = EXIT_SUCCESS;
	int retVal;
	char cNameBuffer[MAX_NAME_SIZE];
	int ssn = 0;
	short numRecords = 0;

	if ((filePtr = fopen(fileName, fileMode)) != NULL)
	{
		printf("How many records are you entering?\n");
		retVal = scanf("%hi", &numRecords);
		retVal = fwrite((void*)&numRecords, sizeof(short), 1, filePtr);
		getc(stdin);	//Clears the stdin buffer of any hard return characters

		for (int i = 0; i < numRecords; i++)
		{
			printf("Enter a name\n");		//Reading in a name and SSN
			//fgets(cNameBuffer, MAX_NAME_SIZE - 1, stdin);	//Safe way to get a string. It won't stop at first space/character break.
			//However, fgets WILL read in the newline chaaracter and insert it into the string
			//Alternatively, use:
			gets(cNameBuffer);
			printf("Enter a SSN\n");
			retVal = scanf("%d", &ssn);
			retVal = fwrite((void*)&ssn, sizeof(int), 1, filePtr);		//Flipping write order to allow for SSN reading before Name reading
			retVal = fwrite(cNameBuffer, sizeof(char), MAX_NAME_SIZE, filePtr);

			getc(stdin);	//Flush entries to file
		}

		if (retVal > 0)
		{
			printf("File Written: %s\n", fileName);
		}
		else
		{
			if (iErr = ferror(filePtr))
			{
				printf("Error writing to the file %s: %s\n", fileName, strerror(iErr));
			}
			else
			{
				printf("Could not write the data\n");
			}
		}
		fclose(filePtr);
	}
	else
	{
		printf("Error accessing the file %s: %s", fileName, strerror(iErr));
	}
}

//Use fseek to reposition the pointer to the required position
int exerciseBinaryRead(const char* fileName, const char* fileMode, int id)
{
	FILE* filePtr;
	int iErr = EXIT_SUCCESS;
	int retVal;
	char cBuffer[MAX_NAME_SIZE];
	int readSSN = 0;		//SSN that is read in from file
	int count = 0;			//Loop counter
	short numRecords = 0;	//short value read in from head of the file indicating maximum records
	int found = 0;		//Integer flag to indicate if ID was found

	if ((filePtr = fopen(fileName, fileMode)) != NULL)
	{
		retVal = fread((void*)& numRecords, sizeof(short), 1, filePtr);

		while (count < numRecords && !found)
		{
			retVal = fread((void*)&readSSN, sizeof(int), 1, filePtr);
			count++;
			
			if (readSSN == id)	//Checks if read in SSN value is equal to given ID
			{
				found = 1;		//Set found flag to 1/true
				retVal = fread(cBuffer, sizeof(char), MAX_NAME_SIZE, filePtr);	//Read in the name for the record
				printf("Name: %s \t SSN: %d\n", cBuffer, readSSN);	//Print otu the record
			}
			else
			{
				//Moves 20 bytes forward from previous read offset
				retVal = fseek(filePtr, 20, SEEK_CUR);
				if (retVal != 0)
				{
					printf("Error occurred while seeking");
				}
			}
			
		}

		if (!found)
		{
			printf("Record with SIN \"%d\" was not found", id);
		}
		fclose(filePtr);
	}
	else
	{
		printf("Error accessing the file %s: %s", fileName, strerror(iErr));
	}
}