#ifndef L8PDICT
#define L8PDICT
#include <stddef.h>
#include "list.h" //eventually make another struct for pairs :(((((
typedef struct Dict Dict;

Dict *dict_init();
int dict_init_key(Dict *self, char key);
void dict_add(Dict *self, char key, char val, size_t weight);
bool dict_in(Dict *self, char key);
void dict_drop(Dict *self);
AdjList *dict_get(Dict *self, char key);
#endif
