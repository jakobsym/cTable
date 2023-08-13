#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <math.h>

/**
 * */
typedef struct {
    char* key;
    char* value;
} ht_item;
/**
 * */
typedef struct {
    int size;
    int count;
    ht_item** items; // dynamic array of pointers to 'ht_item' struct
} ht_hash_table;

#endif /* HASH_TABLE_H */