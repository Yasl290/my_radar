/*
** EPITECH PROJECT, 2023
** B-MUL-100-LIL-1-1-myradar-yanis.asselman
** File description:
** radar_init
*/

#include "include/my.h"
#include "include/struct.h"
#include <stdlib.h>



int allocate_images_memory(GLOBAL_T *ALL)
{
    ALL->pics = malloc(sizeof(*ALL->pics) * 100);
    if (!ALL->pics) {
        return 84;
    }
    return 0;
}

int load_images(GLOBAL_T *ALL)
{
    if (load_background_images(ALL) == 84) {
        return 84;
    }
    if (load_entity_sprites(ALL) == 84) {
        return 84;
    }
    return 0;
}

int load_and_allocate_images(GLOBAL_T *ALL)
{
    if (allocate_images_memory(ALL) == 84) {
        return 84;
    }
    if (load_images(ALL) == 84) {
        free(ALL->pics);
        return 84;
    }
    return 0;
}

int init_sprite(GLOBAL_T *ALL)
{
    if (load_and_allocate_images(ALL) == 84) {
        return 84;
    }
    if (load_font(&(ALL->resources), "./content/stocky.ttf") == 84) {
        free(ALL->pics);
        return 84;
    }
    return 0;
}
