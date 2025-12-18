#include "heap.h"
#include <stdlib.h>
#include <stdio.h>
#define new(T) (T *)malloc(sizeof(T));

static void h_upheap(AdjHeap *self, size_t ind);
static void h_downheap(AdjHeap *self, size_t ind);
struct AdjHeap {
	size_t len;
	size_t cap;
	AdjVal *arr;
};

AdjHeap *h_init(){
	AdjHeap *ptr = new(AdjHeap);
	if(ptr == NULL)
		return NULL;
	*ptr = (AdjHeap){.len = 0, .cap = 0, .arr = NULL};
	return ptr;
}
int h_grow(AdjHeap *self){
	if(self->cap == 0){
		self->arr = (AdjVal *)malloc(sizeof(AdjVal)*(self->cap = 1));
		if(self->arr == NULL)
			return 1;
	}
	if(self->len >= self->cap){
		self->arr = (AdjVal *)realloc(self->arr, sizeof(AdjVal)*(self->cap *= 2));
		if(self->arr == NULL){
			printf("h_grow: Out of memory!");
			return 1;
		}
	}
	return 0;
}

int h_add(AdjHeap *self, char u, char v, size_t w){
	if(self == NULL)
		return 2;
	if(self->cap == self->len)
		if(h_grow(self))
			return 100;
	self->arr[self->len] = (AdjVal){.u = u, .v = v, .w = w};
	h_upheap(self, self->len);
	self->len++;
	return 0;
}
void h_upheap(AdjHeap *self, size_t ind){
	if(ind == 0)
		return;
	size_t par = (ind-1)/2;
	if(self->arr[ind].w <= self->arr[par].w){
		AdjVal tmp = self->arr[ind];
		self->arr[ind] = self->arr[par];
		self->arr[par] = tmp;
		h_upheap(self, par);
	}
}
AdjVal h_pop(AdjHeap *self){
	if(self == NULL)
		return (AdjVal){.u = 0, .v = 0, .w = 0};
	AdjVal ret = self->arr[0];
	self->arr[0] = self->arr[--self->len];
	h_downheap(self, 0);
	return ret;
}
void h_downheap(AdjHeap *self, size_t ind){
	size_t b = 2;
	if(ind*2+1 >= self->len)
		return;
	else if(ind*2+2 >= self->len || self->arr[ind*2+1].w <= self->arr[ind*2+2].w)
		b = 1;
	size_t child = ind * 2 + b;
	if(self->arr[ind].w >= self->arr[child].w){
		AdjVal tmp = self->arr[ind];
		self->arr[ind] = self->arr[child];
		self->arr[child] = tmp;
		h_downheap(self, child);
	}
}
void h_drop(AdjHeap *self){
	if(self != NULL){
		free(self->arr);
		free(self);
	}
}
size_t h_get_len(AdjHeap *self){
	if(self == NULL)
		return 0;
	return self->len;
}
void h_print(AdjHeap *self){
	printf("[");
	for(size_t i = 0; i < self->len; i++){
		AdjVal val = self->arr[i];
		printf("(%c, %c, %zi), ", val.u, val.v, val.w);
	}
	printf("NULL ]\n");
}

