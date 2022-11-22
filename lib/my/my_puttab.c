/*
** EPITECH PROJECT, 2022
** my_puttab.c
** File description:
** my_puttab
*/

#include <unistd.h>
#include "../../include/my.h"

int  my_puttab(char **tab)
{
    int i = 0;

    while (tab[i] != NULL)
    {
        my_putstr(tab[i]);
        if (tab[i + 1] != NULL)
            my_putchar('\n');
        i++;
    }
    return 0;
}