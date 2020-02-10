#ifndef DMA_H
#define DMA_H

#define MAX_STRING_SIZE 250
#define MAX_NAME_SIZE 20

//Methods to print an arrayof integers
void printInts(int*, int);

//Return an array of integers that are dynamically allocated
int* getInts(int);

//Add an int to the end of a dynamic array
int* addInt(int*, int*);

//Get a dynamic string
char* getStringDynamic(char*);


//Concatenate two dynamic stings
//No calls to free in this method
//Returns a dynamically allocated string which is the concatenation of the two strings passes in
char* concatenateStrings(char*, char*);

//A function  that creates a buffer with (MAX_NAME_SIZE) and SIN#
char* getNameAndSIN();

//A function to display a name and SIN#
void printNameAndSIN(char*);

#endif	// !DMA_H
