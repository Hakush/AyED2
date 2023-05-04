#include <stdlib.h>
#include <stdio.h>

void absolute(int x, int* y) {
    if (x>= 0) {
        *y = x;
    } else {
        *y = -x;
    }
    
    
}
int main(void) {
    int a=0, res=0;  // No modificar esta declaración
    int* p = NULL;
   
    a = -10;
    p = &res;
    absolute(a,p);
    printf("%d\n",res);

    return EXIT_SUCCESS;
}
/*
El parametro <int* y> es de tipo in/out, ya que se puede usar
a la izquierda y a la derecha de una asignacion

C tiene disponibles parametros in e in/out, ya que a todos
los parametros que le pasemos a una funcion se le pueden
leer su valor, entonces no hay ninguno estrictamente out
*/
