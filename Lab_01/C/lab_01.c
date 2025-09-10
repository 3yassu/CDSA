//lab_01.c
#include "lab_01.h"
#include <stdlib.h>



void shift(int *list, int index, int item) {
	int temp;
	for(int i = 0; i < index; i++, list++){
		temp = *list;
		if(temp > item){
			*list = item;
			item = temp;
		}
	}
	*list = item;
}

int *insertion_sort_bad(int *list, int size){
	int *return_list = (int*)malloc(sizeof(int) * size);
	for(int i = 0; i < size; i++, list++)
		shift(return_list, i, *list);
	return return_list;
}

void insertion_sort(int *list, int size) {
    for(int i = 0; i < size; i++)
        shift(list, i, *(list+i));
}

void merge(int *list_1, int *list_2, int size_1, int size_2){
    int combo_size = (size_1 + size_2); int j = size_1; int k = size_2;
    int *temp_list = (int*)malloc(sizeof(int) * combo_size);
    for(int i = 0; i < combo_size && (j+k) > 0;i++){
        if(k == 0 || (j > 0 && k > 0 && *(list_1 + size_1 - j) < *(list_2 + size_2 - k))){
            *(temp_list + i) = *(list_1 + size_1 - j); j--;
        }else{
            *(temp_list + i) = *(list_2 + size_2 - k); k--;
        }
    }
    for(int i = 0; i < combo_size; i++, list_1++, temp_list++){
        *list_1 = *temp_list; //works because *list_2's pointer begins 4 bytes after list_1
    }
}

void merge_sort(int *list, int size){
    if(size == 1)
        return;
    int middle = (size)/2;
    int max = size%2 ? (middle + 1) : middle;
    merge_sort(list, middle); merge_sort((list+middle), max);
    merge(list, (list+middle), middle, max); 
}
