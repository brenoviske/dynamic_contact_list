#ifndef ARRAY_H
#define ARRAY_H
#include "../memory/arena.h"
#include "../ctt/ctt.h"

typedef struct{
    
    Ctt* data;
    size_t size,cap;
}Array;

Array *create_array(Arena *arena , size_t cap);
int push(Arena *arena , Array *arr, Ctt *c);
int count_contacts(Array *arr);
void search_contact(Array *arr,char* const name);
double mean_age(Array *arr);
void print_all(Array *arr);



#endif