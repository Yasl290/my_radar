/*
** EPITECH PROJECT, 2023
** B-MUL-100-LIL-1-1-myradar-yanis.asselman
** File description:
** opening
*/

#include "include/my.h"
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

int help_display(void)
{
    FILE *file = fopen("./content/help.txt", "r");
    char ch;

    if (file == NULL) {
        my_printf("Erreur en ouvrant le fichier d'aide\n");
        return 84;
    }
    while (fread(&ch, 1, 1, file) == 1) {
        my_printf("%c", ch);
    }
    fclose(file);
    return 0;
}

int handle_help_option(int argc, char *argv[])
{
    char *arg;

    for (int i = 1; i < argc; i++) {
        arg = argv[i];
        if (arg[0] == '-' && arg[1] == 'h' && arg[2] == '\0') {
            help_display();
            return 1;
        }
    }
    return 0;
}

int launching(GLOBAL_T *ALL, int argc, char *argv[], char *envp[])
{
    int result_env;
    int valid_path;

    valid_path = validate_script_path(argc, argv);
    if (valid_path != 0) {
        return valid_path;
    }
    result_env = checking(envp);
    if (result_env == 84) {
        return 84;
    }
    if (starting(ALL) == 84)
        return 84;
    if (parse_script(argv[1], &ALL->entities) == 84)
        return 84;
    return 0;
}
