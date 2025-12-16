//LISTT
#ifndef L8LIST
#define L8LIST
typedef struct List List;
typedef struct AdjList AdjList;

typedef struct val {
	char key;
	AdjList *arr;
} val;

AdjList *al_init();
int al_append(AdjList *self, char u, int weight);
void al_drop(AdjList *self);
#endif
