#ifndef FILEIO_H
#define FILEIO_H

#define MAX_SIZE 100
#define MAX_NAME_SIZE 20
#define NUM_RECORDS 3

int demoOpenClose(const char*, const char*);
int demoRead(const char*, const char*);
int demoWrite(const char*, const char*, const char*);
int demoWriteBinary(const char*, const char*, const int*);


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
int exerciseBinaryWrite(const char* fileName, const char* fileMode);
int exerciseBinaryRead(const char* fileName, const char* fileMode, int id);


#endif