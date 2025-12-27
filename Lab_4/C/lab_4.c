#include "lab_4.h"
#include <stddef.h>

void mem_swap(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

void downheap(int *arr, int size, int index){
	int l_ind = index * 2 + 1;
	int r_ind = index * 2 + 2;
	int largest = index;
	if(l_ind < size && arr[l_ind] > arr[index])
		largest = l_ind;
	if(r_ind < size && arr[r_ind] > arr[index])
		largest = r_ind;
	if(largest != index){
		mem_swap((arr+largest), (arr+index));
		downheap(arr, size, largest);
	}
}

void heap_sort(int *arr, int size){
	if(arr != NULL){
		for(int i = size/2; i > 0; i--)
			downheap(arr, size, i - 1);
		for(int i = size-1; i > 0; i--){
			mem_swap((arr+0), (arr+i));
			downheap(arr, i, 0);
		}
	}
}

void build_max_heap(int *arr, int size){
	if(arr!=NULL)
		for(int i = size/2; i > 0; i--)
			downheap(arr, size, i - 1);
}

void downheap_min(int *arr, int size, int index){
	int l_ind = index * 2 + 1;
	int r_ind = index * 2 + 2;
	int smallest = index;
	if(l_ind < size && arr[l_ind] < arr[index])
		smallest = l_ind;
	if(r_ind < size && arr[r_ind] < arr[index])
		smallest = r_ind;
	if(smallest != index){
		mem_swap((arr+smallest), (arr+index));
		downheap_min(arr, size, smallest);
	}
}

void build_min_heap(int *arr, int size){
	if(arr!=NULL)
		for(int i = size/2; i > 0; i--)
			downheap_min(arr, size, i - 1);
}


