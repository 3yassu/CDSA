#ifndef L8UFDICT
#define L8UFDICT
typedef struct Dict Dict;

Dict *uf_dict_init();
int uf_dict_add(Dict *self, char key, char value);
void uf_dict_drop(Dict *self);
char uf_dict_get(Dict *self, char key);
void uf_dict_set(Dict *self, char key, char value);
#endif
