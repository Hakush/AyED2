#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
#include "stack.h"
 
struct _s_stack_node {
	stack_elem elem;
	struct _s_stack_node * next;
};

struct _s_stack {
	unsigned int size;
	struct _s_stack_node * stack;
};

static bool 
invrep(stack s)
{	
    bool b = (s != NULL);
    if(b)
    {	
        struct _s_stack_node *p = s->stack;
	unsigned int length = 0u;
	while(p != NULL)
	{
	    length = length + 1u;
	    p = p->next;
	}
	b = (s->size == length);
    }
    return(b && s != NULL);
}

stack stack_empty() {
	stack p;
	p = malloc(sizeof(struct _s_stack));
	p->stack = NULL;
	p->size = 0;
	assert(invrep(p));
	return p;
}

stack stack_push(stack p, stack_elem e) {
	assert(invrep(p));
	struct _s_stack_node * d = NULL;
	d = malloc(sizeof(struct _s_stack_node));
	d->elem = e;
	d->next = p->stack;
	p->stack=d;
	p->size = p->size + 1;
	assert(invrep(p));
	return p;
}

stack stack_pop(stack p) {
	assert(invrep(p));
	struct _s_stack_node * s = p->stack;
	if (s != NULL && p->size > 0) {
		struct _s_stack_node * g = s;
		s = s->next;
		free(g);
		p->size = p->size - 1;
		p->stack = s;
	}
	assert(invrep(p));
	return p;
}

unsigned int stack_size(stack s) {
	assert(invrep(s));
	unsigned int aux = s->size;
	assert(invrep(s));
	return aux;
}

stack_elem stack_top(stack s) {
	assert(((s->stack) != NULL) && invrep(s));
	stack_elem aux = (s->stack)->elem;
	assert(invrep(s));
	return aux;
}

bool stack_is_empty(stack s) {
	assert(invrep(s));
	bool aux = (s->stack == NULL) && (s->size == 0);
	assert(invrep(s));
	return aux;
}

stack_elem *stack_to_array(stack p) {
	assert(invrep(p));
	struct _s_stack_node * s = p->stack;
	unsigned int length = stack_size(p);
	stack_elem * array = NULL;
	if (length > 0) {
		array = calloc(length, sizeof(stack_elem));
	}
	while(0 < length) {
		--length;
		array[length] = s->elem;
		s = s -> next; 
	}
	assert(invrep(p));
	return array;
}

stack stack_destroy(stack p) {
	assert(invrep(p));
	struct _s_stack_node * s = p->stack;
	struct _s_stack_node * g = NULL;
	while(s!=NULL) {
		g = s;
		s = s->next;
		free(g);
	}
	free(p);
	return p;
}

void print_stack(stack p) {
	struct _s_stack_node * s = p->stack;
	while(s!=NULL) {
		printf("%d ", s->elem);
		s = s->next;
	}
	printf("\n");
}