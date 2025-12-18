#ifndef L8PGRAPH
#define L8PGRAPH
#include <stddef.h>
#include "list.h"
typedef struct PGraph PGraph;
typedef struct AdjList AdjList;

PGraph *pg_init(size_t vertices);
int pg_add_edge(PGraph *self, char u, char v, size_t w);
void pg_drop(PGraph *self);
AdjTuple prim_mst(PGraph *self, char start);
#endif
