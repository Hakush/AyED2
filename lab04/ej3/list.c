#include <stdlib.h>  /* EXIT_SUCCESS... */
#include <stdio.h>   /* printf()...     */
#include <assert.h> /* assert()... */

#include "list.h"    /* TAD List         */

struct node {
	list_elem elem;
	list next;
};

/*------ Constructors -------*/
list init_list(void) {
	list l;
	l = NULL;
	return l;
}

list addl_list(list_elem e, list l) {
	list d = NULL;
	d = malloc(sizeof(struct node));
	d->elem = e;
	d->next = l;
	l=d;
	return l;
}

/*------ Operations -------*/
bool is_empty_list(list l) {
	return (l == NULL);
}

list_elem head_list(list l) {
	assert(l != NULL);
	return (l->elem);
}

list tail_list(list l) {
	if (l != NULL) {
		list g = l;
		l = l->next;
		free(g);
	}
	return l;
}

list addr_list(list_elem e, list l) {
	list d = l;
	if (l == NULL) {
		list g = malloc(sizeof(struct node));
		g->elem = e;
		g->next = NULL;
		l = g;
	} else {
		while(d->next != NULL) {
			d = d->next;
			}
		list f = malloc(sizeof(struct node));
		f->elem = e;
		f->next = NULL;
		d->next = f;
	}

	return l;

}

unsigned int length_list(list l) {
	unsigned int n = 0;
	while(l != NULL) {
		n = n + 1;
		l = l->next;
	}

	return n;
}

list concat_list(list l, list d) {
	list f = l;
	while(f->next != NULL) {
		f = f-> next;
	}
	f->next = d;

	return l;
}

list_elem index_list(list l, unsigned int pos) {
	assert((l != NULL) && (0u < pos && pos <= length_list(l)));
	unsigned int i = 1;
	int res = l->elem;
	while(i < pos) {
		l = l->next;
		res = l->elem;
		i = i + 1;

	}

	return res;
}

list take_list(list l, unsigned int n) {
	assert(l!=NULL && 0 < n && n <= length_list(l));
	list d = l;
	unsigned int i = 1;
	while((i < n) && (d->next != NULL)) {
		d = d->next;
		i = i + 1;
	}

	list f = d->next;
	list g = NULL;
	while(f!=NULL) {
		g = f;
		f = f->next;
		free(g);
	}

	d->next = NULL;

	return l;
}

list drop_list(list l, unsigned int n) {
	assert(l != NULL && 0u < n && n <= length_list(l));
	list d = l;
	unsigned int i = 1;
	while(i < n) {
		d = d->next;
		i = i + 1;
	}

	list g = NULL;
	while(l != d) {
		g = l;
		l = l->next;
		free(g);
	}

	l = d->next;

	return l;
}

list copy_list(list l) {
	assert(!is_empty_list(l));
	list copy = NULL;
	copy = malloc(sizeof(struct node));
	copy->elem = l->elem;

	list f = copy;
	while(l!=NULL) {
		copy->elem = l -> elem;
		if (l->next != NULL)
		{
		(*copy).next = malloc(sizeof(struct node));
		copy = copy->next;
		}
		l = l->next;
	}

	copy->next = NULL;
	copy = f;

	return copy;
}

list destroy_list(list l) {
	list g = NULL;
	while(l!=NULL) {
		g = l;
		l = l->next;
		free(g);
	}
	return l;
}

void print_list(list l) {
	while(l!=NULL) {
		printf("%d ", l->elem);
		l = l->next;
	}
	printf("\n");
}