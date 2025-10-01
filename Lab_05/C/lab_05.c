#include "lab_05.h"
#include <stdio.h>
#include <stdlib.h>

int binary_search(int *arr, int size, int item){
	int low = 0, high = size - 1;
	while(low <= high){
		int mid = low + (high-low)/2;
		if(arr[mid] > item)
			high = mid - 1;
		else if(arr[mid] < item)
			low = mid + 1;
		else
			return mid;
	}
	return -1;
}

BST *BST_new(){
	BST *tree = (BST*)malloc(sizeof(BST));
	*tree = {NULL};
	return tree;
}

void BST_rec_insert(Node *cur, int item){
	if(cur == NULL){
		cur = (Node*)malloc(sizeof(Node));
		if(cur != NULL){
			cur = (Node){item, NULL, NULL};
		}else{
			printf("No available memory for insert!");
		}
	}else{
		if(item > cur->val)
			return BST_rec_insert(cur->right, item);
		else
			return BST_rec_insert(cur->left, item)
	}
}

void BST_insert(BST *self, int item){
	if(self->root == NULL){
		self->root = (Node*)malloc(sizeof(Node));
		if(self->root != NULL){
			*self->root = (Node){item, NULL, NULL};
		}else{
			printf("No available memory for insert!");
		}
	}else
		BST_rec_insert(self->root, item);
}

int BST_rec_search(Node *cur, int item){
	if(cur == NULL)
		return 0;
	if(cur->val == item)
		return 1;
	else if(cur->val < item)
		return BST_rec_search(cur->right, item);
	else
		return BST_rec_search(cur->left, item);
}

int BST_search(BST *self, int item){
	BST_rec_search(self->root, item);
}

void BST_rec_drop(Node *cur){
	if(cur == NULL)
		return;
	BST_rec_drop(cur->left);
	BST_rec_drop(cur->right);
	free(cur);
}

void BST_drop(BST* self){
	BST_rec_drop(self->root);
	free(self);
}

