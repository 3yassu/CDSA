#include <stdio.h>
#include <stdlib.h>
#include "kruskal_graph.h"
#include "union_find.h"
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

struct KGraph {
	size_t V;
	AdjList *edges;
};
AdjList *l_init();
char *get_edges(AdjList *self, size_t size);
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
bool str_in(char *str, size_t len, char it){
	if(str == NULL)
		return false;
	for(size_t i = 0; i < len; i++)
		if(str[i] == it)
			return true;
	return false;
}
char *get_edges(AdjList *self, size_t size){
	if(self == NULL)
		return NULL;
	char *ret = (char *)malloc(sizeof(char)*size);
	if(ret == NULL)
		return NULL;
	size_t j = 0;
	for(size_t i = 0; i < self->len && j < size; i++){
		if(!str_in(ret, j, self->arr[i].u))
			ret[j++] = self->arr[i].u;
		if(!str_in(ret, j, self->arr[i].v))
			ret[j++] = self->arr[i].v;
	}
	return ret;
}
int l_append(AdjList *self, char u, char v, size_t w){
	if(self == NULL)
		return 2;
	if(self->cap == 0){
		self->arr = (AdjVal *)malloc(sizeof(AdjVal)*(self->cap = 1));
		if(self->arr == NULL)
			return 1;
	}
	if(self->len >= self->cap){
		self->arr = (AdjVal *)realloc(self->arr, sizeof(AdjVal)*(self->cap *= 2));
		if(self->arr == NULL){
			printf("l_append: Out of memory!");
			return 1;
		}
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
void l_sort(AdjList *self){
	if(self == NULL)
		return;
	l_merge_sort(self->arr, self->len);
}
void l_merge_sort(AdjVal *list, size_t len){
	if(len <= 1)
		return;
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
	for(size_t i = 0; i < len_tot && (j+k) > 0; i++)
		if(k == 0 || (j > 0 && k > 0 && (list_1 + len_1 - j)->w < (list_2 + len_2 - k)->w))
  		*(tmp + i) = *(list_1 + len_1 - (j--));
		else
			*(tmp + i) = *(list_2 + len_2 - (k--));
	for(size_t i = 0; i < len_tot; i++, list_1++, tmp++)
		*list_1 = *tmp;
	tmp -= len_tot;
	free(tmp);
}

KGraph *kg_init(size_t vertices){
	KGraph *ptr = new(KGraph);
	if(ptr == NULL)
		return NULL;
	*ptr = (KGraph){.V = vertices, .edges = l_init()};
	return ptr;
}
int kg_add_edge(KGraph *self, char u, char v, size_t w){
	if(self == NULL)
		return 2;
	return l_append(self->edges, u, v, w);
}
void kg_drop(KGraph *self){
	if(self == NULL)
		return;
	l_drop(self->edges);
	free(self);
}
KrusTuple kruskal_mst(KGraph *self){
	l_sort(self->edges);
	AdjList *ret = l_init();
	if(ret == NULL)
		return (KrusTuple){.list = NULL, .weight = 0};
	char *edge_l = get_edges(self->edges, self->V);
	if(edge_l == NULL){
		free(ret);
		return (KrusTuple){.list = NULL, .weight = 0};
	}
//	for(size_t i = 0; i < self->V; i++)
//		printf("%c ", edge_l[i]);
//	printf("\n");
	UnionFind *union_find = uf_init(edge_l, self->V);
	free(edge_l);
	if(union_find == NULL){
		free(ret);
		return (KrusTuple){.list = NULL, .weight = 0};
	}
	size_t weight = 0, count = 0;
	for(size_t i = 0; i < self->edges->len; i++){
		if(count > self->V - 1)
			break;
		char u = self->edges->arr[i].u, v = self->edges->arr[i].v, w = self->edges->arr[i].w;
		if(uf_union(union_find, u, v)){
			l_append(ret, u, v, w);
			count += 1;
			weight += w;
		}
	}
	uf_drop(union_find);
	return (KrusTuple){.list = ret, .weight = weight};
}
void k_print(KrusTuple tuple){
	printf("[");
	for(size_t i = 0; i < tuple.list->len; i++)
		printf("(%c, %c, %i), ", tuple.list->arr[i].u, tuple.list->arr[i].v, (int)tuple.list->arr[i].w);
	printf("NULL ]");
	printf(" Total weight: %zu\n", tuple.weight);
}
