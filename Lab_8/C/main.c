#include <stdio.h>
#include "lab7.h"

int main(){
	printf("Building Graph...\n");
	Graph *ugraph = graph_init(false);
	char uedges[7][2] = {{'A', 'B'}, {'A', 'C'}, {'A', 'D'}, {'B', 'E'}, {'D', 'F'}, {'E', 'C'}, {'F','C'}};
	for(int i = 0; i < 7; i++){
		int err = add_edge(ugraph, uedges[i][0], uedges[i][1]);
		if(err){
			graph_uninit(ugraph);
			printf("Failure: %d \n", err);
			return 100;
		}
	}
	graph_print(ugraph);
	printf("Test 1: BFS\n\\- Starting Node: 'A'\n"); //do this tmr but it's supposed to return val not freaking CArray dumbass
	val *ubfs = bfs(ugraph, 'A');
	printf("\t");
	val_print(ubfs);
	val_uninit(ubfs);
	printf("Test 2: DFS\n\\- Starting Node: 'A'\n");
	val *udfs = dfs(ugraph, 'A');
	printf("\t");
	val_print(udfs);
	val_uninit(udfs);
	graph_uninit(ugraph);
}
