#ifndef	_LIST_H
#define _LIST_H
#include <stdbool.h>

typedef struct node * list;
typedef int list_elem;


/*------ Constructors -------*/
list init_list(void);
/*
	Returns a new list
*/

list addl_list(list_elem e, list l);
/*
	Adds to the left of the list l an element e
*/

/*------ Operations -------*/
bool is_empty_list(list l);
/*
	Returns True if l is an empty list
*/

list_elem head_list(list l);
/*
	Returns the first element of l
*/

list tail_list(list l);
/*
	PRE: !is_empty_list(l);
	Returns the list l without the first element
*/

list addr_list(list_elem e, list l);
/*
	Adds the element e to the right of the list l
*/

unsigned int length_list(list l);
/*
	Returns how many elements are
	in the list L
*/

list concat_list(list l, list d);
/*
	Adds all the elements of list d to the
	right of list l, in order
*/

list_elem index_list(list l, unsigned int pos);
/*
	PRE: length(l) > pos;
	Returns the n_th element from list l
	the first element starting from 1 
*/

list take_list(list l, unsigned int n);
/*
	Returns the list L with only the
	first n_th elements
*/

list drop_list(list l, unsigned int n);
/*
	Deletes the first n_th elements from l
*/

list copy_list(list l);
/*
	Returns a NEW list, copy of the list l
*/

list destroy_list(list l);
/*
	Frees memory of l
*/

void print_list(list l);
/*
	Prints in stdout the list l
*/

#endif