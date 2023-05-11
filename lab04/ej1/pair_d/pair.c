#include <stdlib.h>  /* EXIT_SUCCESS... */
#include <stdio.h>   /* printf()...     */
#include "pair.h"    /* TAD Par         */

struct s_pair_t {
    elem fst;
    elem snd;
};

pair_t pair_new(elem x, elem y) {
    pair_t p = NULL;
    p = malloc(sizeof(struct s_pair_t));
    p->fst = x;
    p->snd = y;
    return p;
}

elem pair_first(pair_t p) {
    return p->fst;
}

elem pair_second(pair_t p) {
    return p->snd;
}

pair_t pair_swapped(pair_t p) {

    return (pair_new(p->snd,p->fst));
}

pair_t pair_destroy(pair_t p) {
	free(p);
    return p;
}