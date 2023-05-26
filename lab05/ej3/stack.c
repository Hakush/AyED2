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

stack stack_empty() {
	stack p;
	p = malloc(sizeof(struct _s_stack));
	p->stack = NULL;
	p->size = 0;
	return p;
}

stack stack_push(stack p, stack_elem e) {
	struct _s_stack_node * d = NULL;
	d = malloc(sizeof(struct _s_stack_node));
	d->elem = e;
	d->next = p->stack;
	p->stack=d;
	p->size = p->size + 1;

	return p;
}

stack stack_pop(stack p) {
	struct _s_stack_node * s = p->stack;
	if (s != NULL && p->size > 0) {
		struct _s_stack_node * g = s;
		s = s->next;
		free(g);
		p->size = p->size - 1;
		p->stack = s;
	}
	return p;
}

unsigned int stack_size(stack s) {
	return s->size;
}

stack_elem stack_top(stack s) {
	assert(((s->stack) != NULL) && (s->size > 0));
	return ((s->stack)->elem);
}

bool stack_is_empty(stack s) {
	return (s->stack == NULL && s->size == 0);
}

stack_elem *stack_to_array(stack p) {
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

	return array;
}

stack stack_destroy(stack p) {
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