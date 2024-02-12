/*
** EPITECH PROJECT, 2024
** B-MUL-100-LIL-1-1-myradar-yanis.asselman
** File description:
** radar_tower
*/
#include "include/my.h"
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include "include/struct.h"


int initialize_control_tower(ENTITY_T *new_entity, int values[])
{
    new_entity->type = 'T';
    new_entity->tower.x = values[0];
    new_entity->tower.y = values[1];
    new_entity->tower.radius = values[2];
    return 0;
}

int calculate_circle_position(CircleParams *params)
{
    if (params == NULL || params->new_entity == NULL) {
        return 84;
    }
    PN(params)->tower.control_zone_position.x =
        params->new_entity->tower.x + PTS * PTX / 2 - params->radius;
    PN(params)->tower.control_zone_position.y =
        params->new_entity->tower.y + PTH * PTY / 2 - params->radius;
    return 0;
}

int create_zone(ENTITY_T *new_entity, sfVector2f towerScale, float radius)
{
    int towerSpriteWidth = 512;
    int towerSpriteHeight = 512;
    CircleParams params = {new_entity, towerScale, towerSpriteWidth,
    towerSpriteHeight, radius};

    new_entity->tower.control_zone = sfCircleShape_create();
    if (new_entity->tower.control_zone == NULL) {
        return 84;
    }
    if (calculate_circle_position(&params) != 0) {
        return 84;
    }
    sfCircleShape_setRadius(new_entity->tower.control_zone, radius);
    sfCircleShape_setFillColor(new_entity->tower.control_zone, sfTransparent);
    sfCircleShape_setOutlineColor(new_entity->tower.control_zone, sfRed);
    sfCircleShape_setOutlineThickness(new_entity->tower.control_zone, 1.0f);
    SP(new_entity->tower.control_zone,
    PN(&params)->tower.control_zone_position);
    return 0;
}

int control_tower(char *line, ENTITY_T *new_entity, sfVector2f towerScale)
{
    int values[3];
    int num_values = extract_numbers(line, values, 3);
    int result;
    float radius;

    if (num_values != 3) {
        return 84;
    }
    result = initialize_control_tower(new_entity, values);
    if (result != 0) {
        return result;
    }
    radius = (float)values[2] / 100 * 1080;
    return create_zone(new_entity, towerScale, radius);
}
