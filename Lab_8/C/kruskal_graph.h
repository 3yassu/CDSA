#ifndef L8KGRAPH
#define L8KGRAPH
#include <stddef.h>
#include "list.h"
typedef struct KGraph KGraph;

KGraph *kg_init(size_t vertices);
int kg_add_edge(KGraph *self, char u, char v, size_t w);
void kg_drop(KGraph *self);
AdjTuple kruskal_mst(KGraph *self);

#endif
