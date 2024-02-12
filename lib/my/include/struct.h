/*
** EPITECH PROJECT, 2023
** B-MUL-100-LIL-1-1-myhunter-yanis.asselman
** File description:
** struct
*/
#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/Graphics/Rect.h>
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Window/Export.h>
#include <SFML/Window/Types.h>
#include <SFML/System/Vector2.h>
#include <stdbool.h>


#ifndef STRUCT_H_
    #define STRUCT_H_



    #define NB ALL->stgs.img_n
    #define SFFF sfTexture_createFromFile
    #define WIND ALL->stgs.win
    #define EVENT ALL->stgs.event
    #define IMG ALL->pics
    #define MODE ALL->stgs.mode
    #define SFSST sfSprite_setTexture
    #define SFMPR sfMouse_getPositionRenderWindow
    #define SDS sfRenderWindow_drawSprite
    #define SRDS sfRenderWindow_drawSprite
    #define SFS sfTime_asSeconds
    #define SCR sfClock_restart



typedef struct MovementData {
    float dx;
    float dy;
    float distance;
} MovementData;



typedef struct {
    int x;
    int y;
    int dest_x;
    int dest_y;
    int speed;
    int delay;
    int delay_counter;
    int update_counter;
    int start_frame;
    int isActive;
    sfRectangleShape *hitbox;
    float elapsedTime;
} Aircraft;



typedef struct {
    int x;
    int y;
    int radius;
    sfCircleShape *control_zone;
    sfVector2f control_zone_position;
} ControlTower;



typedef struct Entity {
    char type;
    union {
        Aircraft aircraft;
        ControlTower tower;
    };
    struct Entity *next;
} ENTITY_T;



typedef struct {
    ENTITY_T *new_entity;
    sfVector2f towerScale;
    int towerSpriteWidth;
    int towerSpriteHeight;
    float radius;
} CircleParams;



typedef struct {
    char *file_path;
    double scale_x;
    double scale_y;
    double pos_x;
    double pos_y;
} SpriteParams;



typedef struct PARAM {
    sfVideoMode mode;
    sfRenderWindow *win;
    sfEvent event;
    sfMusic *mus;
    int img_n;
} PARAMS_T;



typedef struct ELEM {
    sfTexture *texture;
    sfSprite *sprite;
    sfVector2f scale;
    sfVector2f pos;
} ELEMS_T;



typedef struct {
    sfMusic *backgroundMusic;
} SOUNDS;



typedef struct {
    sfClock *clock;
    sfClock *moveClock;
    sfFont *font;
    sfClock *timerClock;
    sfText *timerText;
} GR_T;



typedef struct {
    sfIntRect birdRect;
    sfVector2f birdPosition;
    float horizontal;
    int vertical;
    int score;
} GS_T;



typedef struct {
    sfVector2f position;
    float horizontal;
    int vertical;
} BirdState;



typedef struct {
    sfFont *font;
    sfText *timerText;
    sfClock *timerClock;
} Timer;



typedef struct {
    float deltaTime;
    bool show_hitbox;
    bool show_sprites;
} GlobalSettings;



typedef struct {
    sfClock *updateClock;
    sfClock *globalClock;
    sfSprite *aircraftSprite;
    sfSprite *towerSprite;
} GlobalGraphics;



typedef struct GLOBAL {
    PARAMS_T stgs;
    ELEMS_T *pics;
    SOUNDS son;
    GR_T resources;
    GS_T state;
    ENTITY_T *entities;
    Timer timer;
    GlobalGraphics graphics;
    GlobalSettings settings;
} GLOBAL_T;



#endif
