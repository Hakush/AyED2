#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 20

int main(void) {
    char user_input[MAX_LENGTH];


    printf("Ingrese su nombre y apellido: ");
    if( fgets(user_input, MAX_LENGTH, stdin) == NULL ) {
        fprintf(stderr, "error\n");
    }

    if (user_input[strlen(user_input)-1] == '\n')
    {
        user_input[strlen(user_input)-1] = '\0';
    }

    printf("Te damos la bienvenida %s a este maravilloso programa!\n", user_input);

    return EXIT_SUCCESS;
}

/*
    Scanf guarda en el string $(str) los elementos que se le pasen
    por teclado sin tener en cuenta el tamaño maximo del string
    e ignorando todo lo que se le pase luego de un espacio

    En cambio fgets va a leer desde una punta de lectura (en este
    caso stdin) la cantidad de elementos que se le pasen como arg.
    incluyendo los espacios y lo que sigue despues de estos

    La unica desventaja es que fgets pone en el ultimo caracter
    del string el simbolo '\n' (si es que se paso por teclado
    menos elementos de los que espera recibir fgets),
    asi que hay que sacarlo manualmente
*/