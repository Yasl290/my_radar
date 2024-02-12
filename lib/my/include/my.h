/*
** EPITECH PROJECT, 2023
** my.h
** File description:
** All mylib prototypes.
*/
#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/Graphics/Rect.h>
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Window/Export.h>
#include <SFML/Window/Types.h>
#include <SFML/System/Vector2.h>
#include <stdarg.h>
#include <sys/stat.h>
#include "struct.h"
#include <stdbool.h>

#ifndef MY_H_
    #define MY_H_
/*

Struct my_printf

*/

struct my_flags {
    int minus;
    int plus;
    int space;
    int diese;
    int zero;
};

typedef struct get_flag {
    struct my_flags my_flag;
    int my_width;
    int my_precision;
    char my_length;
    char my_specifier;
} get_flag_t;

/*

Struct my_printf

*/



int my_putchar(char c);
int my_isneg(int nb);
int my_put_nbr(int nb);
void my_swap(int *a, int *b);
int my_putstr(char const *str);
int my_strlen(char const *str);
int my_getnbr(char const *str);
void my_sort_int_array(int *tab, int size);
int my_compute_power_rec(int nb, int power);
int my_compute_square_root(int nb);
int my_is_prime(int nb);
int my_find_prime_sup(int nb);
char *my_strcpy(char *dest, char const *src);
char *my_strncpy(char *dest, char const *src, int n);
char *my_revstr(char *str);
char *my_strstr(char *str, char const *to_find);
int my_strcmp(char const *s1, char const *s2);
int my_strncmp(char const *s1, char const *s2, int n);
char *my_strupcase(char *str);
char *my_strlowcase(char *str);
char *my_strcapitalize(char *str);
int my_str_isalpha(char const *str);
int my_str_isnum(char const *str);
int my_str_islower(char const *str);
int my_str_isupper(char const *str);
int my_str_isprintable(char const *str);
int my_showstr(char const *str);
int my_showmem(char const *str, int size);
char *my_strcat(char *dest, char const *src);
char *my_strncat(char *dest, char const *src, int nb);
int my_strlen_bis(char const *str);
int my_is_prime_bis(int nb);
char **my_str_to_word_array(char const *str);
char **copy_array(char const *str, char **array);
int my_is_alphanum(char c);
char my_charlowcase(char c);
int my_printf(const char *format, ...);
int print_d(const char *format, va_list list, int i, get_flag_t flag);
int print_i(const char *format, va_list list, int i, get_flag_t flag);
int print_s(const char *format, va_list list, int i, get_flag_t flag);
int print_c(const char *format, va_list list, int i, get_flag_t flag);
int print_percent(const char *format, va_list list, int i, get_flag_t flag);
int print_p(const char *format, va_list list, int i, get_flag_t flag);
int my_unsigned_nbr(unsigned int nb);
int print_u(const char *specifier, va_list list, int i, get_flag_t flag);
int print_hex_address(void *ptr);
int print_o(const char *specifier, va_list list, int i, get_flag_t flag);
int my_unsigned_o(unsigned int nb);
int print_lowerx(const char *specifier, va_list list, int i, get_flag_t flag);
int my_unsigned_x(unsigned int nb);
int print_upperx(const char *specifier, va_list list, int i, get_flag_t flag);
int my_unsigned_upperx(unsigned int nb);
int loop_upperx(unsigned int nb, char *hexupper, int *y, int count);
int loop_x(unsigned int nb, char *hexlower, int *y, int count);
get_flag_t get_all_flags(const char *format, int *i);
int front_padding_int(get_flag_t flag, int arg_int);
int back_padding_int(get_flag_t flag, int arg_int);
int front_padding_str(get_flag_t flag, char *arg_str);
int back_padding_str(get_flag_t flag, char *arg_str);
int front_padding_char(get_flag_t flag);
int back_padding_char(get_flag_t flag);
int print_space_plus(get_flag_t flag, int arg_int);
int printf_f(double nb, int precision);
int print_f(const char *specifier, va_list list, int i, get_flag_t flag);
int plus_flag(get_flag_t flag, int arg_int);
int space_flag(get_flag_t flag, int arg_int);
int loop_printf_f(double *nb, int *precision);
int print_upperf(const char *specifier, va_list list, int i, get_flag_t flag);
int printf_upperf(double nb, int precision);
int loop_printf_upperf(double *nb, int *precision);
int file_rp(const char *fpth);
int opening_check(int argc, char *argv[]);
int my_atoi(const char *str);
bool my_isdigit(int c);



/*

Functions my_radar

*/

    #define SSSP sfSprite_setPosition
    #define SFV sfVector2f
    #define AS aircraftSprite
    #define SRD sfRenderWindow_drawRectangleShape
    #define SSP sfSprite_setPosition
    #define SRC sfRenderWindow_drawCircleShape
    #define SRS sfRectangleShape_setPosition
    #define SRSS sfRectangleShape_setSize
    #define HIT new_entity->aircraft.hitbox
    #define ST sfTexture
    #define SFF sfTexture_createFromFile
    #define SRSP sfRectangleShape_setPosition
    #define MD movement.distance
    #define PN(params) ((params)->new_entity)
    #define PTS params->towerSpriteWidth
    #define PTH params->towerSpriteHeight
    #define PTY params->towerScale.y
    #define PTX params->towerScale.x
    #define SP sfCircleShape_setPosition
    #define MI my_isdigit
    #define ASH ALL->settings.show_hitbox





int add_item(char *line, ENTITY_T *new_entity, ENTITY_T **entities, int fram);


int parse_line(char *line, ENTITY_T **entities);



/*
Functions to check at the beginning
*/
int help_display(void);
int checking(char *envp[]);
int validate_script_path(int argc, char *argv[]);
int handle_help_option(int argc, char *argv[]);

int launching(GLOBAL_T *ALL, int argc, char *argv[], char *envp[]);
/*
Functions to check at the beginning
*/



int my_min(int a, int b);

void init_entity_sprites(GLOBAL_T *ALL);
int load_background_images(GLOBAL_T *ALL);
int load_entity_sprites(GLOBAL_T *ALL);

void display_elements(GLOBAL_T *ALL);




/*
Functions to check the env
*/
int checking(char *envp[]);
bool check_env(char *envp[]);
bool check_f(const char *var_loop, const char *display_f, int len_disp);
/*
Functions to check the env
*/


int init_sprite(GLOBAL_T *ALL);

int sound_init(GLOBAL_T *ALL);

int starting(GLOBAL_T *ALL);


void cleanup(GLOBAL_T *ALL);

void window_menu(GLOBAL_T *ALL);


void aircrafts_position(GLOBAL_T *ALL);


void aircraft_delays(GLOBAL_T *ALL);

void update_aircraft_state(Aircraft *aircraft, int fram);




bool reach_aircraft(GLOBAL_T *ALL);

void aircraft_delays(GLOBAL_T *ALL);




int init_timer(GLOBAL_T *ALL);

void update_timer(GLOBAL_T *ALL);

void updata_delta(GLOBAL_T *ALL);

void window_event(GLOBAL_T *ALL);



/*
Parsing radar functions
*/
int parse_script(const char *filepath, ENTITY_T **entities);
int parse_line(char *line, ENTITY_T **entities);
int extract_numbers(char *line, int *values, int max_values);
int control_tower(char *line, ENTITY_T *new_entity, sfVector2f towerScale);
int handle_aircraft(char *line, ENTITY_T *new_entity, int fram);



/*
Parsing radar functions
*/

#endif /* MY_H_ */
