/*
** EPITECH PROJECT, 2024
** B-MUL-100-LIL-1-1-myradar-yanis.asselman
** File description:
** radar_values
*/
#include "include/my.h"
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include "include/struct.h"

int get_number_from_line(char *line, int *index, char *number)
{
    int num_len = 0;

    while (line[*index] != '\0' && !MI(line[*index]) && line[*index] != '-') {
        (*index)++;
    }
    while (my_isdigit(line[*index]) || line[*index] == '-') {
        number[num_len] = line[*index];
        num_len++;
        (*index)++;
    }
    number[num_len] = '\0';
    if (num_len > 0) {
        return my_atoi(number);
    }
    return -1;
}

int extract_numbers(char *line, int *values, int max_values)
{
    int index = 0;
    int num_index = 0;
    char number[20];
    int num_value;

    while (line[index] != '\0' && num_index < max_values) {
        num_value = get_number_from_line(line, &index, number);
        if (num_value != -1) {
            values[num_index] = num_value;
            num_index++;
        }
    }
    return num_index;
}
