#include <stdlib.h>


void mem_swap(int *one, int *two){
    int temp = *one;
    *one = *two;
    *two = temp;
}

int partition_bad(int *list, int low, int high){
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

int partition(int *list, int low, int high){
	for(int i = low; i < high; i++)
		if(*(list + i) <= *(list + high)){
			mem_swap((list + i), (list + low));
			low++;
		}
	mem_swap((list + high), (list + low));
	return low;
}

void quick_sort(int *list, int low, int high){
	if(low < high){
		int part = partition(list, low, high);
		quick_sort(list, low, part - 1);
		quick_sort(list, part + 1, high);
	}
}
