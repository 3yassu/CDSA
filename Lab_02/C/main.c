#include "lab_02.h"
#include <stdio.h>
#include <stdlib.h>
void main(){
	printf("Question 1(a/b): Partition function test over {8, 3, 6, 2, 7, 5, 1, 4}\n")
	int array_a[] = {8, 3, 6, 2, 7, 5, 1, 4};
	int array_b[] = {8, 3, 6, 2, 7, 5, 1, 4};
	int index_a = partition_bad(array_a, 0, 7);
	int index_b = partition(array_b, 0, 7);
	printf("Partition index of (a) = %d\n Partition Index of (b) = %d\n", index_a, index_b);
	printf("Question 2: sort arrays {1, 2, 3, 2, 1}\n");
	int array[] = {1, 2, 3, 2, 1};
	quick_sort(array, 0, 4);
	
	
}
