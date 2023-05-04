#include <stdlib.h>
#include <stdio.h>

#define MAX_SIZE 1000

static void dump(char a[], unsigned int length) {
    printf("\"");
    for (unsigned int j=0u; j < length; j++) {
        printf("%c", a[j]);
    }
    printf("\"");
    printf("\n\n");
}

unsigned int
data_from_file( const char *path,
                unsigned int indexes[],
                char letters[],
                unsigned int max_size) {
	unsigned int i = 0;
    unsigned int aux;

    FILE* fd = fopen(path,"r");
    if (fd == NULL) {
        fprintf(stderr, "File does not exist.\n");
        exit(EXIT_FAILURE);
    }
	
	while (!feof(fd) && i < max_size) {

        aux = fscanf(fd, "%u -> *%c* \n", &indexes[i], &letters[i]);
        if (aux != 2) {
            fprintf(stderr,"Incorrect format readed, expected: (unsigned int) -> *(char)*\n");
            exit(EXIT_FAILURE);
        }

        ++i;
	}
	
	fclose(fd);
	
	return i;
}

void
sort_data_from_file(unsigned int indexes[],
                    char letters[],
                    unsigned int length,
                    char sorted[]) {

    unsigned int i = 0;

    while(i < length) {
        if (indexes[i] < MAX_SIZE) {
            sorted[indexes[i]] = letters[i];
        } else {
            fprintf(stderr,"Index %u is too big, max index allowed is %d\n", indexes[i], MAX_SIZE-1);
            exit(EXIT_FAILURE);
        }
        i++;
    }
}

int main(int argc, const char* argv[]) {
    //FILE *file;
    if (argc < 2) {
        fprintf(stderr, "Too few arguments, enter at least 2\n for example: ./main uwu.txt\n");
        return EXIT_FAILURE;
    }
    unsigned int indexes[MAX_SIZE];
    char letters[MAX_SIZE];
    char sorted[MAX_SIZE];
    argc = argc;
    unsigned int length=0; 
    //  .----------^
    //  :
    // Debe guardarse aqui la cantidad de elementos leidos del archivo
    
    length = data_from_file(argv[1],indexes,letters,MAX_SIZE);

    sort_data_from_file(indexes, letters, length, sorted);

    dump(sorted, length);

    return EXIT_SUCCESS;
}

