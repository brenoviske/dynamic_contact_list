#include "../memory/arena.h"
#include "../ctt/ctt.h"
#include "array.h"
#include <string.h>

Array *create_array(Arena *arena , size_t cap){

    if( arena == NULL ) return NULL;

    Array *arr = arena_allocate(arena,sizeof(Array));
    if( arr == NULL ) {
        release_arena(arena);
    }

    arr->data = arena_allocate(arena,sizeof(char*) * cap);

    if( arr->data == NULL ) {
        release_arena(arena);
    }

    arr->size = 0;
    arr->cap = cap;
    return arr;
}

int push(Arena *arena , Array *arr , Ctt *ctt){
    if(
        arena == NULL ||
        arr == NULL || 
        ctt  == NULL
    ) return 1;

    if( arr->size >= arr->cap){
        
        size_t new_cap = 2 * arr->cap;
        Ctt* new_data = arena_allocate(
            arena, sizeof(Ctt) * new_cap
        );

        if( new_data==NULL) {
            release_arena(arena);
            return 1;
        }

        arr->data = new_data;
        arr->cap = new_cap;
    }

    arr->data[arr->size++] = *ctt;
    return 0 ;
}

int count_contacts(Array *arr){
    if( arr == NULL ) return 0 ; 
    return arr->size;
}

void print_all(Array *arr){

    if( arr == NULL ) return ; 

    for( int i = 0 ; i < arr->size ; ++i) print_ctt(&arr->data[i]);
    return;
}