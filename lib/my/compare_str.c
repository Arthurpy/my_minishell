/*
** EPITECH PROJECT, 2022
** mini-shell1
** File description:
** B-PSU-101
*/

#include "my.h"

int my_strcmp(char *str1, char *str2)
{
    int i = 0;
    int size1 = my_strlen(str1);
    int size2 = my_strlen(str2);
    if(size1 != size2)
        return 0;
    while(str1[i] != '\0' && str2[i] != '\0'){
        if(str1[i] != str2[i])
            return 0;
        i++;
    }
    return 1;
}