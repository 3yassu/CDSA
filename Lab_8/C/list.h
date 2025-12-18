//LISTT
#ifndef L8LIST
#define L8LIST
#include <stddef.h>
#include <stdbool.h>
#include "val.h"
typedef struct AdjList AdjList;
typedef struct AdjTuple {
	AdjList *list;
	size_t weight;
}AdjTuple;

AdjList *l_init();
int l_append(AdjList *self, char u, char v, size_t w);
char *get_edges(AdjList *self, size_t size);
void l_drop(AdjList *self);
void l_merge(AdjVal *list_1, AdjVal *list_2, size_t len_1, size_t len_2);
void l_merge_sort(AdjVal *list, size_t len);
void l_sort(AdjList *self);
void l_drop(AdjList *self);
bool str_in(char *str, size_t len, char it);
size_t l_get_len(AdjList *self);
AdjVal l_get_item(AdjList *self, size_t loc);
void t_print(AdjTuple tuple);

#endif
