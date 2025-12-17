#include "uf_dict.h"
#include <stdlib.h>
#include <stdint.h>
#define new(T) (T *)malloc(sizeof(T));
#define FNV_OFFSET 14695981039346656037UL 
#define FNV_PRIME 1099511628211UL
#define list_for_each(head) for(;head != NULL; head = head->next)

typedef struct Node Node;
typedef struct item{
	char key;
	char value;
}item;
struct Node{
	item entry;
	Node *next;
};
typedef struct List{
	Node *head;
}List;
struct Dict {
	size_t len;
	size_t cap;
	List *buckets;
};

Node *node_init(item entry);
List *list_init();
int list_push(List *self, item value);
void list_push_node(List *self, Node *node);
void list_drop(List *self);
char list_get(List *self, char key);
void list_set(List *self, char key, char value);
void list_uninit_inner(List *self);
size_t hash(char id);

size_t hash(char id){
	uint64_t hash_val = FNV_OFFSET;
	hash_val ^= (uint64_t)(unsigned char)(id);
	hash_val *= FNV_PRIME;
	return (size_t)(hash_val);
}

Node *node_init(item entry){
	Node *ptr = new(Node);
	if(ptr != NULL)
		*ptr = (Node){.entry = entry, .next = NULL};
	return ptr;
}
List *list_init(){
	List *ptr = new(List);
	if(ptr != NULL)
		*ptr = (List){.head = NULL};
	return ptr;
}
int list_push(List *self, item entry){
	if(self == NULL)
		return 2;
	Node **cur = &self->head;
	while(*cur != NULL)
		cur = &(*cur)->next;
	*cur = node_init(entry);
	if(*cur == NULL)
		return 1;
	return 0;
}
void list_push_node(List *self, Node *node){
	if(self == NULL)
		return;
	Node **cur = &self->head;
	while(*cur != NULL)
		cur = &(*cur)->next;
	*cur = node;
}
char list_get(List *self, char key){
	if(self == NULL)
		return 0;
	Node *cur = self->head;
	for(;cur != NULL; cur = cur->next)
		if(cur->entry.key == key)
			return cur->entry.value;
	return 0;
}
void list_set(List *self, char key, char value){
	if(self == NULL)
		return;
	Node *cur = self->head;
	for(;cur != NULL; cur = cur->next)
		if(cur->entry.key == key)
			cur->entry.value = value;
}

Dict *dict_init(){
	Dict *ptr = new(Dict);
	if(ptr == NULL)
		return NULL;
	*ptr = (Dict){.len = 0, .cap = 0, .buckets = NULL};
	return ptr;
}
int dict_grow(Dict *self){
	if(self->cap == 0){
		self->buckets = (List *)calloc(self->cap=1, sizeof(List));
		if(self->buckets == NULL)
			return 1;
	}else{
		List *list_ptr = (List *)calloc(self->cap*2, sizeof(List));
		if(list_ptr == NULL)
			return 1;
		List *old_ptr = self->buckets;
		self->buckets = list_ptr;
		for(size_t i = 0; i < self->cap; i++){
			Node *head = old_ptr[i].head;
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
	return 0;
}
int dict_add(Dict *self, char key, char value){
	if(self == NULL)
		return 2;
	if(self->len == self->cap)
		if(dict_grow(self))
			return 1;
	size_t hash_o = hash(key)%self->cap;
	list_push(self->buckets + hash_o, (item){.key = key, .value = value});
	self->len++;
	return 0;
}
void dict_drop(Dict *self){
	if(self == NULL)
		return;
	for(size_t i = 0; i < self->cap; i++)
		if(self->buckets[i].head != NULL)
			list_uninit_inner(self->buckets + i);
	free(self->buckets);
	free(self);
}
char dict_get(Dict *self, char key){
	if(self == NULL)
		return 0;
	return list_get(self->buckets + hash(key)%self->cap, key);
}
void dict_set(Dict *self, char key, char value){
	if(self == NULL)
		return;
	list_set(self->buckets + hash(key)%self->cap, key, value);
}

void list_uninit_inner(List *self){
	if(self == NULL)
		return;
	Node *cur = self->head;
	while(cur != NULL){
		Node *next = cur->next;
		free(cur);
		cur = next;
	}
}
