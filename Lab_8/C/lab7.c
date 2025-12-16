#include "lab7.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#define FNV_OFFSET 14695981039346656037UL 
#define FNV_PRIME 1099511628211UL
#define list_for_each(head) for(;head != NULL; head = head->next)
typedef struct Node Node;
Node *node_init(val entry);
size_t hash(char id);
bool hashtable_in(HashTable *self, char key);
bool list_in(LinkedList *self, char key);

void rec_dfs(Graph *self, char start, CArray *list);

size_t hash(char id){
	uint64_t hash_val = FNV_OFFSET;
	hash_val ^= (uint64_t)(unsigned char)(id);
	hash_val *= FNV_PRIME;
	return (size_t)(hash_val);
}
struct val{
	char key;
	CArray *value; //</3
};

struct Node { //int cuz I don't wanna do type generics #define node(type)whatevr
	val entry;
	struct Node *next;
};

struct LinkedList{
	Node *front;
};

struct HashTable {
	size_t len;
	size_t cap;
	LinkedList *buckets;
};

struct CArray {
	size_t len;
	size_t cap;
	char *arr;
};

struct Graph {
	HashTable *graph;
	bool directed;
};

CArray *carray_init(){
	CArray *ptr = (CArray *)malloc(sizeof(CArray));
	if(ptr == NULL){
		printf("carray_init: No Memory Avaialblee\n");
		return NULL;
	}
	*ptr = (CArray){.len = 0, .cap = 0, .arr = NULL};
	return ptr; 
}
bool carray_in(CArray *self, char value){
	if(self == NULL)
		return false;
	for(size_t i = 0; i < self->len; i++)
		if(self->arr[i] == value)
			return true;
	return false;
}

void carray_uninit(CArray *self){
	if(self == NULL)
		return;
	free(self->arr);
	free(self);
}
int carray_append(CArray *self, char value){
	if(self == NULL)
		return 2;
	if(self->cap == 0){
		self->arr = (char *)malloc(sizeof(char) * 1);
		if(self->arr == NULL)
			return 1;
		self->cap = 1;
	}
	else if(self->len == self->cap){
		char *ptr = self->arr;
		self->arr = (char *)malloc(sizeof(char) * self->cap * 2);
		if(self->arr == NULL){
			free(ptr);
			return 1;
		}
		for(size_t i = 0; i < self->len; i++)
			self->arr[i] = ptr[i];
		self->cap *= 2;
		free(ptr);
	}
	self->arr[self->len] = value;
	self->len++;
	return 0;
}
void carray_print(CArray *self){
	if(self->len == 0){
		printf("\n");
		return;
	}
	printf("['%c'", self->arr[0]);
	for(size_t i = 1; i < self->len; i++)
		printf(", '%c'", self->arr[i]);
	printf("]\n");
}
void val_uninit(val *self){
	carray_uninit(self->value);
	free(self);
}
void val_print(val *self){
	printf("'%c': ", self->key);
	carray_print(self->value);
}
Node *node_init(val entry){
	Node *ptr = (Node *)malloc(sizeof(Node));
	if(ptr == NULL){
		printf("node_init: No Memory Available\n");
		return NULL;
	}
	*ptr = (Node){.entry = entry, .next = NULL};
	return ptr;
}

LinkedList *list_init(){
	LinkedList *ptr = (LinkedList *)malloc(sizeof(LinkedList));
	if(ptr == NULL){
		printf("list_init: No Memory Available\n");
		return NULL;
	}
	*ptr = (LinkedList){.front = NULL};
	return ptr;
}
int list_push(LinkedList *self, val entry){
	if(self == NULL)
		return 2;
	Node **cur = &self->front;
	while(*cur != NULL)
		cur = &(*cur)->next;
	*cur = node_init(entry);
	if(*cur == NULL)
		return 1;
	return 0;
}
void list_push_node(LinkedList *self, Node *node){
	if(self == NULL)
		return;
	Node **cur = &self->front;
	while(*cur != NULL)
		cur = &(*cur)->next;
	*cur = node;
}
CArray *list_get(LinkedList *self, char key){
	if(self == NULL)
		return NULL;
	Node *cur = self->front;
	while(cur != NULL && cur->entry.key != key)
		cur = cur->next;
	if(cur != NULL)
		return cur->entry.value;
	return NULL;
}
bool list_in(LinkedList *self, char key){
	if(self == NULL)
		return false;
	Node *cur = self->front;
	while(cur != NULL && cur->entry.key != key)
		cur = cur->next;
	if(cur != NULL)
		return true;
	return false;
}
void list_uninit_inner(LinkedList *self){
	if(self == NULL)
		return;
	Node *cur = self->front;
	while(cur != NULL){
		Node *next = cur->next;
		carray_uninit(cur->entry.value);
		free(cur);
		cur = next;
	}
}

HashTable *hashtable_init(){
	HashTable *ptr = (HashTable *)malloc(sizeof(HashTable));
	if(ptr == NULL){
		printf("hashtable_init: No Memory Avaialble\n");
		return NULL;
	}
	*ptr = (HashTable){.len = 0, .cap = 0, .buckets = NULL};
	return ptr;
}
int hashtable_insert(HashTable *self, char key, val value){
	if(self == NULL)
		return 2;
	if(self->buckets == NULL){
		self->buckets = list_init();
		if(self->buckets == NULL){
			printf("hashtable_insert: No Memory Avaialble LinkedList Arr\n");
			return 1;
		}
		self->cap = 1;
	}
	else if(hashtable_in(self, key)){
			carray_uninit(value.value);
			return 0;
	}
	else if(self->len >= self->cap/2){
		LinkedList *list_ptr = (LinkedList *)calloc(self->cap*2, sizeof(LinkedList));
		LinkedList *old_ptr = self->buckets;
		self->buckets = list_ptr;
		for(size_t i = 0; i < self->cap; i++){
			Node *head = old_ptr[i].front;
			Node *prev = NULL;
			list_for_each(head){
				if(prev)
					prev->next = NULL;
				size_t hash_new = hash(head->entry.key)%(self->cap*2);
				list_push_node(self->buckets + hash_new, head);
				prev = head;
			}
		}
		self->cap *= 2;
		free(old_ptr);
	} 
	size_t hash_o = hash(key)%self->cap;
	list_push(self->buckets + hash_o, value);
	self->len++;
	return 0;
}
bool hashtable_in(HashTable *self, char key){
	if(self == NULL)
		return NULL;
	size_t hash_o = hash(key) % self->cap;
	return list_in(self->buckets + hash_o, key);	
}
void hashtable_uninit(HashTable *self){
	if(self == NULL)
		return;
	for(size_t i = 0; i < self->cap; i++)
		if(self->buckets[i].front != NULL)
			list_uninit_inner(self->buckets + i);
	free(self->buckets);
	free(self);
}
CArray *hashtable_get(HashTable *self, char key){
	size_t hash_o = hash(key)%self->cap;
	return list_get(self->buckets + hash_o, key);
}

Graph *graph_init(bool directed){
	Graph *ptr = (Graph *)malloc(sizeof(Graph));
	if(ptr == NULL){
		printf("graph_init: No Memory Avaialble\n");
		return NULL;
	}
	*ptr = (Graph){.graph = hashtable_init(), .directed = directed};
	return ptr;
}
//Now the freaking homework begins gosh C can be a pain sometimes
int add_edge(Graph *self, char u, char v){
	if(self == NULL)
		return 2;
	hashtable_insert(self->graph, u, (val){.key = u, .value = carray_init()});
	CArray *arr_u = hashtable_get(self->graph, u);
	if(arr_u == NULL)
		return 1;
	if(!carray_in(arr_u, v))
		carray_append(arr_u, v);
	if(!self->directed){
		hashtable_insert(self->graph, v, (val){.key = v, .value = carray_init()});
		CArray *arr_v = hashtable_get(self->graph, v);
		if(arr_v == NULL)
			return 1;
		if(!carray_in(arr_v, u))
			carray_append(arr_v, u);
	}
	return 0;
}
val *bfs(Graph *self, char start){
	val *ptr = (val *)malloc(sizeof(val));
	if(ptr == NULL)
		return NULL;
	CArray *list = carray_init();
	carray_append(list, start);
	*ptr = (val){.key = start, .value = list};
	size_t j = 0;
	CArray *tmp = hashtable_get(self->graph, start);
	while(1){
		for(size_t i = 0; i < tmp->len; i++){
			if(!carray_in(list, tmp->arr[i]))
				carray_append(list, tmp->arr[i]);
			if(j >= list->len)
				return ptr;
		}
		tmp = hashtable_get(self->graph, list->arr[j]);
		j++;
	}
}
val *dfs(Graph *self, char start){
	val *ptr = (val *)malloc(sizeof(val));
	if(ptr == NULL)
		return NULL;
	CArray *list = carray_init();
	carray_append(list, start);
	CArray *tmp = hashtable_get(self->graph, start);
	for(size_t i = 0; i < tmp->len; i++){
		if(!carray_in(list, tmp->arr[i])){
			carray_append(list, tmp->arr[i]);
			rec_dfs(self, tmp->arr[i], list);
		}
	}
	*ptr = (val){.key = start, .value = list};
	return ptr;
}
void rec_dfs(Graph *self, char start, CArray *list){
	CArray *tmp = hashtable_get(self->graph, start);
	for(size_t i = 0; i < tmp->len; i++){
		if(!carray_in(list, tmp->arr[i])){
			carray_append(list, tmp->arr[i]);
			rec_dfs(self, tmp->arr[i], list);
		}
	}
}
void graph_uninit(Graph *self){
	if(self == NULL)
		return;
	hashtable_uninit(self->graph);
	free(self);
}

void hashtable_print(HashTable *self){
	for(size_t i = 0; i < self->cap; i++){
		if(self->buckets[i].front != NULL)
			list_print(self->buckets + i);
	}	
}
void list_print(LinkedList *self){
	Node *cur = self->front;
	printf("\t");
	for(size_t i = 0; cur != NULL; i++, cur = cur->next, printf("\t"))
		val_print(&cur->entry);
	printf("\n");
}
void graph_print(Graph *self){
	printf("Graph:\n");
	hashtable_print(self->graph);
	printf("Directed: %s\n", self->directed ? "true" : "false");
}
