#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include "pqueue.h"

struct s_pqueue {
    unsigned int size;
    struct s_node * node;
};

struct s_node {
    pqueue_elem elem;
    unsigned int priority;
    struct s_node * next;
};

static struct s_node * create_node(pqueue_elem e, unsigned int priority) {
    struct s_node *new_node = NULL;
    new_node = malloc(sizeof(struct s_node));
    assert(new_node!=NULL);
    new_node->priority = priority;
    new_node->elem = e;
    return new_node;
}

static struct s_node * destroy_node(struct s_node *node) {
    assert(node != NULL);
    node->next=NULL;
    free(node);
    node=NULL;
    assert(node == NULL);
    return node;
}


static bool invrep(pqueue q) {
    bool b = false;
    if (q != NULL) {
        unsigned int length = 0u;
        if (q->node != NULL) {
            length = 1;
        }
        if(q->node != NULL && q->size > 0) {   
            struct s_node *new_node = q->node;
            //b = node->priority >= 0 (trivial porque es unsigned)
            b = true;
            while(new_node->next != NULL && b) {
                b = b && ((new_node->priority) <= (new_node->next)->priority);
                length = length + 1;
                new_node = new_node->next;
            }
        } else if (q->node == NULL && q->size == 0) {
            b = true;
        }

        b = b && (q->size == length);
    } else  {
        printf("q == NULL\n");
    }
    return b;
}

pqueue pqueue_empty(void) {
    pqueue q=NULL;
    q = malloc(sizeof(struct s_pqueue));
    q->size = 0;
    q->node = NULL;
    assert(invrep(q) && pqueue_is_empty(q));
    return q;
}

pqueue pqueue_enqueue(pqueue q, pqueue_elem e, unsigned int priority) {
    assert(invrep(q));
    struct s_node *new_node = create_node(e, priority);
    if (pqueue_is_empty(q)) {
        q->node = new_node;
        q->size = 1;
    } else {
        struct s_node * g = q->node;
        while(g->next != NULL) {
            g = g->next;
        }
        g->next = new_node;
        q->size = q->size + 1;
    }
    assert(invrep(q));
    assert(!pqueue_is_empty(q));
    return q;
}

bool pqueue_is_empty(pqueue q) {
    assert(invrep(q));
    return q->node == NULL && q->size == 0;
}

pqueue_elem pqueue_peek(pqueue q) {
    assert(invrep(q) && !pqueue_is_empty(q));
    struct s_node * node = q->node;
    assert(invrep(q));
    return node->elem;
}

unsigned int pqueue_peek_priority(pqueue q) {
    assert(invrep(q) && !pqueue_is_empty(q));
    struct s_node * node = q->node;
    assert(invrep(q));
    return node->priority;
}

unsigned int pqueue_size(pqueue q) {
    assert(invrep(q));
    unsigned int size = q->size;
    assert(invrep(q));
    return size;
}

pqueue pqueue_dequeue(pqueue q) {
    assert(invrep(q) && !pqueue_is_empty(q));
    struct s_node * killme=q->node;
    q->node = q->node->next;
    killme = destroy_node(killme);
    --q->size;
    assert(invrep(q));
    return q;
}

pqueue pqueue_destroy(pqueue q) {
    assert(invrep(q));
    struct s_node *node=q->node;
    while (node != NULL) {
        struct s_node *killme=node;
        node = node->next;
        killme = destroy_node(killme);
    }
    free(q);
    q = NULL;
    assert(q == NULL);
    return q;
}
