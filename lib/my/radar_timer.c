/*
** EPITECH PROJECT, 2024
** B-MUL-100-LIL-1-1-myradar-yanis.asselman
** File description:
** radar_timer
*/
#include "include/my.h"
#include "include/struct.h"
#include <stdlib.h>

int init_timer(GLOBAL_T *ALL)
{
    ALL->timer.font = sfFont_createFromFile("./content/stocky.ttf");
    if (!ALL->timer.font) {
        my_printf("Erreur de chargement de la police\n");
        return 84;
    }
    ALL->timer.timerText = sfText_create();
    if (!ALL->timer.timerText) {
        my_printf("Erreur de création du texte\n");
        return 84;
    }
    sfText_setFont(ALL->timer.timerText, ALL->timer.font);
    sfText_setCharacterSize(ALL->timer.timerText, 24);
    sfText_setPosition(ALL->timer.timerText, (sfVector2f){1770, 10});
    ALL->timer.timerClock = sfClock_create();
    return 0;
}

void update_timer(GLOBAL_T *ALL)
{
    sfTime time = sfClock_getElapsedTime(ALL->timer.timerClock);
    int minutes = sfTime_asSeconds(time) / 60;
    int seconds = (int)sfTime_asSeconds(time) % 60;
    char timerStr[6];

    timerStr[0] = '0' + minutes / 10;
    timerStr[1] = '0' + minutes % 10;
    timerStr[2] = ':';
    timerStr[3] = '0' + seconds / 10;
    timerStr[4] = '0' + seconds % 10;
    timerStr[5] = '\0';
    sfText_setString(ALL->timer.timerText, timerStr);
}

void updata_delta(GLOBAL_T *ALL)
{
    sfTime time = sfClock_getElapsedTime(ALL->graphics.updateClock);

    ALL->settings.deltaTime = sfTime_asSeconds(time);
    sfClock_restart(ALL->graphics.updateClock);
}
