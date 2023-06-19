#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "string.h"

int main(int argc, char const *argv[])
{
    if (argc < 3 || argc > 3)
    {
        fprintf(stderr, "there must be 2 arguments, ./program <String1> <String2>\n");
        exit(EXIT_SUCCESS);
    }


    string str1 = string_create(argv[1]);
    string str2 = string_create(argv[2]);

    if (string_less(str1, str2))
    {
        fprintf(stdout,"String1 is less than String2\n");
    } else {
        fprintf(stdout,"String1 is not less than String2\n");
    }
    
    if (string_eq(str1,str2)) {
        fprintf(stdout, "String1 is equal to String2\n");
    } else {
        fprintf(stdout, "String1 is not equal to String2\n");
    }
    
    string_destroy(str2);
    string_destroy(str1);

    
    return 0;
}
