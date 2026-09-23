#include "ctt.h"
#include "../memory/arena.h"
#include <string.h>
#include <stdio.h>



char* copy_string(
    Arena *arena,
    char* const name
){

    if( name == NULL ) {
        release_arena(arena);
    };

    char* str = arena_allocate(arena,strlen(name) + 1);
    if( str == NULL ) {
        release_arena(arena);
    }

    strcpy(str,name);
    return str;
}

Ctt *create_ctt(
    Arena *arena,
    char* const name,
    char* const phone,
    int age
){

    Ctt *new_ctt = arena_allocate(arena,sizeof(Ctt));
    if( new_ctt == NULL ) {
        release_arena(arena);
    }
    
    new_ctt->name = copy_string(arena,name);
    new_ctt->phone = copy_string(arena,phone);
    new_ctt->age = age;
    return new_ctt;


}

void print_ctt(Ctt *ctt){
    if( ctt == NULL ) return ;

    printf("Name:%s\n",ctt->name);
    printf("Phone:%s\n", ctt->phone);
    printf("Age:%d\n", ctt->age);

    return ;
}

