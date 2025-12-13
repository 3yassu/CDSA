#include <stdio.h>
#include <stdlib.h>
#include "lab6.h"

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
	*ptr = (LinkedList){.len = 0, .front = NULL};
	return ptr;
}
void list_push(LinkedList *self, val entry){
	Node *cur = self->front;
	if(cur == NULL){
	    self->front = node_init(entry);
    	if(self->front != NULL)
    		self->len += 1;
	    return;
	}
	while(cur->next != NULL)
		cur = cur->next;
	cur->next = node_init(entry);
	if(cur == NULL)
		return;
	
	self->len += 1;
}
val list_search(LinkedList *self, int key){
	Node *cur = self->front;
	while(cur != NULL && cur->entry.key != key)
		cur = cur->next;
	if(cur == NULL)
		return (val){.key = 0, .value = 0, .valid = false}; //</3
	return cur->entry;
}
void list_print(LinkedList *self){
	Node *cur = self->front;
	for(size_t i = 0; cur != NULL; i++){
		printf("\t Slot %zu: (%d, %d)\n", i, cur->entry.key, cur->entry.value);
		cur = cur->next;
	}
}
void list_uninit_inner(LinkedList *self){
	Node *cur = self->front;
	while(cur != NULL){
		Node *next = cur->next;
		free(cur);
		cur = next;
	}
}
size_t hash2(int key, size_t r){
	return r - ((size_t)key % r);
}

HashSet *hashset_init(size_t cap, size_t r){
	HashSet *ptr = (HashSet *)malloc(sizeof(HashSet));
	if(ptr == NULL){
		printf("hashset_init: No Memory Available Hash\n");
		return NULL;
	}
	val *val_ptr = (val *)calloc(cap, sizeof(val));
	if(val_ptr == NULL){
		printf("hashset_init: No Memory Available val\n");
		free(ptr);
		return NULL;
	}
	*ptr = (HashSet){.len = 0, .cap = cap, .arr = val_ptr, .r = r};
	return ptr;
}
void hashset_insert(HashSet *self, int key, val value){
	size_t hash1 = ((size_t)key)%(self->cap);
	size_t hash = hash1;
	size_t i = 1;
	while(self->arr[hash].valid == true){
		hash = (hash1 + i * hash2(key, self->r))%(self->cap);
		i++;
	}
	self->arr[hash] = value;
}
val hashset_search(HashSet *self, int key){
	size_t hash1 = (size_t)key%(self->cap);
	size_t hash = hash1;
	size_t i = 1;
	while(self->arr[hash].valid == true && self->arr[hash].key != key){
		hash = (hash1 + i * hash2(key, self->r))%(self->cap);
		i++;
	}
	return self->arr[hash];
}
void hashset_print(HashSet *self){
	for(size_t i = 0; i < self->cap; i++)
		if(self->arr[i].valid == true)
			printf("Slot[%zu] -> (%d, %d)\n", i, self->arr[i].key, self->arr[i].value);
		else
		    printf("Slot[%zu] -> NULL\n", i);
}
void hashset_uninit(HashSet *self){
	free(self->arr);
	free(self);
}

HashTable *hashtable_init(size_t cap){
	HashTable *ptr = (HashTable *)malloc(sizeof(HashTable));
	if(ptr == NULL){
		printf("hashtable_init: No Memory Avaialble HashTable\n");
		return NULL;
	}
	LinkedList *list_ptr = (LinkedList *)calloc(cap, sizeof(LinkedList));
	if(list_ptr == NULL){
		printf("hashtable_init: No Memory Available LinkedList\n");
		free(ptr);
		return NULL;
	}
	*ptr = (HashTable){.len = 0, .cap = cap, .buckets = list_ptr};
	return ptr;
}
void hashtable_insert(HashTable *self, int key, val value){
	size_t hash = (size_t)key%self->cap;
	list_push(self->buckets + hash, value);
}
void hashtable_print(HashTable *self){
	for(size_t i = 0; i < self->cap; i++){
		printf("HashSlot %zu:\n", i);
		if(self->buckets[i].front != NULL)
			list_print(self->buckets + i);
		else
			printf("\t NULL\n");
	}	
}
void hashtable_uninit(HashTable *self){
	for(size_t i = 0; i < self->cap; i++)
		if(self->buckets[i].front != NULL)
			list_uninit_inner(self->buckets + i);
	free(self->buckets);
	free(self);
}
val hashtable_search(HashTable *self, int key){
	size_t hash = (size_t)key % self->cap;
	return list_search(self->buckets + hash, key);
}


