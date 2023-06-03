#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include "set.h"

struct s_node {
    set_elem elem;
    struct s_node *next;
};

typedef struct s_node * node_t;

struct s_set {
    unsigned int size;
    node_t first;
};

static bool goes_before( set_elem a, set_elem b) {
    return a < b;
}

static bool invrep(set s) {

    bool res = false;
    if (s != NULL) {
        res = true;
        if (s->first != NULL && s->size != 0) {

            node_t n = s->first;
            while (n->next != NULL)
            {
                res = res && goes_before(n->elem,n->next->elem);
                n = n->next;
            }
            
        }
    }
    
    return res;
}

static struct s_node *
create_node(set_elem e) {
    node_t new_node = NULL;
    new_node = malloc(sizeof(struct s_node));
    assert(new_node != NULL);

    new_node->elem = e;
    new_node->next = NULL;

    return new_node;
}

static struct s_node *
destroy_node(struct s_node *node) {
    
    node->next= NULL;
    free(node);
    node = NULL;

    return node;
}

/* CONSTRUCTORS */

set set_empty(void) {
    set new_set = NULL;
    new_set = malloc(sizeof(struct s_set));

    new_set->first = NULL;
    new_set->size = 0;

    assert(invrep(new_set));
    return new_set;
}

set set_add(set s, set_elem e) {
    assert(invrep(s));
    node_t previous_node = NULL; // puntero al nodo #"x-1"
    node_t node=s->first;       // Puntero al nodo #"x" (Donde x va hasta s->size)

        // Caso 0:
        // Si el set esta vacio es trivial agregar el nuevo nodo
        if (node == NULL && s->size == 0) {
            s->first = create_node(e);
            ++s->size;
        } else {
            // Caso 0.1:
            // Si e ya pertenece al set, no hay que agregarlo
            if (!set_member(e, s)) {

                // Avanzamos hasta llegar al nodo con el primer elemento de mayor valor
                // O hasta el final del set
                while (node->next!=NULL && goes_before(node->elem,e)) {
                    previous_node = node;
                    node = node->next;
                }


                // Caso 1: No hay nodo previo
                if (previous_node == NULL) {

                    // Caso 1.1:
                    // 'e' es mayor que el elemento del set
                    if (node->next == NULL && goes_before(node->elem, e))
                    {
                        s->first->next = create_node(e);
                        ++s->size;
                    }

                    // Caso 1.2:
                    // Hay un elemento mayor que 'e'
                    if (!goes_before(node->elem,e))
                    {
                        node_t new_node = NULL;
                        new_node = create_node(e);
                        new_node->next = s->first;
                        s->first = new_node;
                        ++s->size;
                    }
                } else {
                // Caso 2: Hay nodo previo
                    // Caso 2.1: 
                    // 'e' es mayor al elemento que estamos mirando
                    if (goes_before(node->elem,e))
                    {
                        node_t new_node = create_node(e);
                        new_node->next = node->next;
                        node->next = new_node;
                        ++s->size;
                    } else if (!goes_before(node->elem,e)) {
                        // Caso 2.2:
                        // 'e' es menor al elemento que estamos mirando actualmente
                            node_t new_node = create_node(e);
                            new_node->next = node;
                            previous_node->next = new_node;
                            ++s->size;
                    }
                }


            }
        }

    return s;
}

/* OPERATIONS   */
unsigned int set_cardinal(set s) {
    assert(invrep(s));
    return s->size;
}

bool set_is_empty(set s) {
    assert(invrep(s));
    return (s->size == 0);
}

bool set_member(set_elem e, set s) {
    assert(invrep(s));
    node_t node=s->first;
    while (node!=NULL && goes_before(node->elem,e)) {
        node = node->next;
    }
    return node!=NULL && node->elem==e;
}

set set_elim(set s, set_elem e) {
    assert(invrep(s));
    node_t previous_node = NULL; // puntero al nodo #"x-1"
    node_t node=s->first;       // Puntero al nodo #"x" (Donde x va hasta s->size)
        // Avanzamos hasta encontrar (o no) el elemento
        while (node!=NULL && node->elem < e) {
            previous_node = node;
            node = node->next;
        }
        // Si encontramos el elemento
        if (node != NULL && node->elem == e)
        {
            //Guardamos en una variable auxiliar el nodo siguiente
            node_t auxNode = node->next;
            //Destruimos el nodo
            node = destroy_node(node);

            // Si habia un nodo previo al nodo 'node' donde encontramos 'e'
            if (previous_node != NULL)
            {
            ;    //Modificamos el nodo anterior para que no tenga mas en cuenta el nodo con 'e'
                previous_node->next = auxNode;

            } else { // Si no habia nodo previo
                // El primer nodo pasa a ser auxNode
                // Que a su vez era el siguiente al nodo donde encontramos 'e'
                s->first = auxNode;
            }
            
            // Como eliminamos un nodo, el size se reduce en 1;
            s->size--;
        }
        

    return s;
}

set_elem set_get(set s) {
    assert(invrep(s) && !set_is_empty(s));
    return s->first->elem;
}

set_elem*
set_to_array(set s) {
    assert(invrep(s) && !set_is_empty(s));
    set_elem * array = NULL;
    unsigned int size = s->size;
    array = calloc(size, sizeof(set_elem));
    node_t node = s->first;

    for (unsigned int i = 0; i < size && node!= NULL; i++)
    {
        array[i] = node->elem;
        node = node->next;

    }

    return(array); 
}

set set_destroy(set s) {
    assert(invrep(s));
    node_t node = s->first;
    while(s->size != 0) {

        node_t killme = node;
        node = node->next;
        killme = destroy_node(killme);
        --s->size;
    }

    s->size = 0;
    free(s);
    s = NULL;
    return s;
}