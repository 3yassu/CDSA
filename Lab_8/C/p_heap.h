#ifndef L8PHEAP
#define L8PHEAP
#include <stddef.h>
typedef struct Heap Heap;

Heap *heap_init();
int heap_append(Heap *self, char key);
int dict_add(Dict *self, char key, char val, size_t weight);
void dict_drop(Dict *self);
char dict_get(Dict *self, char key);
#endif
