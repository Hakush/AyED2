#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char *string_clone(const char *str, size_t length) {
    char *clone= calloc(length, sizeof(char));
    for (size_t i=0; i<length; i++) {
        clone[i] = str[i];
    }
    clone[length-1] = '\0';
    return clone;
}


int main(void) {
    char *original=""
         "______ time ago in a galaxy far, far away...\n\n\n"
         "         _______..___________.     ___      .______             \n"
         "        /       ||           |    /   \\     |   _  \\          \n"
         "       |   (----``---|  |----`   /  ^  \\    |  |_)  |          \n"
         "        \\   \\        |  |       /  /_\\  \\   |      /        \n"
         "    .----)   |       |  |      /  _____  \\  |  |\\  \\----.    \n"
         "    |_______/        |__|     /__/     \\__\\ | _| `._____|     \n"
         "                                                                \n"
         "____    __    ____      ___      .______           _______.     \n"
         "\\   \\  /  \\  /   /     /   \\     |   _  \\         /       |\n"
         " \\   \\/    \\/   /     /  ^  \\    |  |_)  |       |   (----` \n"
         "  \\            /     /  /_\\  \\   |      /         \\   \\    \n"
         "   \\    /\\    /     /  _____  \\  |  |\\  \\----..----)   |   \n"
         "    \\__/  \\__/     /__/     \\__\\ | _| `._____||_______/     \n"
         "\n\n\n"
         "                     Episode IV \n\n"
         "                     A NEW HOPE \n\n"
         "                     It is a period of civil war. Rebel\n"
         "spaceships, striking from a hidden base, have won their\n"
         "first victory against the evil Galactic Empire. During the\n"
         "battle, Rebel spies managed to steal secret plans to the\n"
         "Empire’s ultimate weapon, the DEATH STAR, an armored space\n"
         "station with enough power to destroy an entire planet.\n"
         "Pursued by the Empire’s sinister agents, Princess Leia\n"
         "races home aboard her starship, custodian of the stolen\n"
         "plans that can save her people and restore freedom to the\n"
         "galaxy...\n";
    char *copy=NULL;

    printf("size original : %lu\n size char: %lu", sizeof(original), sizeof(char));
    copy = string_clone(original, strlen(original));
    printf("Original: %s\n", original);
    copy[0] = 'A';
    copy[1] = ' ';
    copy[2] = 'l';
    copy[3] = 'o';
    copy[4] = 'n';
    copy[5] = 'g';
    printf("Copia   : %s\n", copy);


    free(copy);

    return EXIT_SUCCESS;
}

/*
    El problema fue que la funcion string_clone estaba usando
    memoria estatica para alojar el string copiado, entonces
    al devolver un puntero que apunta a esa memoria, como es
    estatica, al salir de la funcion apunta a algo que esta free

    cuando se llama a string_clone con 
    length = sizeof(original)/sizeof(char) - 1;
    length toma como valor 8/1 - 1 = 7;
    lo cual no tiene sentido porque no queremos copiar un string
    de 7 caracteres, sizeof(original) devuelve la cantidad de 
    bytes que usa el puntero original, pero deberiamos ver
    cuantos caracteres tiene a lo que apunta original.

    no entiendo el enunciado del apartado c), 
    dice que copiemos clone.c a otro .c pero 
    modificando el tipo de la variable original a char *, 
    pero original ya era de ese tipo, si no me equivoco 
    creo que la idea era probar que pasa si cambiamos 
    original a char original[MAX_SIZE], o original a un
    puntero a memoria dinamica, como no esta especificado
    no lo resuelvo
*/