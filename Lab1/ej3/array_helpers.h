#ifndef _ARRAY_HELPERS_H_
#define _ARRAY_HELPERS_H_

// Puts into an array some given numbers from a file
// and returns the length of this array
unsigned int array_from_file(int array[],
							unsigned int max_size,
							const char * filepath);

// Prints the array given in the argument of the function
// Into standard output
void array_dump(int a[], unsigned int length);

#endif