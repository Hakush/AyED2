#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
#include "stack.h"
 
struct _s_stack {
	stack_elem elem;
	stack next;
};

stack stack_empty() {
	stack p;
	p = NULL;
	return p;
}

stack stack_push(stack s, stack_elem e) {
	stack d = NULL;
	d = malloc(sizeof(struct _s_stack));
	d->elem = e;
	d->next = s;
	s=d;
	return s;
}

stack stack_pop(stack s) {
	if (s != NULL) {
		stack g = s;
		s = s->next;
		free(g);
	}
	return s;
}

unsigned int stack_size(stack s) {
	unsigned int length = 0;
	while(s != NULL)
	{
		length = length + 1;
		s = s->next;
	}
	return(length);
}

stack_elem stack_top(stack s) {
	assert(s!=NULL);
	return s->elem;
}

bool stack_is_empty(stack s) {
	return (s == NULL);
}

stack_elem *stack_to_array(stack s) {
	unsigned int length = stack_size(s);
	stack_elem * array = NULL;
	if (length > 0) {
		array = calloc(length, sizeof(stack_elem));
	}
	while(0 < length) {
		--length;
		array[length] = stack_top(s);
		s = s -> next; 
	}

	return array;
}

stack stack_destroy(stack s) {
	stack g = NULL;
	while(s!=NULL) {
		g = s;
		s = s->next;
		free(g);
	}
	return s;
}

void print_stack(stack s) {
	while(s!=NULL) {
		printf("%d ", s->elem);
		s = s->next;
	}
	printf("\n");
}