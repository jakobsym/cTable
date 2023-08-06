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
