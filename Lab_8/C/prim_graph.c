#include <stdio.h>
#include <stdlib.h>
#include "prim_graph.h"
#include "p_dict.h"
#include "p_heap.h"
#define new(T) (T *)malloc(sizeof(T));
struct KGraph{
	size_t V;
	Dict *list;
}

KGraph *kg_init(size_t vertices){
	KGraph *ptr = new(KGraph);
	if(ptr != NULL)
		*ptr = (KGraph){.V = vertices, .list = dict_init()};
	return ptr;
}
int kg_add_edge(KGraph *self, char u, char v, size_t w){
	if(self->list == NULL)
		return 100;
	if(!dict_in(self->list, u))
		dict_init_key(self->list, u)
	if(!dict_in(self->list, v))
		dict_init_key(self->list, v)
	dict_add(self->list, u, v, w);
	dict_add(self->list, v, v, w);
}

