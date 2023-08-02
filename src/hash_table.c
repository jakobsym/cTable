#include <stdlib.h>
#include <string.h>
#include "hash_table.h"


// initialisation function for 'ht_item(s)'
static ht_item* ht_new_item(const char* k, const char *v) {
    ht_item* i = malloc(sizeof(ht_item));
    i->key = strdup(k); // `strdup()` creates char* pointer that is null-terminated
    i->value = strdup(v);
    return i;
}