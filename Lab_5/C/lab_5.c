#include "lab_5.h"
#include <stdio.h>
#include <stdlib.h>

struct Node{
	int val;
	struct binary_node *left;
	struct binary_node *right;
};

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

int first_or_greater(int *arr, int size, int item){
	int low = 0, high = size - 1, mid = low + (high - low) / 2;
	if(item > arr[high])
		return -1;
	while(low < high){
		if(arr[mid] < item)
			low = mid + 1;
		else
			high = mid;
		mid = low + (high-low)/2;
	}
	return mid;
}


BST *BST_new(){
	BST *tree = (BST*)malloc(sizeof(BST));
	*tree = (BST){NULL};
	return tree;
}

int BST_rec_is_valid(Node *cur){
	if(!cur)
		return 1;
	if(cur->left && cur->left->val >= cur->val)
		return 0;
	if(cur->right && cur->right->val <= cur->val)
		return 0;
	return BST_rec_is_valid(cur->left) && BST_rec_is_valid(cur->right);
}

int BST_is_valid(BST *self){
	if(!self)
		return 0;
	return BST_rec_is_valid(self->root);
}

Node *BST_rec_insert(Node *cur, int item){
	if(cur == NULL){
		cur = (Node*)malloc(sizeof(Node));
		if(cur != NULL){
			*cur = (Node){item, NULL, NULL};
			return cur;
		}else{
			printf("No available memory for insert!");
		}
	}
	if(item > cur->val)
		cur->right = BST_rec_insert(cur->right, item);
	else if( item < cur->val)
		cur->left = BST_rec_insert(cur->left, item);
	else
		printf("SOFT_ERROR: Tried to insert copy in BST!\n");
	return cur;
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
	return BST_rec_search(self->root, item);
}

void BST_rec_drop(Node *cur){
	if(cur == NULL)
		return;
	BST_rec_drop(cur->left);
	BST_rec_drop(cur->right);
	free(cur);
}

void BST_drop(BST *self){
	BST_rec_drop(self->root);
	free(self);
}

void BST_rec_print(Node *cur, Order order){
	if(cur == NULL)
		return;
	if(order == PRE)
		printf("%d, ", cur->val);
	BST_rec_print(cur->left, order);
	if(order == IN)
		printf("%d, ", cur->val);
	BST_rec_print(cur->right, order);
	if(order == POST)
		printf("%d, ", cur->val);
}
void BST_print(BST *self, Order order){
	if(self == NULL)
		return;
	printf("{");
	BST_rec_print(self->root, order);
	printf("NULL}\n");
}

