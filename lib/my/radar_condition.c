/*
** EPITECH PROJECT, 2023
** B-MUL-100-LIL-1-1-myradar-yanis.asselman
** File description:
** radar_condition
*/
#include "include/my.h"
#include "include/struct.h"
#include <stdbool.h>

bool check_status(Aircraft *aircraft)
{
    return aircraft->isActive &&
    (aircraft->x != aircraft->dest_x || aircraft->y != aircraft->dest_y);
}

bool reach_aircraft(GLOBAL_T *ALL)
{
    ENTITY_T *current = ALL->entities;

    while (current != NULL) {
        if (current->type == 'A' && check_status(&(current->aircraft))) {
            return false;
        }
        current = current->next;
    }
    return true;
}
