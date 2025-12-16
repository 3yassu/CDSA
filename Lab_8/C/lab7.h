#ifndef LAB7
#define LAB7

#include <stdbool.h>
#include <stddef.h>

typedef struct CArray CArray;
typedef struct LinkedList LinkedList;
typedef struct HashTable HashTable;
typedef struct Graph Graph;
typedef struct val val;

void val_uninit(val *self);
LinkedList *list_init();
int list_push(LinkedList *self, val entry);
val list_search(LinkedList *self, int key);
void list_print(LinkedList *self);
void list_uninit(LinkedList *self);

void val_uninit(val *self);
void val_print(val *self);

void carray_uninit(CArray *self);
HashTable *hashtable_init();

void hashtable_print(HashTable *self);
int hashtable_insert(HashTable *self, char key, val value);
val hashtable_search(HashTable *self, char key);
void hashtable_uninit(HashTable *self);

Graph *graph_init(bool directed);
int add_edge(Graph *self, char u, char v);
val *bfs(Graph *self, char start);
val *dfs(Graph *self, char start);
void graph_uninit(Graph *self);
void graph_print(Graph *self);

#endif
