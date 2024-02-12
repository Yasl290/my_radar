/*
** EPITECH PROJECT, 2023
** B-MUL-100-LIL-1-1-myradar-yanis.asselman
** File description:
** radar_parsing
*/

#include "include/my.h"
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include "include/struct.h"

extern int fram;


int handle_entity_type(char *line, ENTITY_T *new_entity, int fram)
{
    sfVector2f towerScale = {0.10f, 0.10f};

    if (line[0] == 'A') {
        return handle_aircraft(line, new_entity, fram);
    } else if (line[0] == 'T') {
        return control_tower(line, new_entity, towerScale);
    } else {
        return 84;
    }
}

int add_item(char *line, ENTITY_T *new_entity, ENTITY_T **entities, int fram)
{
    int result = handle_entity_type(line, new_entity, fram);

    if (result == 0) {
        new_entity->next = *entities;
        *entities = new_entity;
    } else {
        free(new_entity);
    }
    return result;
}
