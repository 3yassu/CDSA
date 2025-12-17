#ifndef L8KGRAPH
#define L8KGRAPH
#include <stddef.h>
typedef struct KGraph KGraph;
typedef struct AdjList AdjList;
typedef struct KrusTuple {
	AdjList *list;
	size_t weight;
}KrusTuple;

KGraph *kg_init(size_t vertices);
int kg_add_edge(KGraph *self, char u, char v, size_t w);
void kg_drop(KGraph *self);
KrusTuple kruskal_mst(KGraph *self);
void k_print(KrusTuple tuple);

void l_drop(AdjList *self);


#endif
