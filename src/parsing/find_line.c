/*
** EPITECH PROJECT, 2022
** mysh
** File description:
** find 
*/

#include "my.h"

int find_line(char **env, char *str)
{
    int i = 0;
    int j = 0;
    int size = my_strlen(str);
    char *temp;

    while (env[i] != NULL) {
        temp = env[i];
        j = 0;
        while (temp[j] == str[j] && temp[j] != '\0' && str[j] != '\0'){
            if (temp[j + 1] == '='){
                return i;
            }
            j++;
        }
        i++;
    }
    return -1;
}