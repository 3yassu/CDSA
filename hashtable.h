//Hash table lol...
#include "list.h"
typedef struct HashTable HashTable


HashTable *hashtable_init();
int ht_insert(HashTable *self, char key, val value);
void ht_print(HashTable *self);
void ht_drop(HashTable *self);
