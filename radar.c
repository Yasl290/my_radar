/*
** EPITECH PROJECT, 2023
** B-MUL-100-LIL-1-1-myradar-yanis.asselman
** File description:
** radar
*/
#include "lib/my/include/my.h"
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include "lib/my/include/struct.h"

int fram;

int main(int argc, char *argv[], char *envp[])
{
    GLOBAL_T ALL;

    ALL.entities = NULL;
    if (handle_help_option(argc, argv) == 1) {
        return 0;
    }
    if (launching(&ALL, argc, argv, envp) == 84) {
        return 84;
    }
    sound_init(&ALL);
    window_menu(&ALL);
    cleanup(&ALL);
    my_printf("End of the program\n");
    return 0;
}
