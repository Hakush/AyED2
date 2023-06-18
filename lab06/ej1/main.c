/* First, the standard lib includes, alphabetically ordered */
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "abb.h" /* TAD abb */


void print_help(char *program_name) {
    /* Print the usage help of this program. */
    printf("Usage: %s <input file path>\n\n",
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

abb abb_from_file(const char *filepath) {
    FILE *file = NULL;
    abb read_tree;

    read_tree = abb_empty();
    file = fopen(filepath, "r");
    if (file == NULL) {
        fprintf(stderr, "File does not exist.\n");
        exit(EXIT_FAILURE);
    }
    unsigned int i = 0u;
    unsigned int size = 0u;
    int res = 0;
    res = fscanf(file, " %u ", &size);
    if (res != 1) {
        fprintf(stderr, "Invalid format.\n");
        exit(EXIT_FAILURE);
    }
    while (i < size) {
        abb_elem elem;
        res = fscanf(file," %d ", &(elem));
        if (res != 1) {
            fprintf(stderr, "Invalid array.\n");
            exit(EXIT_FAILURE);
        }
        read_tree = abb_add(read_tree, elem);

       ++i;
    }
    fclose(file);
    return read_tree;
}

int main(int argc, char *argv[]) {
    char *filepath = NULL;

    /* parse the filepath given in command line arguments */
    filepath = parse_filepath(argc, argv);

    /* parse the file to obtain an abb with the elements */
    abb tree = abb_from_file(filepath);

    /*dumping the tree*/
    bool continueB = true;
    int input;
    
    while (continueB) {
        fprintf(stdout, " Ingrese que operacion desea realizar: \n* 1 ........ Mostrar árbol por pantalla \n* 2 ........ Agregar un elemento \n* 3 ........ Eliminar un elemento \n* 4 ........ Chequear existencia de elemento \n* 5 ........ Mostrar longitud del árbol \n* 6 ........ Mostrar raiz, máximo y mínimo del árbol \n* 7 ........ Salir \n ");
        fscanf(stdin, "%d", &input);
        switch (input)
        {
        abb_elem tmp;
        case 1:
            abb_dump(tree);
            printf("\n");
            break;
        case 2:
            fprintf(stdout, "Ingrese el elemento que desea agregar: \n");
            fscanf(stdin, "%d", &tmp);
            tree = abb_add(tree, tmp);
            break;
        case 3:
            fprintf(stdout, "Ingrese el elemento que desea eliminar: \n");
            fscanf(stdin, "%d", &tmp);
            tree = abb_remove(tree, tmp);
            break;
        case 4:
            fprintf(stdout, "Ingrese el elemento que desea saber si existe: \n");
            fscanf(stdin, "%d", &tmp);
            if(abb_exists(tree, tmp)) {
                printf("Existe\n");
            } else {
                printf("No existe\n");
            }
            break;
        case 5:
            fprintf(stdout, "Longitud del arbol: %d\n", abb_length(tree));
            break;
        case 6:
            printf("raiz: %d\n minimo: %d\n maximo: %d\n", abb_root(tree), abb_min(tree), abb_max(tree));
            break;
        case 7:
            tree = abb_destroy(tree);
            continueB = false;
            break;
        
        default:
            break;
        };
    }
    return (EXIT_SUCCESS);
}

/*
La funcion abb_dump se comporta de esta manera porque recorre
el arbol de manera in-order, si agregaramos los elementos en ese orden
obtendriamos un arbol distinto tal que asi: 
root: 1
2: NULL  2
3:          3
                5
                    6
                        7
                            8
                                10
                                    12
                                        15
                                            16
                                                18
                                                    22
*/