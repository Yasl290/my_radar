/*
** EPITECH PROJECT, 2024
** B-MUL-100-LIL-1-1-myradar-yanis.asselman
** File description:
** radar_aircrafts
*/
#include "include/my.h"
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include "include/struct.h"



int initialize_aircraft(ENTITY_T *new_entity, int values[], int fram)
{
    new_entity->type = 'A';
    new_entity->aircraft.x = values[0];
    new_entity->aircraft.y = values[1];
    new_entity->aircraft.dest_x = values[2];
    new_entity->aircraft.dest_y = values[3];
    new_entity->aircraft.speed = values[4];
    new_entity->aircraft.delay = values[5];
    new_entity->aircraft.isActive = 0;
    new_entity->aircraft.start_frame = fram + (values[5] * 60);
    return 0;
}

int create_aircraft_hitbox(ENTITY_T *new_entity)
{
    new_entity->aircraft.hitbox = sfRectangleShape_create();
    if (new_entity->aircraft.hitbox == NULL) {
        return 84;
    }
    SRSS(new_entity->aircraft.hitbox, (sfVector2f){20, 20});
    sfRectangleShape_setFillColor(new_entity->aircraft.hitbox, sfTransparent);
    sfRectangleShape_setOutlineColor(new_entity->aircraft.hitbox, sfGreen);
    sfRectangleShape_setOutlineThickness(new_entity->aircraft.hitbox, 1.0f);
    SRS(HIT, (SFV){new_entity->aircraft.x, new_entity->aircraft.y});
    return 0;
}

int handle_aircraft(char *line, ENTITY_T *new_entity, int fram)
{
    int values[6];
    int num_values = extract_numbers(line, values, 6);
    int result;

    if (num_values != 6) {
        return 84;
    }
    result = initialize_aircraft(new_entity, values, fram);
    if (result != 0) {
        return result;
    }
    return create_aircraft_hitbox(new_entity);
}
