/*
** EPITECH PROJECT, 2023
** B-MUL-100-LIL-1-1-myradar-yanis.asselman
** File description:
** radar_clean
*/

#include "include/my.h"
#include <stdlib.h>
#include "include/struct.h"

void cleanup_aircraft_and_tower_sprites(GLOBAL_T *ALL)
{
    sfTexture *towerTexture;
    sfTexture* aircraftTexture;

    if (ALL->graphics.aircraftSprite != NULL) {
        aircraftTexture = sfSprite_getTexture(ALL->graphics.aircraftSprite);
        if (aircraftTexture != NULL) {
            sfTexture_destroy(aircraftTexture);
        }
        sfSprite_destroy(ALL->graphics.aircraftSprite);
        ALL->graphics.aircraftSprite = NULL;
    }
    if (ALL->graphics.towerSprite != NULL) {
        towerTexture = sfSprite_getTexture(ALL->graphics.towerSprite);
        if (towerTexture != NULL) {
            sfTexture_destroy(towerTexture);
        }
        sfSprite_destroy(ALL->graphics.towerSprite);
        ALL->graphics.towerSprite = NULL;
    }
}

void cleanup_other_sprites_and_textures(GLOBAL_T *ALL)
{
    for (int i = 0; i < NB; i++) {
        if (ALL->pics[i].sprite != NULL) {
            sfSprite_destroy(ALL->pics[i].sprite);
            ALL->pics[i].sprite = NULL;
        }
        if (ALL->pics[i].texture != NULL) {
            sfTexture_destroy(ALL->pics[i].texture);
            ALL->pics[i].texture = NULL;
        }
    }
    free(ALL->pics);
    ALL->pics = NULL;
}

void cleanup_window_and_music(GLOBAL_T *ALL)
{
    if (ALL->stgs.win != NULL) {
        sfRenderWindow_destroy(ALL->stgs.win);
        ALL->stgs.win = NULL;
    }
    if (ALL->son.backgroundMusic != NULL) {
        sfMusic_stop(ALL->son.backgroundMusic);
        sfMusic_destroy(ALL->son.backgroundMusic);
        ALL->son.backgroundMusic = NULL;
    }
}

void cleanup_graphics_and_music(GLOBAL_T *ALL)
{
    cleanup_aircraft_and_tower_sprites(ALL);
    cleanup_other_sprites_and_textures(ALL);
    cleanup_window_and_music(ALL);
}

static void cleanup_entities(GLOBAL_T *ALL)
{
    ENTITY_T *current = ALL->entities;
    ENTITY_T *next;

    while (current != NULL) {
        if (current->type == 'A') {
            sfRectangleShape_destroy(current->aircraft.hitbox);
        }
        if (current->type == 'T' && current->tower.control_zone != NULL) {
            sfCircleShape_destroy(current->tower.control_zone);
        }
        next = current->next;
        free(current);
        current = next;
    }
    ALL->entities = NULL;
}

void cleanup(GLOBAL_T *ALL)
{
    if (ALL->timer.timerClock != NULL) {
        sfClock_destroy(ALL->timer.timerClock);
        ALL->timer.timerClock = NULL;
    }
    if (ALL->timer.timerText != NULL) {
        sfText_destroy(ALL->timer.timerText);
        ALL->timer.timerText = NULL;
    }
    cleanup_graphics_and_music(ALL);
    cleanup_entities(ALL);
    if (ALL->timer.font != NULL) {
        sfFont_destroy(ALL->timer.font);
        ALL->timer.font = NULL;
    }
    if (ALL->graphics.updateClock != NULL) {
        sfClock_destroy(ALL->graphics.updateClock);
    }
    if (ALL->graphics.globalClock != NULL) {
    sfClock_destroy(ALL->graphics.globalClock);
    }
}
