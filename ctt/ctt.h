#ifndef CTT_H
#define CTT_H
#include "../memory/arena.h"

typedef struct{
    char* name;
    char* phone;
    int age;
}Ctt;

char* copy_string(Arena *arena, char* const name);
Ctt *create_ctt(
    Arena *arena,
    char* const name,
    char* const phone,
    int age
);
void print_ctt(Ctt *ctt);


#endif