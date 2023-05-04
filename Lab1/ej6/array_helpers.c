/* First, the standard lib includes, alphabetically ordered */
#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

unsigned int array_from_file(int array[],
                             unsigned int max_size,
                             const char *filepath) {

    unsigned int length;

    // Set the file to readable, obtain File Descriptor
    FILE * fd = fopen(filepath,"r");

    // Read first unsigned int of first line and store it in length
    fscanf(fd,"%u",&length);
    assert(length < max_size);

    // Read line jump (previously knowing the input file has one) to 
    // read the next line
    fscanf(fd, "\n");

    // Iterativamente reads ints and blank spaces from a single line
    for (unsigned int i = 0; i < length; ++i)
    {
        fscanf(fd,"%d", &array[i]);
        fscanf(fd, "_");
    }

    // Close File Descriptor now that we already read it
    fclose(fd);

    return length;

}

void array_dump(int a[], unsigned int length) {
    length = length;
    a = a;
    printf("[");
    for (unsigned int i = 0; i < length-1; ++i) {
    printf(" %d,",a[i]);
    }
    printf(" %d]\n",a[length-1]);
    
}

bool array_is_sorted(int a[], unsigned int length) {
    bool sorted = true;
    unsigned int i = 0;
    while (sorted && (i < length-1)) {
        sorted = sorted && (a[i] <= a[i+1]);
        i++;
    }
    return sorted;
}

void array_swap(int a[], unsigned int i, unsigned int j) {
    int aux;
    aux = a[i];
    a[i] = a[j];
    a[j] = aux;
}

void array_inverse(int a[], unsigned int length) {
    unsigned int i,j;
    i = 0;
    j= length-1;
    while(i<j) {
        array_swap(a, i, j);
        i++;
        j--;
    }
}