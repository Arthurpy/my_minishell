/*
** EPITECH PROJECT, 2022
** my_str_to_word_array
** File description:
** char * in char **
*/

#include "my.h"

char **my_str_to_char(char *str, char c)
{
    int y = -1;
    int x = 0;
    int i = 0;
    char **result = malloc(sizeof(char*) * cont_word(str));
    result[y] = malloc(sizeof(char) * size_of_word(i ,str) + 1);

    while (str[i] != '\0') {
        if (str[i] == c && str[i - 1] != c) {
            result[y][x] = '/';
            y++;
            i++;
            result[y] = malloc(sizeof(char) * size_of_word(i ,str) + 1);
            x = 0;
        }
        result[y][x] = str[i];
        i++;
        x++;
    }
    result[y][x] = '/';
    return result;
}