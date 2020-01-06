#include <stdio.h>
#include <stdlib.h>
/*
Imports
Similar to "Using" statements found in C#, or "Import" in Java
	- .h extension indicates a Header file.

Tells the pre-processor that there is existing code that we want to utilize within our code

The "<>" brackets tell the pre-processor to look in the built-in standard libraries
We will use "" instead of <> to tell the pre-processor to look in the local project first.

Note that the pre-processor reads the current source file looking for pre-processor directives
	- A Pre-Processor Directive starts with the # symbol
		- #include tells the pre-processor to find stdio.h and substitute its text into this file
	- These do not end with semi-colons so the compiler will ignore them when compiling

Another type of pre-processor directive is the Define statement
	- Define statements also do not end with semi-colons

#define PI 3.14159
#define Radius 2
	- Substitutes 3.14159 for the constant PI, and constant Radius as 2 before any other code is processed

Integers stored as 4 bytes, which contain 8 bits
	- If a byte is divided into two sets of 4 bits, it becomes a "nib" or a "nyb"
	- Each nib can store 16 values, so can represent a hex value
	- x below becomes 00, 01, e2, 40 internally
		- Converting to char only reads last byte, 40, so prints out @ (Hex 40 on ASCII is @)
			- Nib 1 of last byte is 4, Nib 2 of last byte is 0
*/
#define PI 3.14159
#define Radius 2

void PrimativeDataTypes()
{
	char c = 'R';
	int x = 123456;
	float f = PI;	//PI was defined above
	double d = 12345.6597;

	//Print the value of the variables
	//Note the use of the format specifiers that start with %
	printf("The value of c is %c\n", c);	//The format specifier can be changed to adjust how the value of c is displayed
	printf("The value of c in hexadecimal is %x", c);	//Formatting as hexadecimal value
	printf("The value of c as an int is %d\n", c);		//Formatting as an integer
	printf("The value of x is %d\n", x);
	printf("The value of x as a character is %c\n", x);	//Converting x to ASCII character
	printf("The value of x as a character is %x\n", x); //Converting to hex
	printf("The vlaue of f is %f\n", f);

	//Can use the format specifier to modify output. Example: To display 10 digits total with two decimals:
	printf("The value of d is %f\n", d);	//Unformatted
	printf("The value of d formatted is %10.2f\n", d); //%10.2f formats it as 10 spaces with 2 decimals

	//What are the sizes of each data type
	//The sizeof() function is used to return the size of a datatype, struct, array, etc. 
		// - The size returned represents how many bytes the datatype requires
	printf("The size of a char is %d\n", sizeof(c));
	printf("The size of an int is %d\n", sizeof(x));
	printf("The size of a float is %d\n", sizeof(float));	//Can define specific instance of a datatype, or a general datatype
	printf("The size of a double is %d\n", sizeof(d));

}

//Modifiers to the primative datatypes
void Modifiers()
{
	//Originally, C required all variables to be declared at the top.

	//Note that C defaults to signed values
	//"unsigned" --> Positive values only
	unsigned char e = 255;
	signed char c = 127;

	//Short and Long
	short int x;
	short y;	//When using short, it is implied that the variable will be a short int. The int part is optional
	long int z;	//
	long float f;

	//Add one to e and c
	//After adding 1 to each, the value exceeds the max value for the datatype, so the value goes "off the top" and loops back to the lowest possible value
	e = e + 1;
	c += 1;

	/*
	Signed vs Unsigned

	Consider an unsigned char in binary
	1111 1111 = 255
	Adding 1 adds 0000 0001 to the previous
		1111 1111
	+	0000 0001
	= 1 0000 0000

	The resulting 9th bit is ignored as it exceeds the 8 bit limit. System only sees the original 8 bits, so 0000 0000. Results in value of 0

	For a signed char in binary
	1111 1111
	First bit is the Signed Bit. 1 indicates it is negative
	1 | 111 1111

	Convert to decimal values, remember first bit is NEGATIVE
	-128 | 127
	Add both sides
	-128 + 127 = -1
	Therefore, 1111 1111 as a signed value is -1

	So in example, 127 is 0111 1111
	Adding 1 - 0000 0001

	 0111 1111
	+0000 0001
	=1000 0000 = -128
	*/

	//Notice that when we exceed the max values of e and c, the resulting value is dfiferent than expected
	printf("The value of e is %d\n", e);
	printf("The value of c is %d\n", c);

	//Display the size of short and long modifiers
	printf("The size of x and y are %d and %d respecitvely.\n", sizeof(x), sizeof(y));	//Note that a short is 2 bytes in this environment.
	printf("The size of z is %d\n", sizeof(z));	//Long is still only 4 bytes
	printf("The size of f is %d\n", sizeof(f)); //This extends the size of a float to 8 bytes. Note, this may not be allowed in all environments
}

void CastDemo()
{
	int x;
	float y = 3.2;
	float fahr = 32;
	float celc;

	//Assign y to x
	x = (int) y;	//Casting it removes the loss of data error

	printf("The value of x is %d\n", x);
	
	//Temperature Conversion
	printf("The temperature in fahrenheit is %f\n", fahr);
	celc = ((float) 5 / 9) * (fahr - 32);	//Need to cast divided values to float or integer division will round to 0
	printf("The temperature is celcius is %f\n", celc);
}

void DemoConstants()
{
	//Note the keyword "const"
	const float pi = 3.14159;
	
	//const prevents the variable from being later modified
	//pi = pi + 1;	//lvalue means left-hand side value
	printf("Value of pi is %f\n", pi);
}

//Strings in C --> Wait a minute! Strings are objects, but there are no objects in C, so there are no Strings in C (or at least there are no String objects)
//Strings in C are arrays of chars
void StringDemo()
{
	char mychar = 'm';		//Single quotes around a single char
	char sOne[] = "Bill";	//Can initalize a string literal to a char array using double quotes ""
	char sTwo[5];			//Note, the above rule only applies at initialization. Cannot assign using this afterwards
	//sTwo = "John";			//Does not work due to above restriction. Cannot assign a literal string to an initialized char array

	//Char arrays can be changed as such:
	sTwo[0] = 'J';
	sTwo[1] = 'o';
	sTwo[2] = 'h';
	sTwo[3] = 'n';

	printf("The value of string One (sOne) is %s\n", sOne);
	printf("The value of string Two (sTwo) is %s\n", sTwo);

}

int main(void)
{
	//Use printf to output to the console
	//printf("Hello Cruel World\n");

	//PrimativeDataTypes();
	//Modifiers();
	//CastDemo();
	//DemoConstants();
	StringDemo();

	//Normally the C program returns 0 if successful
	return EXIT_SUCCESS;
}
