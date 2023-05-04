#include <assert.h>
#include <stdbool.h>
#include <stdio.h>

#include "array_helpers.h"
#include "sort_helpers.h"
#include "sort.h"


static void insert(int a[], unsigned int i) {
    unsigned int j = i;
    while(j>0u && goes_before(a[j],a[j-1])) {
    	swap(a,j,j-1);
    	j = j-1;
    }
}

void insertion_sort(int a[], unsigned int length) {
    for (unsigned int i = 1u; i < length; ++i) {
        assert(array_is_sorted(a,i));
        insert(a, i);
    }
}

/*
Analizar los resultados del programa y responder: ¿Qué relación implementa la función
goes_before()?¿Cuál es el criterio que usa?

La relacion es de orden menor o igual distancia al 0

El criterio que usa es el del valor absoluto de cada numero
*/
