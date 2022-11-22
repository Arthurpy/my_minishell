/*
** EPITECH PROJECT, 2022
** mini-shell1
** File description:
** B-PSU-101
*/

#include <stddef.h>
#include "my.h"

char *my_strdup(char const *src)
{
    int i = 0;
    char *dest = malloc(sizeof(char) * my_strlen(src) + 1);

    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return dest;
}

char **parth_argv(char *buffer)
{
    int i = 0;
    int j = 0;
    char **argv = malloc(sizeof(char *) * (my_strlen(buffer) + 1));
    char *temp = malloc(sizeof(char) * (my_strlen(buffer) + 1));

    while (buffer[i] != '\0') {
        if (buffer[i] == ' ') {
            argv[j] = my_strdup(temp);
            i++;
            j++;
            temp = malloc(sizeof(char) * (my_strlen(buffer) + 1));
        }
        temp[i] = buffer[i];
        i++;
    }
    argv[j] = my_strdup(temp);
    argv[j + 1] = NULL;
    free(temp);
    return argv;
}