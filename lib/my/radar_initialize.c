/*
** EPITECH PROJECT, 2024
** B-MUL-100-LIL-1-1-myradar-yanis.asselman
** File description:
** radar_initialize
*/


#include "include/my.h"
#include "include/struct.h"
#include <stdlib.h>

void init_entity_sprites(GLOBAL_T *ALL)
{
    sfTexture *aircraftTexture;
    sfTexture *towerTexture;
    sfVector2f aircraftScale = {0.07f, 0.07f};
    sfVector2f towerScale = {0.10f, 0.10f};

    ALL->graphics.aircraftSprite = sfSprite_create();
    ALL->graphics.towerSprite = sfSprite_create();
    aircraftTexture = sfTexture_createFromFile("./content/plane.png", NULL);
    towerTexture = sfTexture_createFromFile("./content/tower.png", NULL);
    sfSprite_setTexture(ALL->graphics.aircraftSprite, aircraftTexture, sfTrue);
    sfSprite_setTexture(ALL->graphics.towerSprite, towerTexture, sfTrue);
    sfSprite_setScale(ALL->graphics.aircraftSprite, aircraftScale);
    sfSprite_setScale(ALL->graphics.towerSprite, towerScale);
}

int load_background_images(GLOBAL_T *ALL)
{
    sfTexture *bgTexture = sfTexture_createFromFile("./content/bg.jpg", NULL);
    sfSprite *bgSprite = sfSprite_create();

    if (!bgTexture) {
        my_printf("Erreur de chargement de l'image de fond\n");
        return 84;
    }
    sfSprite_setTexture(bgSprite, bgTexture, sfTrue);
    ALL->pics[0].texture = bgTexture;
    ALL->pics[0].sprite = bgSprite;
    ALL->pics[0].scale.x = 1;
    ALL->pics[0].scale.y = 1;
    ALL->pics[0].pos.x = 0;
    ALL->pics[0].pos.y = 0;
    NB = 1;
    return 0;
}

int load_entity_sprites(GLOBAL_T *ALL)
{
    ST *aircraftTexture = SFF("./content/plane.png", NULL);
    ST *towerTexture = SFF("./content/tower.png", NULL);
    sfVector2f aircraftScale = {0.010f, 0.010f};
    sfVector2f towerScale = {0.010f, 0.010f};

    ALL->graphics.aircraftSprite = sfSprite_create();
    ALL->graphics.towerSprite = sfSprite_create();
    if (!aircraftTexture || !towerTexture) {
        my_printf("Erreur de chargement des textures\n");
        return 84;
    }
    sfSprite_setTexture(ALL->graphics.aircraftSprite, aircraftTexture, sfTrue);
    sfSprite_setTexture(ALL->graphics.towerSprite, towerTexture, sfTrue);
    sfSprite_setScale(ALL->graphics.aircraftSprite, aircraftScale);
    sfSprite_setScale(ALL->graphics.towerSprite, towerScale);
    return 0;
}
