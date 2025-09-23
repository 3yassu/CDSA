void mem_swap(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

void downheap_max(int *arr, int size, int index){
	int l_ind = index * 2 + 1;
	int r_ind = index * 2 + 2;
	int largest = index;
	if(l_ind < size && arr[l_ind] > arr[index]){
		largest = l_ind;
	}
	if(r_ind < size && arr[r_ind] > arr[index]){
		largest = r_ind;
	}
	if(largest != index){
		mem_swap((arr+largest), (arr+index));
		downheap_max(arr, size, largest);
	}
}
void downheap_min(int *arr, int size, int index){
	int l_ind = index * 2 + 1;
	int r_ind = index * 2 + 2;
	int smallest = index;
	if(l_ind < size && arr[l_ind] < arr[index]){
		smallest = l_ind;
	}
	if(r_ind < size && arr[r_ind] < arr[index]){
		smallest = r_ind;
	}
	if(smallest != index){
		mem_swap((arr+smallest), (arr+index));
		downheap_max(arr, size, smallest);
	}
}
void heap_sort(int *arr, int size){
	for(int i = size/2; i > 0; i--){
		downheap_max(arr, size, i - 1);
	}
	for(int i = size-1; i > 0; i--){
		mem_swap((arr+0), (arr+i));
		downheap_max(arr, i, 0);
	}
}
