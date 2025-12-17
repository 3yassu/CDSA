#ifndef L8UFDICT
#define L8UFDICT
typedef struct Dict Dict;

Dict *dict_init();
int dict_add(Dict *self, char key, char value);
void dict_drop(Dict *self);
char dict_get(Dict *self, char key);
void dict_set(Dict *self, char key, char value);
#endif
