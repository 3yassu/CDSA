#include <stdio.h>
#include "kruskal_graph.h"
#include "prim_graph.h"
int main(){
	printf("Building Kruskal's Graph...\n");
	KGraph *kgraph = kg_init(7);
	char kedges[12][2] = {{'A', 'B'}, {'A', 'D'}, {'A', 'F'}, {'B', 'D'}, {'B', 'E'}, {'B', 'C'}, {'B', 'G'}, {'C', 'E'}, {'C', 'G'}, {'D', 'E'}, {'F', 'G'}, {'F', 'B'}};
	size_t kweights[12] = {2, 4, 5, 1, 3, 7, 4, 10, 6, 2, 1, 8};
	for(int i = 0; i < 12; i++){
		int err = kg_add_edge(kgraph, kedges[i][0], kedges[i][1], kweights[i]);
		if(err){
			kg_drop(kgraph);
			printf("Failure: %d \n", err);
			return err;
		}
	}
	printf("Test Case 1: Kruskal MST\n");
	AdjTuple mst = kruskal_mst(kgraph);
	t_print(mst);
	l_drop(mst.list);
	kg_drop(kgraph);
	printf("Building Prim's Graph...\n");
	printf("Test Case 2: Prim MST\n");
	PGraph *pgraph = pg_init(7);
	for(int i = 0; i < 12; i++){
		int err = pg_add_edge(pgraph, kedges[i][0], kedges[i][1], kweights[i]);
		if(err){
			pg_drop(pgraph);
			printf("Failure: %d \n", err);
			return err;
		}
	}
	AdjTuple pmst = prim_mst(pgraph, 'A');
	t_print(pmst);
	l_drop(pmst.list);
	pg_drop(pgraph);
}
