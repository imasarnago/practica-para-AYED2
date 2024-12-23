#include <stdlib.h>     /* malloc(), free()... */
#include <stdbool.h>    /* bool type           */
#include <assert.h>     /* assert()            */
#include "key_value.h"  /* key_t               */
#include "dict.h"       /* intarface           */

struct _s_dict {
    size_t size;
    struct _node_t * first;
};

// Internal structure
struct _node_t {
    key_t key;
    value_t value;
    struct _node_t *next;
};



struct _node_t * create_node(key_t k, value_t v) {
    struct _node_t *new_node=malloc(sizeof(struct _node_t));
    new_node->key=k;
    new_node->value=v;
    new_node->next=NULL;
    return new_node;
}

struct _node_t *destroy_node(struct _node_t *node) {
    node->key = key_destroy(node->key);
    node->value = value_destroy(node->value);
    free(node);
    node=NULL;
    return node;
}

static bool invrep(dict_t dict) {
    assert(sizeof(dict) == dict->size);
}
// --- Interface functions ---

dict_t dict_empty(void) {
    dict_t new_dict = malloc(sizeof(dict_t));
    new_dict->first=NULL;
    new_dict->size=0;
    assert(dict_length(new_dict)==0);
    return new_dict;
}

dict_t dict_add(dict_t dict, key_t word, value_t def) {
    struct _node_t *tmp = dict->first;
    for (int i = 0; i<dict_length(dict); i++) {
        if(tmp->next !=NULL) {
            tmp = tmp->next;
        }             
    }
    tmp = tmp->next;
    create_node(word,def);
    dict->size=dict->size+1;
    assert(dict_exists(dict,word)); //  POST-CONDITION
    return dict;
}

value_t dict_search(dict_t dict, key_t word) {
    struct _node_t *tmp = dict->first;
    value_t definition;
    for (int i = 0; i<dict_length(dict); i++) {
        if(tmp->key==word) {
            definition = tmp->value;
            break;
        }             
    }
    return definition;
}

bool dict_exists(dict_t dict, key_t word) {
    

    //assert((def!=NULL) == dict_exists(dict,word));
}

unsigned int dict_length(dict_t dict) {
    // COMPLETAR
}

dict_t dict_remove(dict_t dict, key_t word) {
    // COMPLETAR
}

void dict_dump(dict_t dict, FILE *file) {
    assert(invrep(dict));
    for (struct _node_t *check=dict->first; check!=NULL; check=check->next) {
        fprintf(file, "key: ");
        key_dump(check->key, file);
        fprintf(file, "\n");
        fprintf(file, "value: ");
        value_dump(check->value, file);
        fprintf(file, "\n\n");
    }
}

dict_t dict_remove_all(dict_t dict) {
    // COMPLETAR
}

dict_t dict_destroy(dict_t dict) { 
    assert(invrep(dict));
    dict = dict_remove_all(dict);
    free(dict);
    dict=NULL;
    assert(dict==NULL);
    return dict;
}

