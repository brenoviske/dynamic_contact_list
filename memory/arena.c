#include <stdlib.h>
#include <stddef.h>
#include "arena.h"

Arena *create_arena(size_t cap){

    Arena *arena = malloc(sizeof(Arena));
    
    if( arena == NULL ) return NULL;

    arena->buffer = malloc(cap);

    if( arena->buffer == NULL ) {
        free(arena);
        return NULL;
    }

    arena->cap = cap;
    arena->offset = 0;
    return arena;
}

void* arena_allocate(Arena *arena, size_t size){

    if( arena == NULL ) return NULL;

    if( arena->offset + size > arena->cap) return NULL;

    void* ptr = arena->buffer + arena->offset;
    arena->offset += size;
    return ptr;
}

void release_arena(Arena *arena){
    if( arena == NULL ) return ; 

    free(arena->buffer);
    free(arena);
    return;
}

