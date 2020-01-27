#ifndef ARRAY_POINTERS_H_
#define ARRAY_POINTERS_H

#define NAME_SIZE 4
#define AGE_SIZE 1

//Formal argument names are optional in a prototype
void intArrayPrinter(int[], int);
void charArrayPrinter(char[]);

//Example with formal argument names
void intArrayPrinterWithPointers(int* iArrayPtr, int iArraySize);
void charArrayPrinterWithPointers(char* cArrayPtr);
void intBytePrinter(int iValue);
double encode();
void decode(double x);


#endif //!ARRAY_POINTERS_H_