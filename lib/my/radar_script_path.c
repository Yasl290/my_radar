/*
** EPITECH PROJECT, 2024
** B-MUL-100-LIL-1-1-myradar-yanis.asselman
** File description:
** radar_script_path
*/
#include "include/my.h"
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include "include/struct.h"

FILE* open_script(const char *filepath)
{
    FILE* file = fopen(filepath, "r");

    if (!file) {
        my_printf("Erreur: Impossible d'ouvrir '%s'\n", filepath);
    }
    return file;
}

int process_line(char *line, ENTITY_T **entities)
{
    int result = parse_line(line, entities);

    if (result != 0) {
        free(line);
        return result;
    }
    return 0;
}

int read_and_parse_file(FILE *file, ENTITY_T **entities)
{
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    int process_result;

    if (file == NULL) {
        return 84;
    }
    while (true) {
        read = getline(&line, &len, file);
        if (read == -1) {
            break;
        }
        process_result = process_line(line, entities);
        if (process_result != 0) {
            return process_result;
        }
    }
    free(line);
    return 0;
}

int parse_script(const char *filepath, ENTITY_T **entities)
{
    int result;
    FILE *paf = open_script(filepath);

    if (paf == NULL) {
        return 84;
    }
    result = read_and_parse_file(paf, entities);
    fclose(paf);
    return result;
}
