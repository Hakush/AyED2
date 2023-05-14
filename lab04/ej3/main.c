/* First, the standard lib includes, alphabetically ordered */
#include <stdio.h>
#include <stdlib.h>

/* Then, this project's includes, alphabetically ordered */
#include "array_helpers.h"
#include "list.h"

/* Maximum allowed length of the array */
static const unsigned int MAX_SIZE = 100000u;

void print_help(char *program_name) {
    /* Print the usage help of this program. */
    printf("Usage: %s <input file path>\n\n"
           "Compute average for the list of numbers in file.\n"
           "\n",
           program_name);
}

char *parse_filepath(int argc, char *argv[]) {
    /* Parse the filepath given by command line argument. */
    char *result = NULL;

    if (argc < 2) {
        print_help(argv[0]);
        exit(EXIT_FAILURE);
    }

    result = argv[1];

    return (result);
}


float average(list l) {
    list laux = copy_list(l);
    unsigned int largo;
    int elem;
    float r = 0.0;
    largo = length_list(l);
    while(!is_empty_list(laux)) {
        elem = head_list(laux);
        r = r + elem;
        laux = tail_list(laux);
    }
    destroy_list(laux);
    r = (( r) / ( largo));

    return r;
}

list array_to_list(int array[], unsigned int length) {
    list l = init_list();
    for (unsigned int i = 0u; i < length; ++i) {
        l = addr_list(array[i],l);
    }
    return l;
}

int main(int argc, char *argv[]) {
    char *filepath = NULL;
    FILE *file = NULL;
    file = file;

    /* parse the filepath given in command line arguments */
    filepath = parse_filepath(argc, argv);

    /* create an array of MAX_SIZE elements */
    int array[MAX_SIZE];

    /* parse the file to fill the array and obtain the actual length */
    unsigned int length = array_from_file(array, MAX_SIZE, filepath);

    /* show the array in the screen */
    printf("Array:\n");
    array_dump(array, length);

    /* transform from array to our list type */
    list l = array_to_list(array, length);

    /* shows that the list is read correctly */
    printf("List:\n");
    print_list(l);

    /* call the average function */
    printf("The average is: %.2f \n", average(l));

    print_list(l);
    l = tail_list(l);
    print_list(l);

    l = destroy_list(l);

    return (EXIT_SUCCESS);
}