#ifndef ARENA_H
#define ARENA_H

#include <stddef.h>

typedef struct{
    unsigned char* buffer;
    size_t offset,cap;
}Arena;

Arena *create_arena(size_t cap);
void* arena_allocate(Arena* arena , size_t size);
void release_arena(Arena *arena);

#endif
