// gcc -Wall -Wextra -Werror -pedantic -std=c99 -c bounds.c
// gcc -Wall -Wextra -Werror -pedantic -std=c99 bounds.o -o bounds
// ./bounds

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#define ARRAY_SIZE 4

struct bound_data {
    bool is_upperbound;
    bool is_lowerbound;
    bool exists;
    unsigned int where;
};

struct bound_data check_bound(int value, int arr[], unsigned int length) {
    struct bound_data res;
    bool upper = true;
    bool down = true;
    bool exists = false;
    unsigned int where = ARRAY_SIZE + 500;
    

    for (unsigned int i = 0; i < length; i++) {
        
        upper = upper && (arr[i] <= value);
        down = down && (arr[i] >= value);
        exists = exists || (arr[i] == value);
        if ((arr[i] == value)) {
            where = i;
        }

    }

    res.is_upperbound = upper;
    res.is_lowerbound = down;
    res.exists = exists;
    res.where = where;
    
    return res;
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

int main(void) {
    int a[ARRAY_SIZE] = {0, -1, 9, 4};
    int value=9;
    
    for (int i = 0; i < ARRAY_SIZE; i++) {
            printf("Ingresa el valor %d del arreglo: \n", i);
            scanf("%d",&a[i]);
        }

    array_dump(a,ARRAY_SIZE);

    printf("Ingrese un valor para check_bound: \n");
    scanf("%d", &value);
        
    
    struct bound_data result = check_bound(value, a, ARRAY_SIZE);

    // TODO: REEMPLAZAR LO SIGUIENTE LUEGO POR LA SALIDA QUE PIDE EL ENUNCIADO
    printf("---------------------------------\n1=True;0=False\n");
    printf("Es cota superior: %d\n", result.is_upperbound); // Imprime 1
    printf("Es cota inferior: %d\n", result.is_lowerbound); // Imprime 0
    printf("Esta incluido en el arreglo: %u\n", result.exists);        // Imprime 1
    printf("Si esta incluido, esta en la posicion: %u\n", result.where);         // Imprime 2 

    return EXIT_SUCCESS;
}

