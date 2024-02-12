/*
** EPITECH PROJECT, 2024
** B-MUL-100-LIL-1-1-myradar-yanis.asselman
** File description:
** radar_display
*/

#include <stdlib.h>
#include "include/my.h"
#include "include/struct.h"
#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/Graphics/Rect.h>
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Window/Export.h>
#include <SFML/Window/Types.h>
#include <SFML/System/Vector2.h>
#include <stdbool.h>
#include <math.h>

void display_aircraft(GLOBAL_T *ALL, ENTITY_T *entity)
{
    if (entity->aircraft.isActive) {
        if (ALL->settings.show_sprites) {
            SSSP(ALL->graphics.AS,
            (SFV){entity->aircraft.x, entity->aircraft.y});
            SRDS(ALL->stgs.win, ALL->graphics.aircraftSprite, NULL);
        }
        if (ASH && entity->aircraft.hitbox != NULL) {
            SRD(ALL->stgs.win, entity->aircraft.hitbox, NULL);
        }
    }
}

void display_tower(GLOBAL_T *ALL, ENTITY_T *entity)
{
    if (ALL->settings.show_sprites) {
        SSP(ALL->graphics.towerSprite,
        (sfVector2f){entity->tower.x, entity->tower.y});
        sfRenderWindow_drawSprite(ALL->stgs.win,
        ALL->graphics.towerSprite, NULL);
    }
    if (ASH && entity->tower.control_zone != NULL) {
        SRC(ALL->stgs.win, entity->tower.control_zone, NULL);
    }
}

void display_entity(GLOBAL_T *ALL, ENTITY_T *current)
{
    if (current->type == 'A') {
        display_aircraft(ALL, current);
    } else if (current->type == 'T') {
        display_tower(ALL, current);
    }
}

void display_elements(GLOBAL_T *ALL)
{
    ENTITY_T *current = ALL->entities;

    while (current != NULL) {
        display_entity(ALL, current);
        current = current->next;
    }
}
