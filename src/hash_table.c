#include <stdlib.h>
#include <string.h>
#include "hash_table.h"

// Initialisation function for 'ht_item(s)'
/**
 * */
static ht_item* ht_new_item(const char* k, const char *v) {
    ht_item* i = malloc(sizeof(ht_item));
    i->key = strdup(k); // `strdup()` creates char* pointer that is null-terminated
    i->value = strdup(v);
    return i;
}

// Create a new hash table: ('NULL' indicates empty bucket)
/**
 * */
ht_hash_table* ht_new() {
    ht_hash_table* ht = malloc(sizeof(ht_hash_table));
    ht->count = 0;
    ht->size = 53;
    ht->items = ; // fill array of items memory with 'NULL' bytes
    return ht;
}