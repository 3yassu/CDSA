#include <stdio.h>
#include <stdlib.h>
#include "kruskal_graph.h"
#define new(T) (T *)malloc(sizeof(T));
typedef struct AdjVal {
	char u;
	char v;
	size_t w;
} AdjVal;

struct AdjList {
	size_t len;
	size_t cap;
	AdjVal *arr;
};

struct Graph {
	size_t V;
	AdjList *edges;
}
AdjList *l_init();
int l_append(AdjList *self, char u, char v, size_t w);
void l_drop(AdjList *self);
void l_merge(AdjVal *list_1, AdjVal *list_2, size_t len_1, size_t len_2);
void l_merge_sort(AdjVal *list, size_t len);
void l_sort(AdjList *self);


AdjList *l_init(){
	AdjList *ptr = new(AdjList);
	if(ptr == NULL)
		return NULL;
	*ptr = (AdjList){.len = 0, .cap = 0, .arr = NULL};
	return ptr;
}

int l_append(AdjList *self, char u, char v, size_t w){
	if(self == NULL)
		return 2;
	if(self->cap == 0){
		self->arr = (AdjVal *)malloc(sizeof(AdjVal)*(self->cap = 1));
		if(self->arr == NULL)
			return 1;
	}
	if(self->len <= self->cap){
		AdjVal old_ptr = self->arr;
		self->arr = (AdjVal *)malloc(sizeof(AdjVal)*(self->cap *= 2));
		for(size_t i = 0; i < self->cap/2; i++)
			self->arr[i] = old_ptr[i];
		free(old_ptr)
	}
	self->arr[self->len] = (AdjVal){.u = u, .v = v, .w = w};
	self->len++;
	return 0;
}
void l_drop(AdjList *self){
	if(self == NULL)
		return;
	free(self->arr);
	free(self);
}
void l_sort(AdjList *self, ){
	if(self == NULL)
		return;
	l_merge_sort(self->arr, self->len);
}
void l_merge_sort(AdjVal *list, size_t len){
	size_t mid = len/2;
	size_t max = len%2 ? mid + 1 : mid;
	l_merge_sort(list, mid); l_merge_sort(list + mid, max);
	l_merge(list, list + mid, mid, max);
}
void l_merge(AdjVal *list_1, AdjVal *list_2, size_t len_1, size_t len_2){
	size_t len_tot = len_1 + len_2, j = len_1, k = len_2;
	AdjVal *tmp = (AdjVal *)malloc(sizeof(AdjVal)*len_tot);
	if(tmp == NULL)
		return;
	for(size_t i = 0; i < combo_size && (j+k) > 0; i++)
		if(k == 0 || (j > 0 && k > 0 && (list_1 + size_1 - j)->w < (list_2 + size_2 - k)->w))
  		*(tmp + i) = *(list_1 + size_1 - (j--));
		else
			*(tmp + i) = *(list_2 + size_2 - (k--));
	for(int i = 0; i < combo_size; i++, list_1++, temp_list++)
		*list_1 = *tmp;
	temp_list -= combo_size;
	free(temp_list);
}

Graph *g_init(size_t vertices){
	Graph *ptr = new(Graph);
	if(ptr == NULL)
		return NULL;
	*ptr = (Graph){.V = vertices, .edges = l_init()};
	return ptr;
}
int g_add_edge(Graph *self, char u, char v, size_t w){
	if(self == NULL)
		return 2;
	return l_append(self->edges, u, v, w);
}
void g_drop(Graph *self){
	if(self == NULL)
		return;
	l_drop(self->edges);
	free(self);
}
AdjList *kruskal_mst(Graph *self){
	l_sort(self->edges);
	AdjList *ret = new(AdjList);
	if(ret == NULL)
		return NULL;
	
}

