#ifndef FILEIO_H
#define FILEIO_H

#define MAX_SIZE 100
#define MAX_NAME_SIZE 20
#define NUM_RECORDS 3

int demoOpenClose(const char*, const char*);
int demoRead(const char*, const char*);
int demoWrite(const char*, const char*, const char*);
int demoWriteBinary(const char*, const char*, const int*);

#endif