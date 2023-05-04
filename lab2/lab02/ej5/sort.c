#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#include "array_helpers.h"
#include "sort_helpers.h"
#include "sort.h"
#include "fixstring.h"


static unsigned int partition(fixstring a[], unsigned int izq, unsigned int der) {
    char* pivot = a[izq];
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
}

static void quick_sort_rec(fixstring a[], unsigned int izq, unsigned int der) {
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

void quick_sort(fixstring a[], unsigned int length) {
    quick_sort_rec(a, 0, (length == 0) ? 0 : length - 1);
}


