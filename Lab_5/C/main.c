#include <stdio.h>
#include "lab_5.h"
#define arr_size(arr) sizeof(arr)/sizeof(*arr)

void print_list(int* arr, int size){
	printf("{");
	for(int i = 0; i < size; i++)
		printf("%d, ", arr[i]);
	printf("NULL}\n");
}

int main(){
	printf("First Test Case: First_or_greater\n");
	int arr1[] = {2, 5, 8, 12, 16}, test1[] = {1, 2, 9, 16, 18};
	int arr2[] = {10, 20, 30, 40, 40, 50}, test2[] = {25, 40, 60};
	int arr3[] = {10, 20, 20, 20, 30, 50}, test3[] = {20, 25, 30};
	printf("\tArr1: ");
	print_list(arr1, arr_size(arr1));
	for(int i = 0; i < arr_size(test1); i++)
		printf("\t\tSEARCHING FOR K=%d, RESULT: %d\n", 
			test1[i], first_or_greater(arr1, arr_size(arr1), test1[i]));
	printf("\t Arr2: ");
	print_list(arr2, arr_size(arr2));
	for(int i = 0; i < arr_size(test2); i++)
		printf("\t\tSEARCHING FOR K=%d, RESULT: %d\n", test2[i], 
			first_or_greater(arr2, arr_size(arr2), test2[i]));
	printf("\t Arr3: ");
	print_list(arr3, arr_size(arr3));
	for(int i = 0; i < arr_size(test3); i++)
		printf("\t\tSEARCHING FOR K=%d, RESULT: %d\n", test3[i], 
			first_or_greater(arr3, arr_size(arr3), test3[i]));
	printf("Second Test Case: Binary Search Tree\n");
	BST *bst = BST_new();
	int bst_arr[] = {15, 8, 20, 5, 12, 18, 25, 7, 10, 16, 22, 28, 5};
	printf("\tPart 1: Insertion\n");
	printf("\t\tInsertion Arr: ");
	print_list(bst_arr, arr_size(bst_arr));
	for(int i = 0; i < arr_size(bst_arr); i++)
		BST_insert(bst, bst_arr[i]);
	printf("\t IS VALID: %s\n", BST_is_valid(bst) ? "True" : "False");
	int bst_search_arr[] = {5, 7, 12, 13, 22, 28};
	printf("Part 2: Searching");
	for(int i = 0; i < arr_size(bst_search_arr); i++)
		printf("\t Searching for %d: %s\n", bst_search_arr[i], BST_search(bst, bst_search_arr[i]) ? "True" : "False");
	Order or = PRE;
	BST_print(bst, or);
	or = IN;
	BST_print(bst, or);
	or = POST;
	BST_print(bst, or);
	BST_drop(bst);
	return 0;
}
