/*
** EPITECH PROJECT, 2024
** B-MUL-100-LIL-1-1-myradar-yanis.asselman
** File description:
** radar_parse_line
*/

#include "include/my.h"
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include "include/struct.h"


int create_new_entity(ENTITY_T *entities)
{
    ENTITY_T *new_entity = malloc(sizeof(ENTITY_T));

    if (!new_entity) {
        my_printf("allocation error\n");
        return NULL;
    }
    return new_entity;
}

int proccess(char *line, ENTITY_T **entities, int fram)
{
    int result;
    ENTITY_T *new_entity = create_new_entity(entities);

    if (new_entity == NULL) {
        return 84;
    }
    if (line[0] == 'A' || line[0] == 'T') {
        result = add_item(line, new_entity, entities, fram);
        if (result != 0) {
            free(new_entity);
        }
        return result;
    } else {
        free(new_entity);
        return 0;
    }
}

int parse_line(char *line, ENTITY_T **entities)
{
    int fram = 0;

    return proccess(line, entities, fram);
}
