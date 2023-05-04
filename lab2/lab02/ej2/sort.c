#include <assert.h>
#include <stdbool.h>
#include <stdio.h>

#include "array_helpers.h"
#include "sort_helpers.h"
#include "sort.h"


static void quick_sort_rec(int a[], unsigned int izq, unsigned int der) {
    if ((der > izq)) {
    	unsigned int ppiv = partition(a,izq,der);
    	if (ppiv == 0) {
    		quick_sort_rec(a,ppiv+1,der);		
    	} else {
    		//printf("%u\n",ppiv-1u);
    		quick_sort_rec(a,izq,ppiv-1u);
			quick_sort_rec(a,ppiv+1u,der);	
    	}
    }
}

/*
Error segFault
el problema estaba en que si ppiv es 0 y es unsigned, la llamada a quick_sort_rec(a,izq,ppiv-1u) se hace con der = el ultimo numero de los unsigned (4294967295), ya que 0u - 1u no puede dar negativo, da el maximo
del conjunto de los unsigned ints. Luego esto ocasiona que se llame a partition con (a,izq,429...) lo cual termina dando segmentation fault por chequear lugares del arreglo que no estan reservados en memoria
*/

void quick_sort(int a[], unsigned int length) {
    quick_sort_rec(a, 0u, (length == 0u) ? 0u : length - 1u);
    
}

