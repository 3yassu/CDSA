#include "list.h"
#include <stdio.h>
#include <stdlib.h>
#define new(T) (T *)malloc(sizeof(T));

AdjList *l_init();
char *get_edges(AdjList *self, size_t size);
int l_append(AdjList *self, char u, char v, size_t w);
void l_drop(AdjList *self);
void l_merge(AdjVal *list_1, AdjVal *list_2, size_t len_1, size_t len_2);
void l_merge_sort(AdjVal *list, size_t len);
void l_sort(AdjList *self);

struct AdjList {
	size_t len;
	size_t cap;
	AdjVal *arr;
};

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
int l_grow(AdjList *self){
	if(self->cap == 0){
		self->arr = (AdjVal *)malloc(sizeof(AdjVal)*(self->cap = 1));
		if(self->arr == NULL)
			return 1;
	}
	if(self->len >= self->cap){
		self->arr = (AdjVal *)realloc(self->arr, sizeof(AdjVal)*(self->cap *= 2));
		if(self->arr == NULL){
			printf("l_grow: Out of memory!");
			return 1;
		}
	}
	return 0;
}
int l_append(AdjList *self, char u, char v, size_t w){
	if(self == NULL)
		return 2;
	if(self->cap == self->len)
		if(l_grow(self))
			return 100;
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
size_t l_get_len(AdjList *self){
	if(self == NULL)
		return 0;
	return self->len;
}
AdjVal l_get_item(AdjList *self, size_t loc){
	if(self == NULL){
		printf("l_get_item: NULL ptr exception!\n");
		return (AdjVal){.u = 0, .v = 0, .w = 0};
	}else if(loc >= self->len){
		printf("l_get_item: Index error!!\n");
		return (AdjVal){.u = 0, .v = 0, .w = 0};
	}
	return self->arr[loc];
}

void t_print(AdjTuple tuple){
	printf("[");
	for(size_t i = 0; i < l_get_len(tuple.list); i++){
		AdjVal val = l_get_item(tuple.list, i);
		printf("(%c, %c, %zi), ", val.u, val.v, val.w);
	}
	printf("NULL ]");
	printf(" Total weight: %zu\n", tuple.weight);
}
