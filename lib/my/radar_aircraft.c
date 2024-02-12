/*
** EPITECH PROJECT, 2023
** B-MUL-100-LIL-1-1-myradar-yanis.asselman
** File description:
** radar_aircraft
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
#include <math.h>
#include <time.h>

extern int fram;


void update_aircraft_state(Aircraft *aircraft, int fram)
{
    if (!aircraft->isActive && fram >= aircraft->start_frame) {
        aircraft->isActive = 1;
    }
}

void up_aircraft(Aircraft *aircraft, float deltaTime)
{
    aircraft->elapsedTime += deltaTime;
    if (!aircraft->isActive && aircraft->elapsedTime >= aircraft->delay) {
        aircraft->isActive = 1;
    }
    if (aircraft->isActive) {
        apply_aircraft_movement(aircraft, deltaTime);
    }
}

void aircrafts_position(GLOBAL_T *ALL)
{
    ENTITY_T *current = ALL->entities;

    while (current != NULL) {
        if (current->type == 'A') {
            up_aircraft(&(current->aircraft), ALL->settings.deltaTime);
        }
        current = current->next;
    }
}
