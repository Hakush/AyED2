#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#include "array_helpers.h"
#include "sort_helpers.h"
#include "sort.h"


static unsigned int partition(int a[], unsigned int izq, unsigned int der) {
    int pivot = a[izq];
    unsigned int ppiv = izq;
    unsigned int i = izq+1;
    unsigned int j = der;
    while(i <= j) {
    	if (goes_before(a[i],pivot) || pivot == a[i]) {
			i++;
    	} else if((goes_before(pivot,a[j]) || pivot == a[j]) && j>0) {
    		j--;
    	} else if( goes_before(pivot,a[i]) && goes_before(a[j],pivot) ) {
    		swap(a,i,j);
    	}
    }
    
    swap(a,ppiv,j);
    ppiv = j;
    
    return ppiv;

    /* Permutes elements of a[izq..der] and returns pivot such that:
     - izq <= pivot <= der
     - elements in a[izq,pivot) all 'go_before' (according to function goes_before) a[pivot]
     - a[pivot] 'goes_before' all the elements in a(pivot,der]
    */
}

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
    quick_sort_rec(a, 0, (length == 0) ? 0 : length - 1);
}

