#include <stdlib.h>
#include <assert.h>
#include "stack.h"
#include <stdio.h>

struct _s_stack {
    stack_elem *elems;      // Arreglo de elementos
    unsigned int size;      // Cantidad de elementos en la pila
    unsigned int capacity;  // Capacidad actual del arreglo elems
};

static bool invrep(stack p) {
    return (p!= NULL && p->elems != NULL && p->size <= p->capacity);
}

stack stack_empty() {
    stack p;
    p = malloc(sizeof(struct _s_stack));
    p->capacity = 20u;
    p->elems = calloc(p->capacity,sizeof(stack_elem));
    p->size = 0u;
    assert(invrep(p));
    return p;
}

stack stack_push(stack p, stack_elem e) {
    assert(invrep(p));
    if (p->capacity > p->size) {
        (p->elems)[p->size] = e;
        p->size = p->size + 1;
    } else {
        p->elems = realloc(p->elems, 2 * p->capacity * sizeof(stack_elem));
        p->capacity = 2 * p->capacity;
        p = stack_push(p, e);
    }

    assert(invrep(p));
    return p;
}

stack stack_pop(stack p) {
    assert(invrep(p) && p->size > 0);
    --(p->size);
    assert(invrep(p));
    return p;
}

unsigned int stack_size(stack s) {
    assert(invrep);
    unsigned int aux = s->size;
    assert(invrep);
    return aux;
}

stack_elem stack_top(stack s) {
    assert(invrep(s) && s->size > 0u);
    stack_elem aux = (s->elems)[((s->size)-1u)];
    assert(invrep(s));
    return aux;
}

bool stack_is_empty(stack s) {
    assert(invrep(s));
    bool aux = (s->size == 0);
    assert(invrep(s));
    return aux;
}

stack_elem *stack_to_array(stack p) {
    assert(invrep(p));
    stack_elem * aux = p->elems;
    assert(invrep(p));
    return aux;
}

stack stack_destroy(stack p) {
    assert(invrep(p));
    p->size = 0;
    p->capacity = 0;
    free(p->elems);
    return p;
}

void print_stack(stack p) {
    unsigned int i = 0;
    while(i < p->size) {
        printf("%d ", (p->elems)[i]);
        ++i;
    }
    printf("\n");
}