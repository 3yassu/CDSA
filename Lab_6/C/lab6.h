#ifndef LAB_06
#define LAB_06
#include <stdbool.h>
#include <stddef.h>

typedef struct val val;
typedef struct LinkedList LinkedList;
typedef struct HashTable HashTable;
typedef struct HashSet HashSet;

struct val{
	int key;
	int value; //</3
	bool valid; // double </3
};

LinkedList *list_init();
void list_push(LinkedList *self, val entry);
val list_search(LinkedList *self, int key);
void list_print(LinkedList *self);
void list_uninit(LinkedList *self);

HashSet *hashset_init(size_t cap, size_t r);
HashTable *hashtable_init(size_t cap);

//size_t hash1(int key); just k%m
size_t hash2(int key, size_t r);

void hashset_insert(HashSet *self, int key, val value);
val hashset_search(HashSet *self, int key);
void hashset_print(HashSet *self);
void hashset_uninit(HashSet *self);

void hashtable_print(HashTable *self);
void hashtable_insert(HashTable *self, int key, val value);
val hashtable_search(HashTable *self, int key);
void hashtable_uninit(HashTable *self);

#endif
