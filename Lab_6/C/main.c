#include "lab6.h"
#include <stdio.h>
int main(){   
    printf("Q1: Double hash\n");
    printf("\tInsert:\n");
    int keys_double[] = {15, 20, 33, 44, 55, 65};
    HashSet *hash_set = hashset_init(11, 7);
    for(size_t i = 0; i < sizeof(keys_double)/sizeof(int); i++)
        hashset_insert(hash_set, keys_double[i], (val){.key = keys_double[i], .value = keys_double[i]*10, .valid = true});
    hashset_print(hash_set);
    printf("\tSearch: 20, 44, 56\n");
    int set_search[] = {20, 44, 56};
    for(size_t i = 0; i < sizeof(set_search)/sizeof(int); i++){
        val check = hashset_search(hash_set, set_search[i]);
        printf("Result: Key %d -> ", set_search[i]);
        if(check.valid == true)
            printf("Value: (%d, %d)\n", check.key, check.value);
        else
            printf("Key not found!\n");
    }
    hashset_uninit(hash_set);
    //
    printf("\nQ2: Choose your own hash (Open hash!)\n");
    printf("\tInsert:\n");
    HashTable *hash_table = hashtable_init(12);
    int keys_open[] = {10, 17, 24, 30, 38, 40, 52, 59, 66, 72};
    for(size_t i = 0; i < sizeof(keys_open)/sizeof(int); i++)
        hashtable_insert(hash_table, keys_open[i], (val){.key = keys_open[i], .value = keys_open[i]*10, .valid = true});
    hashtable_print(hash_table);
    printf("\tSearch: 24, 72, 80\n");
    int table_search[] = {24, 72, 80};
    for(size_t i = 0; i < sizeof(table_search)/sizeof(int); i++){
        val check = hashtable_search(hash_table, table_search[i]);
        printf("Result: Key %d -> ", table_search[i]);
        if(check.valid == true)
            printf("Value: (%d, %d)\n", check.key, check.value);
        else
            printf("Key not found!\n");
    }
    hashtable_uninit(hash_table);
    return 0;
}
