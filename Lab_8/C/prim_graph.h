#ifndef L8PGRAPH
#define L8PGRAPH
#include <stddef.h>
typedef struct PGraph PGraph;
typedef struct AdjList AdjList;
typedef struct PrimTuple {
	AdjList *list;
	size_t weight;
}PrimTuple;

KGraph *kg_init(size_t vertices);
int kg_add_edge(KGraph *self, char u, char v, size_t w);
void kg_drop(KGraph *self);
KrusTuple kruskal_mst(KGraph *self);
void k_print(KrusTuple tuple);

void l_drop(AdjList *self);


#endif
