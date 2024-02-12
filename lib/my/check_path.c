/*
** EPITECH PROJECT, 2024
** B-MUL-100-LIL-1-1-myradar-yanis.asselman
** File description:
** check_path
*/
#include "include/my.h"
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

int check_args_and_extension(int argc, char *argv[])
{
    const char *script_path;
    int len;
    int i;

    if (argc != 2) {
        my_printf("Usage: %s <script_filepath>\n", argv[0]);
        my_printf("Try with -h\n");
        return 84;
    }
    script_path = argv[1];
    len = my_strlen(script_path);
    for (i = len - 1; i >= 0 && script_path[i] != '.'; i--);
    if (i < 0 || my_strcmp(&script_path[i], ".rdr") != 0) {
        my_printf("Erreur: '%s' n'est pas un fichier valable\n", script_path);
        return 84;
    }
    return 0;
}

int open_file(char *script_path)
{
    FILE *file = fopen(script_path, "r");

    if (file == NULL) {
        my_printf("Erreur: Impossible d'ouvrir '%s'\n", script_path);
        return 84;
    }
    fclose(file);
    return 0;
}

int validate_script_path(int argc, char *argv[])
{
    int result;

    result = check_args_and_extension(argc, argv);
    if (result != 0) {
        return result;
    }
    return open_file(argv[1]);
}
