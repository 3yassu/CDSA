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
	Dict *parent = dict_init();
	if(parent == NULL)
		return NULL;
	Dict *rank = dict_init();
	if(rank == NULL){
		free(parent);
		return NULL;
	}
	for(size_t i = 0; i < len; i++)
		if(dict_add(parent, roots[i], roots[i]) || dict_add(rank, roots[i], 0)){
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
	if(x != dict_get(self->parent, x))
		dict_set(self->parent, x, uf_find(self, dict_get(self->parent, x)));
	return dict_get(self->parent, x);
}
bool uf_union(UnionFind *self, char x, char y){
	char rx = uf_find(self, x);
	char ry = uf_find(self, y);
	if(rx == ry)
		return false;
	char rank_x = dict_get(self->rank, rx), rank_y = dict_get(self->rank, ry);
	if(rank_x < rank_y)
		dict_set(self->parent, rx, ry);
	else if(rank_x > rank_y)
		dict_set(self->parent, ry, rx);
	else{
		dict_set(self->parent, ry, rx);
		dict_set(self->rank, rx, rank_x + 1);
	}
	return true;
}
void uf_drop(UnionFind *self){
	if(self == NULL)
		return;
	dict_drop(self->parent);
	dict_drop(self->rank);
	free(self);
}
