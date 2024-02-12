/*
** EPITECH PROJECT, 2024
** B-MUL-100-LIL-1-1-myradar-yanis.asselman
** File description:
** radar_moves
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


void aircraft_delays(GLOBAL_T *ALL)
{
    ENTITY_T *current = ALL->entities;

    while (current != NULL) {
        if (current->type == 'A') {
            update_aircraft_state(&(current->aircraft), fram);
        }
        current = current->next;
    }
}

void move_aircraft(Aircraft *aircraft, MovementData movement)
{
    float dirX;
    float speed_factor;
    float dirY;

    if (movement.distance > 0) {
        dirX = movement.dx / movement.distance;
        dirY = movement.dy / movement.distance;
        speed_factor = (aircraft->speed > 60) ? (aircraft->speed / 60.0) : 1.0;
        aircraft->x += dirX * speed_factor;
        aircraft->y += dirY * speed_factor;
        SRSP(aircraft->hitbox, (sfVector2f){aircraft->x, aircraft->y});
    } else {
        aircraft->x = aircraft->dest_x;
        aircraft->y = aircraft->dest_y;
    }
}

void apply_aircraft_movements(Aircraft *aircraft, int update_counter)
{
    int update_frequency;
    MovementData movement;

    update_frequency = (aircraft->speed <= 60) ? (60 / aircraft->speed) : 1;
    if (update_counter % update_frequency == 0) {
        movement.dx = aircraft->dest_x - aircraft->x;
        movement.dy = aircraft->dest_y - aircraft->y;
        MD = sqrt(movement.dx * movement.dx + movement.dy * movement.dy);
        move_aircraft(aircraft, movement);
    }
}

void apply_aircraft_movement(Aircraft *aircraft, int update_counter)
{
    int update_frequency;
    MovementData movement;

    update_frequency = (aircraft->speed <= 60) ? (60 / aircraft->speed) : 1;
    if (update_counter % update_frequency == 0) {
        movement.dx = aircraft->dest_x - aircraft->x;
        movement.dy = aircraft->dest_y - aircraft->y;
        MD = sqrt(movement.dx * movement.dx + movement.dy * movement.dy);
        apply_aircraft_movements(aircraft, update_counter);
    }
}
