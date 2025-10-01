//lab_01.h
#ifndef LAB05
#define LAB05

typedef struct binary_node{
	int val;
	struct binary_node *left;
	struct binary_node *right
}Node;

typedef struct BST{
	Node *root;
}BST;

int binary_search(int *arr, int size, int item);

BST *BST_new();
void BST_insert(BST *self, item);
void BST_search(BST *self, item);
void BST_drop(BST *self);
//pre, post, whateverwhateverwhatever


#endif
