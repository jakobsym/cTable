#include "hash_table.h"


/**
 * Hashing function: Converts input string to a large int, reduce size of integer to fixed range (0 - m)
 * creating bucket of hash table.
 * @param s character array.
 * @param a constant prime number integer > 128 (hashing ASCII strings which has alphabet size of 128).
 * @param m constant integer, used to fix range (0 - m)
 * @return the bucket location as an integer in which `s` is going to be stored.
 * */
static int ht_hash(const char* s, const int a, const int m) {
    long hash = 0;
    const int s_len = strlen(s);

    for (int i = 0; i < s_len; i++) {
        hash += (long)pow(a, s_len - (i+1)) * s[i];
        hash %= m;
    }
    return (int)hash;
}







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
    printf("New Hash Table has been created.\n");
    ht->size = 53;
    ht->count = 0;
    // allocate memory to the size of a ' ht_item ': ' ht_item* ' used as we want array of pointers to 'ht_item'
    ht->items = calloc((size_t)ht->size, sizeof(ht_item*)); // fill array of items memory with 'NULL' bytes
    return ht;
}

// Delete 'ht_item(s)' and 'ht_hash_table(s)': Freeing any allocated memory
static void ht_del_item(ht_item* i) {
    // free children of 'i' before free 'i' itself
    free(i->key);
    free(i->value);
    free(i);
}

// Delete 'ht_hash_table(s)': Freeing any allocated memory
void ht_del_hash_table(ht_hash_table* ht) {
    printf("Hash Table has been deleted.\n");
    for (int i = 0; i < ht->size; i++) {
        /* unpack 'ht->items' array into temp variable to protect against improper freeing of memory.
         Ensuring we only delete(free) an 'ht_item' if its valid pointer and not already free'd */
        ht_item* item = ht->items[i];
        if (item != NULL) {
            ht_del_item(item);
        }
    }
    free(ht->items);
    free(ht);
}