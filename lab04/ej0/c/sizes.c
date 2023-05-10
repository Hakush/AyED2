#include <stdio.h>
#include <stdlib.h>

#include "data.h"

void
print_data(data_t d) {
    printf("NOMBRE: %s\n"
           "EDAD  : %d años\n"
           "ALTURA: %d cm\n\n",
           d.name, d.age, d.height);
}

int main(void) {

    data_t messi = {"Leo Messi", 35, 169};
    print_data(messi);

    printf("name-size  : %lu bytes\n"
           "age-size   : %lu bytes\n"
           "height-size: %lu bytes\n"
           "data_t-size: %lu bytes\n",  sizeof(messi.name), 
                                        sizeof(messi.age), 
                                        sizeof(messi.height),
                                        sizeof(messi));

    return EXIT_SUCCESS;
}

/* -----------------------Rtas----------------------------------------- 
-El tamaño del struct (40 bytes) no coincide con la suma del tamaño de
 sus campos (38 bytes)

-El tamaño del campo name no depende del nombre que contiene, ya que
esta definido como un array de maximo NAME_MAXSIZE caracteres,y al declarar 
el arreglo siempre se usa memoria para NAME_MAXSIZE caracteres (30 bytes)
 -------------------------------------------------------------------- */

