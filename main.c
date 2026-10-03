#include "arr/array.h"
#include "memory/arena.h"
#include "ctt/ctt.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    /* Arena for all program allocations */
    Arena *arena = create_arena(1024);

    if (arena == NULL)
        return 1;


    /* Create dynamic contact array */
    Array *new_arr = create_array(arena, 4);

    if (new_arr == NULL) {
        release_arena(arena);
        return 1;
    }


    printf("Command Line Interface\n");
    printf("----------------------\n");
    printf("Commands:\n");
    printf("ADD <name> <phone> <age>\n");
    printf("COUNT\n");
    printf("MEAN\n");
    printf("SHOW\n");
    printf("QUIT\n");


    char input[100];


    while (1)
    {
        printf("\n> ");

        if (fgets(input, sizeof input, stdin) == NULL)
            break;

        /* Remove newline */
        input[strcspn(input, "\n")] = '\0';

        /* Get command */
        char *command = strtok(input, " ");

        if (command == NULL)
            continue;


        /* =========================
           ADD
           ========================= */

        if (strcmp(command, "ADD") == 0)
        {
            char *name = strtok(NULL, " ");
            char *phone = strtok(NULL, " ");
            char *age_str = strtok(NULL, " ");

            if (name == NULL || phone == NULL || age_str == NULL)
            {
                printf("Usage: ADD <name> <phone> <age>\n");
                continue;
            }

            int age = atoi(age_str);

            Ctt *ctt = create_ctt(
                arena,
                name,
                phone,
                age
            );

            if (ctt == NULL)
            {
                printf("Failed to create contact.\n");
                continue;
            }

            if (push(arena, new_arr, ctt) != 0)
            {
                printf("Failed to add contact.\n");
                continue;
            }

            printf("Contact added successfully.\n");
        }


        /* =========================
           COUNT
           ========================= */

        else if (strcmp(command, "COUNT") == 0)
        {
            printf(
                "Contacts: %d\n",
                count_contacts(new_arr)
            );
        }


        /* =========================
           MEAN
           ========================= */

        else if (strcmp(command, "MEAN") == 0)
        {
            if (new_arr->size == 0)
            {
                printf("No contacts available.\n");
                continue;
            }

            printf(
                "Mean age: %.2f\n",
                mean_age(new_arr)
            );
        }


        /* =========================
           SHOW
           ========================= */

        else if (strcmp(command, "SHOW") == 0)
        {
            if (new_arr->size == 0)
            {
                printf("No contacts available.\n");
                continue;
            }

            print_all(new_arr);
        }


        /* =========================
           QUIT
           ========================= */

        else if (strcmp(command, "QUIT") == 0)
        {
            printf("Goodbye!\n");
            break;
        }


        /* =========================
           UNKNOWN COMMAND
           ========================= */

        else
        {
            printf("Unknown command: %s\n", command);
        }
    }


    release_arena(arena);

    return 0;
}