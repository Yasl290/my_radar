/*
** EPITECH PROJECT, 2023
** B-MUL-100-LIL-1-1-myhunter-yanis.asselman
** File description:
** env_check
*/
#include "include/my.h"
#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "include/struct.h"


bool check_f(const char *var_loop, const char *display_f, int len_disp)
{
    for (int j = 0; j < len_disp; j++) {
        if (var_loop[j] != display_f[j]) {
            return false;
        }
    }
    return true;
}

bool check_env(char *envp[])
{
    const char *display_f = "DISPLAY=";
    int len_disp = 8;

    for (int i = 0; envp[i] != NULL; i++) {
        if (check_f(envp[i], display_f, len_disp)) {
            return true;
        }
    }
    return false;
}

int checking(char *envp[])
{
    if (!check_env(envp)) {
        my_printf("Aucun environnement d'affichage détecté.\n");
        return 84;
    }
    return 0;
}
