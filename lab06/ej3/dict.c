#include <assert.h>
#include <stdlib.h>
#include "dict.h"
#include "key_value.h"

struct _node_t
{
    dict_t left;
    dict_t right;
    key_t key;
    value_t value;
};

static bool invrep_aux(dict_t dict, key_t min, key_t max) {
    bool b = true;
    if(dict != NULL) {
        b = string_less(min,dict->key) && string_less(dict->key,max);
        b = b && invrep_aux(dict->left, min, dict->key);
        b = b && invrep_aux(dict->right, dict->key, max);
    }
    return b;
}

static bool invrep(dict_t dict)
{
    if (dict == NULL)
    {
        return true;
    }
    key_t min = string_create("");
    key_t max = string_create("zzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz");
    bool b = true;
    if(dict != NULL) {
        b = invrep_aux(dict, min, max);
    }
    return b;
}

dict_t dict_empty(void)
{
    dict_t dict = NULL;
    assert(invrep(dict) && dict_length(dict)==0);
    return dict;
}

dict_t dict_add(dict_t dict, key_t word, value_t def)
{
    assert(invrep(dict));
    if (dict != NULL)
    {
        if (string_less(word, dict->key))
        {
            dict->left = dict_add(dict->left, word, def);
        }
        else if (string_less(dict->key, word))
        {
            dict->right = dict_add(dict->right, word, def);
        }
        else if (string_eq(word, dict->key))
        {
            // do nothing
        }
    }
    else
    {
        dict = malloc(sizeof(struct _node_t));
        dict->key = word;
        dict->value = def;
        dict->left = NULL;
        dict->right = NULL;
    }

    assert(invrep(dict) && key_eq(def, dict_search(dict, word)));
    return dict;
}

value_t dict_search(dict_t dict, key_t word)
{
    key_t def = NULL;
    assert(invrep(dict));
    if (dict != NULL)
    {
        if (string_less(word, dict->key))
        {
            def = dict_search(dict->left, word);
        }
        else if (string_less(dict->key, word))
        {
            def = dict_search(dict->right, word);
        }
        else if (string_eq(word, dict->key))
        {
            def = dict->value;
        }
    }
    assert(invrep(dict) && (def == NULL || dict_exists(dict, word)));
    return def;
}

bool dict_exists(dict_t dict, key_t word)
{
    bool exists = false;
    assert(invrep(dict));
    if (dict != NULL)
    {
        if (string_less(word, dict->key) && !exists)
        {
            exists = dict_exists(dict->left, word);
        }
        else if (string_less(dict->key, word) && !exists)
        {
            exists = dict_exists(dict->right, word);
        }
        else if (string_eq(word, dict->key))
        {
            exists = true;
        }
    }

    return exists;
}

unsigned int dict_length(dict_t dict)
{
    unsigned int length = 0;
    assert(invrep(dict));
    if (dict != NULL)
    {
        length = 1u + dict_length(dict->left) + dict_length(dict->right);
    }
    return length;
}

dict_t dict_remove(dict_t dict, key_t word)
{
    assert(invrep(dict));
    bool found = false;
    if (dict != NULL)
    {
        if (string_less(word, dict->key) && !found)
        {
            dict->left = dict_remove(dict->left, word);
        }
        else if (string_less(dict->key, word) && !found)
        {
            dict->right = dict_remove(dict->right, word);
        }
        else if (string_eq(word, dict->key))
        {
            found = true;
            if (dict->left == NULL && dict->right == NULL)
            {
                string_destroy(dict->key);
                string_destroy(dict->value);
                free(dict);
                dict = NULL;
            }
            else if (dict->left == NULL)
            {
                dict_t tmp = dict;
                string_destroy(dict->key);
                string_destroy(dict->value);
                dict = dict->right;
                free(tmp);
            }
            else if (dict->right == NULL)
            {
                dict_t tmp = dict;
                string_destroy(dict->key);
                string_destroy(dict->value);
                dict = dict->left;
                free(tmp);
            }
            else if (dict->left != NULL && dict->right != NULL)
            {
                dict_t tmp = dict;
                dict_t tmp2 = dict->right;
                dict_t tmp3 = dict->left;
                dict = tmp3;
                while (tmp3->right != NULL)
                {
                    tmp3 = tmp3->right;
                }
                tmp3->right = tmp2;
                string_destroy(tmp->key);
                string_destroy(tmp->value);
                free(tmp);
            }
        }
    }
    assert(!dict_exists(dict, word));
    assert(invrep(dict));
    return dict;
}

dict_t dict_remove_all(dict_t dict)
{
    assert(invrep(dict));
    if (dict != NULL)
    {
        dict->left = dict_remove_all(dict->left);
        dict->right = dict_remove_all(dict->right);
        string_destroy(dict->key);
        string_destroy(dict->value);
        free(dict);
        dict = NULL;
    }

    assert(dict_length(dict) == 0);
    return dict;
}

void dict_dump(dict_t dict, FILE *file)
{
    assert(invrep(dict) && file != NULL);
    if (dict != NULL)
    {
        dict_dump(dict->left, file);
        fprintf(file, "%s: %s\n", string_ref(dict->key), string_ref(dict->value));
        dict_dump(dict->right, file);
    }
}

dict_t dict_destroy(dict_t dict)
{
    assert(invrep(dict));
    if (dict != NULL)
    {
        dict_destroy(dict->left);
        dict_destroy(dict->right);
        string_destroy(dict->key);
        string_destroy(dict->value);
        free(dict);
        dict = NULL;
    }

    assert(dict == NULL);
    return dict;
}
