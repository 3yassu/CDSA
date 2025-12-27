#include "lab_4.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
	printf("Question 1: Array testing [3, 9, 2, 1, 4, 5] \n");
	int arr_max[] = {3, 9, 2, 1, 4, 5};
	int arr_min[] = {3, 9, 2, 1, 4, 5};
	build_max_heap(arr_max, sizeof(arr_max)/sizeof(int));
	printf("\t Max Heap: [");
	for(int i = 0; i < sizeof(arr_max)/sizeof(int); i++)
		printf("%d, ", arr_max[i]);
	printf("NULL]\n");
	build_max_heap(arr_min, sizeof(arr_min)/sizeof(int));
	printf("\t Min Heap: [");
	for(int i = 0; i < sizeof(arr_min)/sizeof(int); i++)
		printf("%d, ", arr_min[i]);
	printf("NULL]\n");
	int numbers_heap[5000];
	for (int i = 0; i < 5000; i++)
		numbers_heap[i] = rand();
	printf("Now beginning Question 3: time complexity testing:\n");
	clock_t start = clock();
	heap_sort(numbers_heap, 5000);
	clock_t end = clock();
	double quick_time = (double)(end - start) / CLOCKS_PER_SEC;
	printf("\tHeapsort time: %f \n", quick_time);
	return 0;
}
