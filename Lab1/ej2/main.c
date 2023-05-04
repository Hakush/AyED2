/* Compile */
/* gcc -Wall -Werror -Wextra -pedantic -std=c99 main.c -o ej2 */
/* ./ej2 */

/* First, the standard lib includes, alphabetically ordered */
#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

/* Maximum allowed length of the array */
#define MAX_SIZE 100000

unsigned int array_from_STDIN(int array[],
                             unsigned int max_size) {

    unsigned int length;

    // Set the file to readable, obtain File Descriptor
    //FILE * fd = fopen(filepath,"r");

    // Read first unsigned int of first line and store it in length
    fprintf(stdout, "Ingrese the array length and press enter\n");
    fscanf(stdin,"%u",&length);
    assert(length < max_size);

    // Iterativamente reads ints and blank spaces from a single line
    fprintf(stdout, "Ingrese los elementos del arreglo con un espacio entre ellos y presione anter\n");
    for (unsigned int i = 0; i < length; ++i)
    {
        fscanf(stdin,"%d", &array[i]);
        fscanf(stdin, "_");
    }

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

int main(int argc, char *argv[]) {
    argc = argc;
    argv = argv;
    
    /* create an array of MAX_SIZE elements */
    int array[MAX_SIZE];
    
    /* parse the file to fill the array and obtain the actual length */
    unsigned int length = array_from_STDIN(array, MAX_SIZE);
    
    /*dumping the array*/
    array_dump(array, length);
    
    return EXIT_SUCCESS;
}
