#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
#include "abb.h"

struct _s_abb {
    abb_elem elem;
    struct _s_abb *left;
    struct _s_abb *right;
};

static bool elem_eq(abb_elem a, abb_elem b) {
    return a == b;
}

static bool elem_less(abb_elem a, abb_elem b) {
    return a < b;
}

static bool invrep(abb tree) {
    bool b = true;
    tree = tree;
    if(tree!=NULL) {
        if(tree->left != NULL) {
            b = invrep(tree->left) && tree->elem > tree->left->elem;
        } 
        if (tree->right != NULL) {
            b = invrep(tree->right) && tree->elem < tree->right->elem;
        }
    }
    return b;
}

abb abb_empty(void) {
    abb tree;
    tree = NULL;
    assert(invrep(tree) && abb_is_empty(tree));
    return tree;
}

abb abb_add(abb tree, abb_elem e) {
    assert(invrep(tree));
    if (tree != NULL) {
        if (elem_less(e, tree->elem)) {
            tree->left = abb_add(tree->left, e);
        } else if (elem_less(tree->elem, e)) {
            tree->right = abb_add(tree->right, e);
        } else if (elem_eq(e, tree->elem)) {
            // do nothing
        }
    } else {
        tree = malloc(sizeof(struct _s_abb));
        tree->elem = e;
        tree->left = NULL;
        tree->right = NULL;
    }
    
    assert(invrep(tree) && abb_exists(tree, e));
    return tree;
}

bool abb_is_empty(abb tree) {
    bool is_empty=false;
    assert(invrep(tree));
    is_empty = tree == NULL;
    return is_empty;
}

bool abb_exists(abb tree, abb_elem e) {
    bool exists = false;
    assert(invrep(tree));
    if (tree != NULL) {
        if (elem_less(e, tree->elem) && !exists) {
            exists = abb_exists(tree->left, e);
        } else if (elem_less(tree->elem, e) && !exists) {
            exists = abb_exists(tree->right, e);
        } else if (elem_eq(e, tree->elem)) {
            exists = true;
        }
    }
    return exists;
}

unsigned int abb_length(abb tree) {
    unsigned int length=0;
    assert(invrep(tree));
    if (tree != NULL) {
        length = 1 + abb_length(tree->left) + abb_length(tree->right);
    }
    assert(invrep(tree) && (abb_is_empty(tree) || length > 0));
    return length;
}

abb abb_remove(abb tree, abb_elem e) {
    assert(invrep(tree) && abb_exists(tree, e));
    bool found = false;
    if (tree != NULL) {
        if (elem_less(e, tree->elem) && !found) {
            tree->left = abb_remove(tree->left, e);
        } else if (elem_less(tree->elem, e) && !found) {
            tree->right = abb_remove(tree->right, e);
        } else if (elem_eq(e, tree->elem)) {
            found = true;
            if (tree->left == NULL && tree->right == NULL) {
                free(tree);
                tree = NULL;
            } else if (tree->left == NULL) {
                abb tmp = tree;
                tree = tree->right;
                free(tmp);
            } else if (tree->right == NULL) {
                abb tmp = tree;
                tree = tree->left;
                free(tmp);
            } else if (tree->left != NULL && tree->right != NULL) {
                abb tmp = tree;
                abb tmp2 = tree->right;
                abb tmp3 = tree->left;
                tree = tmp3;
                while(tmp3->right != NULL) {
                    tmp3 = tmp3->right;
                }
                tmp3->right = tmp2;
                free(tmp); 
            }
        }
    }
    assert(!abb_exists(tree,e));
    assert(invrep(tree));
    return tree;
}

abb_elem abb_root(abb tree) {
    abb_elem root;
    assert(invrep(tree) && !abb_is_empty(tree));
    root = tree->elem;
    assert(abb_exists(tree, root));
    return root;
}

abb_elem abb_max(abb tree) {
    abb_elem max_e;
    assert(invrep(tree) && !abb_is_empty(tree));
    while(tree->right != NULL) {
        tree = tree->right;
    }
    max_e = tree->elem;
    assert(invrep(tree) && abb_exists(tree, max_e));
    return max_e;
}

abb_elem abb_min(abb tree) {
    abb_elem min_e;
    assert(invrep(tree) && !abb_is_empty(tree));
    while(tree->left != NULL) {
        tree = tree->left;
    }
    min_e = tree->elem;
    assert(invrep(tree) && abb_exists(tree, min_e));
    return min_e;
}

void abb_dump(abb tree) {
    assert(invrep(tree));
    if (tree != NULL) {
        printf("%d ", tree->elem);
        abb_dump(tree->left);
        abb_dump(tree->right);
    }
}

abb abb_destroy(abb tree) {
    assert(invrep(tree));
    if (tree != NULL)
    {
        abb_destroy(tree->left);
        abb_destroy(tree->right);
        free(tree);
        tree= NULL;
    }
    
    assert(tree == NULL);
    return tree;
}

