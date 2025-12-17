#ifndef L8UNIONFIND
#define L8UNIONFIND
#include <stdbool.h>
#include <stddef.h>
typedef struct UnionFind UnionFind;

UnionFind *uf_init(char *roots, size_t len);
bool uf_union(UnionFind *self, char x, char y);
void uf_drop(UnionFind *self);
#endif
