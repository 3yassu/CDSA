#include <stdio.h>
#include <stdlib.h>
#include "prim_graph.h"
#include "p_dict.h"
#include "heap.h"
#define new(T) (T *)malloc(sizeof(T));

struct PGraph{
	size_t V;
	Dict *list;
};

PGraph *pg_init(size_t vertices){
	PGraph *ptr = new(PGraph);
	if(ptr != NULL)
		*ptr = (PGraph){.V = vertices, .list = dict_init()};
	return ptr;
}
int pg_add_edge(PGraph *self, char u, char v, size_t w){
	if(self->list == NULL)
		return 100;
	if(!dict_in(self->list, u))
		dict_init_key(self->list, u);
	if(!dict_in(self->list, v))
		dict_init_key(self->list, v);
	dict_add(self->list, u, v, w);
	dict_add(self->list, v, u, w);
	return 0;
}
AdjTuple prim_mst(PGraph *self, char start){
	if(self == NULL)
		return (AdjTuple){.list = NULL, .weight = 0};
	char *visited = (char *)malloc(sizeof(char) * self->V);
	size_t count = 1;
	size_t weight = 0;
	if(visited == NULL)
		return (AdjTuple){.list = NULL, .weight = 0};
	visited[0] = start;
	AdjList *ret = l_init();
	if(ret == NULL){
		free(visited);
		return (AdjTuple){.list = NULL, .weight = 0};
	}
	AdjHeap *hqueue = h_init();
	if(hqueue == NULL){
		free(visited);
		free(ret);
		return (AdjTuple){.list = NULL, .weight = 0};
	}
	AdjList *start_arr = dict_get(self->list, start);
	for(size_t i = 0; i<l_get_len(start_arr); i++){
		AdjVal tmp_val = l_get_item(start_arr, i);
		h_add(hqueue, start, tmp_val.v, tmp_val.w);
	}
	while(h_get_len(hqueue) > 0 && count < self->V){
		AdjVal tmp_val = h_pop(hqueue);
		if(str_in(visited, count, tmp_val.v))
			continue;
		visited[count++] = tmp_val.v;
		l_append(ret, tmp_val.u, tmp_val.v, tmp_val.w);
		weight += tmp_val.w;

		AdjList *tmp_arr = dict_get(self->list, tmp_val.v);
		for(size_t i = 0; i<l_get_len(tmp_arr); i++){
			AdjVal new_tmp_val = l_get_item(tmp_arr, i);
			if(!str_in(visited, count, new_tmp_val.v))
				h_add(hqueue, tmp_val.v, new_tmp_val.v, new_tmp_val.w);
		}
	}
	h_drop(hqueue);
	free(visited);
	return (AdjTuple){.list = ret, .weight = weight};
}
void pg_drop(PGraph *self){
	if(self == NULL)
		return;
	dict_drop(self->list);
	free(self);
}

