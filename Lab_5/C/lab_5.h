#ifndef LAB05
#define LAB05


typedef struct Node Node;
typedef struct BST{
	Node *root;
}BST;
typedef enum Order{
	PRE,
	IN,
	POST,
}Order;

int binary_search(int *arr, int size, int item);
int first_or_greater(int *arr, int size, int item);

BST *BST_new();
int BST_is_valid(BST *self);
void BST_insert(BST *self, int item);
int BST_search(BST *self, int item);
void BST_drop(BST *self);
void BST_print(BST *self, Order order);


#endif
