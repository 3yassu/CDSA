#ifndef L8PDICT
#define L8PDICT
#include <stddef.h>
typedef struct Dict Dict;

Dict *dict_init();
int dict_init_key(Dict *self, char key);
int dict_add(Dict *self, char key, char val, size_t weight);
void dict_drop(Dict *self);
char dict_get(Dict *self, char key);
#endif
