#include "lab_1.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
	printf("Beginning Testing of Question 1 and Question 2: {1, 2, 3, 2, 1} and {10, 9, 1, 2, 8, 4, 3, 2, 0, -10} \n {");
	printf("Expected output: {1, 1, 2, 2, 3} and {-10, 0, 1, 2, 2, 3, 4, 8, 9, 10} \n");
	int array1[] = {10, 9, 1, 2, 8, 4, 3, 2, 0, -10};
	int array[] = {1, 2, 3, 2, 1};
	merge_sort(array1, sizeof(array1)/sizeof(int));
	int *new_array = insertion_sort_bad(array, sizeof(array)/sizeof(int));
	insertion_sort(array, sizeof(array)/sizeof(int));
	printf("Insertion Sort Output: \n {");
	for(int i = 0; i < sizeof(array)/sizeof(int); i++)
		printf("%d, ", array[i]);
	printf("NULL}\n {");
	for(int i = 0; i < sizeof(array)/sizeof(int); i++)
		printf("%d, ", *(new_array + i));
	printf("NULL}\n");
	printf("Merge Sort Output: \n {");
	for(int i = 0; i < sizeof(array1)/sizeof(int); i++)
		printf("%d, ", array1[i]);
	printf("NULL}\n");
	free(new_array);
	int numbers_merge[5000]; int numbers_insert[5000];
	for (int i = 0; i < 5000; i++) {
		numbers_insert[i] = rand();
		numbers_merge[i] = numbers_insert[i];
	}
	printf("Now beginning Question 3: time complexity testing:\n");
	clock_t start = clock();
	merge_sort(numbers_merge, 5000);
	clock_t end = clock();
	double merge_time = (double)(end - start) / CLOCKS_PER_SEC;
	start = clock();
	new_array = insertion_sort_bad(numbers_insert, 5000);
	end = clock();
	free(new_array);
	double insert_bad_time = (double)(end - start) / CLOCKS_PER_SEC;
	start = clock();
	insertion_sort(numbers_insert, 5000);
	end = clock();
	double insert_time = (double)(end - start) / CLOCKS_PER_SEC;
	printf("\tInsertion method 1 time: %f \n\tInsertion method 2 time: %f \n\tMerge time: %f \n", insert_time, insert_bad_time, merge_time);
	return 0;
}
