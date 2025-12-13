#include <stdlib.h>


void mem_swap(int *one, int *two){
    int temp = *one;
    *one = *two;
    *two = temp;
}

int partition_bad(int *list, int low, int high, int pivot){
	mem_swap((list + pivot), (list + high));
	int size = high + 1 - low;
	int *new_list = (int*)malloc(sizeof(int)*size);
	for(int i = 0; i < high; i++){
		 if(*(list + i) <= *(list + high)){
			*new_list = *(list + i);
			low++; new_list++;
		}
	}
	*new_list = *(list + high);
	new_list++;
	for(int i = 0; i < high; i++){
		if(*(list + i) > *(list + high)){
			*new_list = *(list + i);
			new_list++;
		}
	}
	new_list -= size;
	for(int i = 0; i < high + 1; i++, new_list++, list++)
		*list = *new_list;
	free(new_list);
	return low;
}

int partition(int *list, int low, int high, int pivot){
	mem_swap((list + pivot), (list + high));
	for(int i = low; i < high; i++)
		if(*(list + i) <= *(list + high)){
			mem_swap((list + i), (list + low));
			low++;
		}
	mem_swap((list + high), (list + low));
	return low;
}

int rselect(int *list, int size, int low, int high, int k){
	if(low == high)
		return list[low];
	int pivot_index = (rand()%(high - low + 1)) + low;
	pivot_index = partition(list, low, high, pivot_index);
	int rank = pivot_index-low;
	if(k==rank)
		return list[pivot_index];
	else if(k < rank)
		return rselect(list, size, low, pivot_index+1, k);
	else
		return rselect(list, size, pivot_index-1, high, k-rank-1);
}
