#ifndef LAB_06
#define LAB_06
#include <stdbool.h>
#include <stddef.h>

typedef struct val{
	int key;
	int value; //</3
	bool valid; // double </3
} val;

typedef struct Node { //int cuz I don't wanna do type generics #define node(type)whatevr
	val entry;
	struct Node *next;
} Node;

typedef struct LinkedList{
	size_t len;
	Node *front;
} LinkedList;

typedef struct HashTable {
	size_t len;
	size_t cap;
	LinkedList *buckets;
} HashTable;

typedef struct HashSet {
	size_t len;
	size_t cap;
	size_t r; //what the hell
	val *arr;
} HashSet;

Node *node_init(val entry);
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
