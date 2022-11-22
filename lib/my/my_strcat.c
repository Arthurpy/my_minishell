/*
** EPITECH PROJECT, 2021
** days07
** File description:
** Arthurpy
*/

#include "my.h"

char *my_strcat(char *dest , char const *src )
{
    int i = 0;
    int j = 0;
    int size = my_strlen(dest) + my_strlen(src);
    char *result = malloc(sizeof(char) * (size + 1));

    while (dest[i] != '\0') {
        result[i] = dest[i];
        i++;
    }
    while (src[j] != '\0' && src[j] != '\n') {
        result[i] = src[j];
        i++;
        j++;
    }
    result[i] = '\0';
    return result;
}
