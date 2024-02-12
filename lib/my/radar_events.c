/*
** EPITECH PROJECT, 2024
** B-MUL-100-LIL-1-1-myradar-yanis.asselman
** File description:
** radar_events
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

void close_window(GLOBAL_T *ALL)
{
    if (ALL->stgs.event.type == sfEvtClosed) {
        sfRenderWindow_close(ALL->stgs.win);
    }
}

void q_key(GLOBAL_T *ALL)
{
    if (ALL->stgs.event.type == sfEvtKeyPressed &&
    ALL->stgs.event.key.code == sfKeyQ) {
        sfRenderWindow_close(ALL->stgs.win);
    }
}

void l_key(GLOBAL_T *ALL)
{
    if (ALL->stgs.event.type == sfEvtKeyPressed &&
    ALL->stgs.event.key.code == sfKeyL) {
        ALL->settings.show_hitbox =
        !ALL->settings.show_hitbox;
    }
}

void s_key(GLOBAL_T *ALL)
{
    if (ALL->stgs.event.type == sfEvtKeyPressed &&
    ALL->stgs.event.key.code == sfKeyS) {
        ALL->settings.show_sprites = !ALL->settings.show_sprites;
    }
}

void window_event(GLOBAL_T *ALL)
{
    while (sfRenderWindow_pollEvent(ALL->stgs.win, &ALL->stgs.event)) {
        close_window(ALL);
        q_key(ALL);
        s_key(ALL);
        l_key(ALL);
    }
}
