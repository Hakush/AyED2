/*
  @file sort.c
  @brief sort functions implementation
*/

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include "helpers.h"
#include "sort.h"
#include "player.h"

bool goes_before(player_t x, player_t y){
    bool res = false;
    if (x->rank <= y->rank) {
        res = true;
    }
    return res;
}

bool array_is_sorted(player_t atp[], unsigned int length) {
    unsigned int i = 1u;
    while (i < length && goes_before(atp[i - 1u], atp[i])) {
        i++;
    }
    return (i == length);
}

static void swap(player_t a[], unsigned int i, unsigned int j) {
    player_t aux;
    aux = a[i];
    a[i] = a[j];
    a[j] = aux;
}

static unsigned int 
partition(player_t a[], unsigned int izq, unsigned int der)
{
    unsigned int ppiv = izq;
    unsigned int i = izq + 1u;
    unsigned int j = der;
    while(i <= j)
    {
        if(goes_before(a[i], a[ppiv]))
        {
            i = i + 1u;
        }
        else if(goes_before(a[ppiv], a[j]))
        {
            j = j - 1u;
        }
        else if(goes_before(a[ppiv], a[i]) && goes_before(a[j], a[ppiv]))
        {
            swap(a, i, j);
            i = i + 1u;
            j = j - 1u;
        }
    }
    swap(a, ppiv, j);
    ppiv = j;
    return ppiv;
}

static void 
quick_sort_rec(player_t a[], unsigned int izq, unsigned int der)
{
    if(der > izq)
    {
        unsigned int ppiv = partition(a, izq, der);
        quick_sort_rec(a, izq, ppiv == 0u ? 0u : ppiv - 1u);
        quick_sort_rec(a, ppiv+1, der);
    }
}

static void 
quick_sort(player_t a[], unsigned int length) 
{
    quick_sort_rec(a, 0u, (length == 0u) ? 0u : length - 1u);
}

void sort(player_t a[], unsigned int length) {
    quick_sort(a,length);
}

// Funciona mas rapido la version con punteros, pasamos de ~0.005000 cpu time a ~0.002000 cpu time
// Los intercambios son mas eficientes porque cambian dos direcciones de memoria y no dos valores apuntados por esas direcciones 

// LLama a destroy para que no quede reservada memoria que ha llamado este programa de ningun tipo, ya que queremos que al terminar el programa no se use mas y quede libre.