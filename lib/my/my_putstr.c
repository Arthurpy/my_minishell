/*
** EPITECH PROJECT, 2021
** days04
** File description:
** my_putstr.c
*/

#include "../../include/my.h"

int  my_putstr(char  const *str)
{
    int i = 0;

    if (str == NULL) {
        printf("null\n");
        return 84;
    }    
    while  (str[i] != '\0'){
        my_putchar(str[i]);
        i++;
    }
    return(0);
}