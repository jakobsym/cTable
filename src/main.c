#include "hash_table.h"

ht_hash_table* ht_new();
void ht_del_hash_table(ht_hash_table* ht);

int main() {
    ht_hash_table* ht = ht_new();
    ht_del_hash_table(ht);
    return 0;
}

