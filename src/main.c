/*
** EPITECH PROJECT, 2022
** mini-shell1
** File description:
** B-PSU-101
*/

#include "my.h"

int my_strlen_pers(char *str, char stop)
{
    int i = 0;
    
    while(str[i] != '\0' || str[i] != stop){
        i++;
    }
    return i;
}

int print_argv(char **argv)
{
    int i = 0;

    while(argv[i] != NULL){
        my_putstr(argv[i]);
        my_putchar('\n');
        i++;
    }
}

int main(int argc, char **argv, char **env)
{
    if (argc != 1 || !argv)
        return 84;
    if (shell_loop(env) == 84)
        return 84;
    return 0;
}