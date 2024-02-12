/*
** EPITECH PROJECT, 2023
** B-MUL-100-LIL-1-1-myradar-yanis.asselman
** File description:
** radar_wind
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

extern int fram;

void handle_window_events(GLOBAL_T *ALL)
{
    window_event(ALL);
}

void draw_background(GLOBAL_T *ALL)
{
    if (ALL->pics[0].sprite != NULL) {
        sfRenderWindow_drawSprite(ALL->stgs.win, ALL->pics[0].sprite, NULL);
    }
}

bool air_reach(GLOBAL_T *ALL)
{
    return reach_aircraft(ALL);
}

static void game_update(GLOBAL_T *ALL)
{
    aircraft_delays(ALL);
    aircrafts_position(ALL);
}

void window_menu(GLOBAL_T *ALL)
{
    bool aircraft_reached = false;

    sfWindow_setFramerateLimit((sfWindow *)ALL->stgs.win, 60);
    while (sfRenderWindow_isOpen(ALL->stgs.win) && !aircraft_reached) {
        ALL->settings.deltaTime = SFS(SCR(ALL->graphics.globalClock));
        handle_window_events(ALL);
        sfRenderWindow_clear(ALL->stgs.win, sfBlack);
        updata_delta(ALL);
        game_update(ALL);
        fram++;
        draw_background(ALL);
        display_elements(ALL);
        aircraft_reached = air_reach(ALL);
        if (aircraft_reached) {
            sfRenderWindow_close(ALL->stgs.win);
        }
        update_timer(ALL);
        sfRenderWindow_drawText(ALL->stgs.win, ALL->timer.timerText, NULL);
        sfRenderWindow_display(ALL->stgs.win);
    }
}
