#include <stdio.h>
#include <stdlib.h>
#include "kruskal_graph.h"
#include "union_find.h"
#define new(T) (T *)malloc(sizeof(T));

struct KGraph {
	size_t V;
	AdjList *edges;
};
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
AdjTuple kruskal_mst(KGraph *self){
	l_sort(self->edges);
	AdjList *ret = l_init();
	if(ret == NULL)
		return (AdjTuple){.list = NULL, .weight = 0};
	char *edge_l = get_edges(self->edges, self->V);
	if(edge_l == NULL){
		free(ret);
		return (AdjTuple){.list = NULL, .weight = 0};
	}
	UnionFind *union_find = uf_init(edge_l, self->V);
	free(edge_l);
	if(union_find == NULL){
		free(ret);
		return (AdjTuple){.list = NULL, .weight = 0};
	}
	size_t weight = 0, count = 0;
	for(size_t i = 0; i < l_get_len(self->edges); i++){
		if(count > self->V - 1)
			break;
		AdjVal val = l_get_item(self->edges, i);
		char u = val.u, v = val.v, w = val.w;
		if(uf_union(union_find, u, v)){
			l_append(ret, u, v, w);
			count += 1;
			weight += w;
		}
	}
	uf_drop(union_find);
	return (AdjTuple){.list = ret, .weight = weight};
}
