/* First, the standard lib includes, alphabetically ordered */
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

/* Then, this project's includes, alphabetically ordered */
#include "stack.h"

void array_dump(int a[], unsigned int length) {
    fprintf(stdout, "[");
    for (unsigned int i = 0u; i < length; ++i) {
        fprintf(stdout, "%d", a[i]);
        if (i < length - 1) {
            fprintf(stdout, ", ");
        } else {
            fprintf(stdout, "]\n");
        }
    }
}

int main(int argc, char const *argv[]) {

	argc = argc;
	argv = argv;

	printf("| Testing stack_pop in stacks of size 1 |\n\n");
	stack p = stack_empty();
	p = stack_push(p, 99);
	printf("Stack before pop: ");
	print_stack(p);
	unsigned int slbp = stack_size(p);
	printf("Length of stack before pop: %u\n", slbp);
	p = stack_pop(p);
	printf("Stack after pop: ");
	print_stack(p);
	unsigned int slap = stack_size(p);
	printf("Length of stack after pop: %u\n", slap);

	if (slbp == 1 && slap == 0)
	{
		printf("\n-----------TEST 1 PASSED------------\n");
	} else {
		fprintf(stderr, "----XX-----TEST 1 not PASSED------XX----\n");
	}
	printf("\n");

	p = stack_push(p, 99);
	p = stack_push(p, 100);
	unsigned int length = 2;

	printf("| Testing stack_to_array for stack of size %u | \n", length);
	printf("Stack: ");
	print_stack(p);
	stack_elem * a;
	a = stack_to_array(p);

	printf("Array: ");
	array_dump(a, length);
	bool j = true;
	for (unsigned int i = length; 0u < i; --i)
	{	
		j = j && (a[i-1] == stack_top(p));
		p = stack_pop(p);
	}
	if (j) {
		printf("\n-----------TEST 3)b) PASSED------------\n");
		printf("\n");
	} else	{
		printf("\n---XX------TEST 3)b) not PASSED----XX-----\n");
		printf("\n");
	}
	free(a);

	

	printf("| Testing stack_to_array for empty stack |\n");
	printf("Stack: ");
	stack q = stack_empty();
	print_stack(q);
	length = 0;
	stack_elem * b = stack_to_array(q);
	bool h = false;
	if (b == NULL)
	{
		printf("stack is equal to NULL\n");
		h = true;
	}
	printf("Array: ");
	array_dump(b, length);
	free(b);

	h ? printf("\n-----------TEST 3)a) PASSED------------\n") : printf("\n---XX------TEST 3)a) not PASSED------XX----\n");
	printf("\n");

	printf("| Testing if a stack that has been emptied can have elements pushed into again | \n");
	printf("Stack: ");
	stack r = stack_empty();
	r = stack_push(r,77);
	r = stack_push(r,78);
	print_stack(r);
	printf("Stack after being emptied: \n");
	r = stack_pop(r);
	r = stack_pop(r);

	print_stack(r);
	printf("Stack with some new elements pushed into\n");
	r = stack_push(r, 15);
	r = stack_push(r,16);
	print_stack(r);
	slap = stack_size(r);
	h = slap > 0;
	h ? printf("\n-----------TEST 2 PASSED------------\n") : printf("\n---XX-----TEST 2 not PASSED-----XX-----\n");
	printf("\n");

	/* Debugging purposes
	printf("%p \n", (void *) p);
	printf("%d \n",(int) stack_top(p)); */
	stack_destroy(p);
	stack_destroy(q);
	stack_destroy(r);

	return EXIT_SUCCESS;
}