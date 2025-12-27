#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "lab_3.h"

int main(){
	printf("Question 1(a/b): Partition function test over {8, 3, 6, 2, 7, 5, 1, 4}\n");
	int array_a[] = {8, 3, 6, 2, 7, 5, 1, 4};
	int array_b[] = {8, 3, 6, 2, 7, 5, 1, 4};
	int index_a = rselect_bad(array_a, 0, 7, 4);
	int index_b = rselect(array_b, 0, 7, 4);
	printf("Partition index of (a) = %d\n Partition Index of (b) = %d\n", index_a, index_b);
	int numbers_quick[5000];
	for (int i = 0; i < 5000; i++)
		numbers_quick[i] = rand();
	printf("Now beginning Question 3: time complexity testing:\n");
	clock_t start = clock();
	rselect(numbers_quick, 0, 4999, 4);
	clock_t end = clock();
	double quick_time = (double)(end - start) / CLOCKS_PER_SEC;
	printf("\tRselect time: %f \n", quick_time);
	return 0;
}
