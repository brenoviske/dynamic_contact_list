#include "memory/arena.h"
#include "arr/array.h"
#include"ctt/ctt.h"
#include <stdio.h>
#include <stdbool.h>


// Main part here of the current c code , that operates in some other apis of other folders within the same directory
int main(void){

    
    Arena *arena = create_arena(1024); // Allocating a big block of memory to allocate in memory future structures;
    if( arena==NULL)  return 1;

    Array* arr = create_array(arena,10);

    bool isrun = true;
    do{

        printf("1.Add Contact\n");
        printf("2.See all contacts\n");
        printf("3.Count contacts\n");
        printf("4.Exit\n");

        int op;
        printf("Enter your option of choosing here:\n");
        
        scanf("%d",&op);

        switch(op){

            case 1 :


                char name[100];
                char phone[100];
                int age;

                printf("Enter here the name , phone and age of your contact:\n");

                scanf("%99s %99s %d", name,phone,&age);

                push(arena,arr,
                    create_ctt(arena,name,phone,age));

                break;

            case 2 : print_all(arr);

            case 3 : count_contacts(arr);

            case 4: 
                    printf("Thank you for using our application\n");
                    isrun = false;

                    break;

            default:
                    printf("Invalid option of choosing\n");

                }
        
    }while(isrun);
    release_arena(arena);
    return 0;
}