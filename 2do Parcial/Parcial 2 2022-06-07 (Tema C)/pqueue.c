#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include "pqueue.h"

struct s_pqueue {
    unsigned int size;      // Size of queue (how many nodes there are)
    priority_t min_priority;
    pnode * array; // Pointer to the first pointer to node of the array of prioritys
};

struct s_node {
    pqueue_elem elem;
    struct s_node * next;
};

static struct s_node * create_node(pqueue_elem e) {
    struct s_node* new_node=NULL;
    new_node = malloc(sizeof(struct s_node));
    assert(new_node!=NULL);

    new_node->elem = e;
    new_node->next = NULL;

    assert(new_node!=NULL);
    return new_node;
}

static struct s_node * destroy_node(struct s_node *node) {
    node->next=NULL;
    free(node);
    node=NULL;
    return node;
}


static bool invrep(pqueue q) {
    return q != NULL;
}

pqueue pqueue_empty(priority_t min_priority) {
    pqueue q=NULL;
    q = malloc(sizeof(struct s_pqueue));
    q->size = 0;
    q->min_priority = min_priority;
    q->array = calloc(min_priority+1, sizeof(struct s_node *));
    for (unsigned int i = 0u; i <= min_priority; ++i) {
        q->array[i] = NULL;
    }
    assert(invrep(q) && pqueue_is_empty(q));
    return q;
}

pqueue pqueue_enqueue(pqueue q, pqueue_elem e, priority_t priority) {
    assert(invrep(q) && priority <= q->min_priority);

    if ((q->array)[priority]==NULL) {
        (q->array)[priority] = create_node(e);
    } else {
        struct s_node * nde = (q->array)[priority];
        while (nde->next != NULL) {
            nde = nde -> next;
        }
        nde->next = create_node(e);
    }
    ++q->size;

    assert(invrep(q) && !pqueue_is_empty(q));
    return q;
}

bool pqueue_is_empty(pqueue q) {
    assert(invrep(q));
    /*bool empty = true;
    for (unsigned int i = 0u; i <= q->min_priority; ++i)
    {
        empty = empty && ((q->array)[i]== NULL);
    }*/
    return(q->size == 0);
}

pqueue_elem pqueue_peek(pqueue q) {
    assert(invrep(q) && !pqueue_is_empty(q));
    priority_t p = pqueue_peek_priority(q);
    return (q->array[p])->elem;
}

priority_t pqueue_peek_priority(pqueue q) {
    assert(invrep(q) && !pqueue_is_empty(q));
    pnode * array = q->array;
    priority_t priority = 0u;
    while (priority <= q->min_priority && array[priority]==NULL) {
        ++priority;
    }

    return priority;
}

size_t pqueue_size(pqueue q) {
    assert(invrep(q));
    return q->size;
}

pqueue pqueue_dequeue(pqueue q) {
    assert(invrep(q) && !pqueue_is_empty(q));
    pnode * array = q->array;
    priority_t peek_priority;

    peek_priority = pqueue_peek_priority(q);
    pnode killme=array[peek_priority];

    array[peek_priority] = array[peek_priority]->next;
    killme = destroy_node(killme);
    --q->size;

    assert(invrep(q));
    return q;
}

pqueue pqueue_destroy(pqueue q) {
    assert(invrep(q));
    pnode * array = q->array;
    for (unsigned int current_priority = 0u; current_priority <= q->min_priority; ++current_priority) {
        while (array[current_priority] != NULL) {
            struct s_node *killme=array[current_priority];
            array[current_priority] = array[current_priority]->next;
            killme = destroy_node(killme);
        }   
    }
    free(array);
    free(q);
    q = NULL;
    assert(q == NULL);

    return q;
}