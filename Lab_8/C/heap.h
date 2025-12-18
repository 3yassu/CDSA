#ifndef L8HEAP
#define L8HEAP
#include "val.h"
typedef struct AdjHeap AdjHeap;

AdjHeap *h_init();
int h_add(AdjHeap *self, char u, char v, size_t w);
AdjVal h_pop(AdjHeap *self);
void h_drop(AdjHeap *self);
size_t h_get_len(AdjHeap *self);
void h_print(AdjHeap *self);

#endif
