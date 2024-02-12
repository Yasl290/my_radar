/*
** EPITECH PROJECT, 2023
** B-MUL-100-LIL-1-1-myradar-yanis.asselman
** File description:
** radar_sound
*/
#include "include/struct.h"
#include "include/my.h"

int sound_init(GLOBAL_T *ALL)
{
    ALL->son.backgroundMusic = sfMusic_createFromFile("./content/ost.ogg");
    if (!ALL->son.backgroundMusic) {
        my_printf("Failed to load background music\n");
        return 84;
    } else {
        sfMusic_setVolume(ALL->son.backgroundMusic, 5.0f);
        sfMusic_play(ALL->son.backgroundMusic);
    }
}
