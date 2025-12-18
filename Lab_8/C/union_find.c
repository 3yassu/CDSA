#include <stdlib.h>
#include "uf_dict.h"
#include "union_find.h"
#define new(T) (T *)malloc(sizeof(T));
struct UnionFind {
	Dict *parent;
	Dict *rank;
};
char uf_find(UnionFind *self, char x);

UnionFind *uf_init(char *roots, size_t len){
	Dict *parent = uf_dict_init();
	if(parent == NULL)
		return NULL;
	Dict *rank = uf_dict_init();
	if(rank == NULL){
		free(parent);
		return NULL;
	}
	for(size_t i = 0; i < len; i++)
		if(uf_dict_add(parent, roots[i], roots[i]) || uf_dict_add(rank, roots[i], 0)){
			free(parent);
			free(rank);
			return NULL;
		}
	UnionFind *ptr = new(UnionFind);
	if(ptr == NULL){
			free(parent);
			free(rank);
			return NULL;
	}
	*ptr = (UnionFind){.parent = parent, .rank = rank};
	return ptr;
}
char uf_find(UnionFind *self, char x){
	if(x != uf_dict_get(self->parent, x))
		uf_dict_set(self->parent, x, uf_find(self, uf_dict_get(self->parent, x)));
	return uf_dict_get(self->parent, x);
}
bool uf_union(UnionFind *self, char x, char y){
	char rx = uf_find(self, x);
	char ry = uf_find(self, y);
	if(rx == ry)
		return false;
	char rank_x = uf_dict_get(self->rank, rx), rank_y = uf_dict_get(self->rank, ry);
	if(rank_x < rank_y)
		uf_dict_set(self->parent, rx, ry);
	else if(rank_x > rank_y)
		uf_dict_set(self->parent, ry, rx);
	else{
		uf_dict_set(self->parent, ry, rx);
		uf_dict_set(self->rank, rx, rank_x + 1);
	}
	return true;
}
void uf_drop(UnionFind *self){
	if(self == NULL)
		return;
	uf_dict_drop(self->parent);
	uf_dict_drop(self->rank);
	free(self);
}
