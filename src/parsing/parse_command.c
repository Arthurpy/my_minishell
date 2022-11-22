/*
** EPITECH PROJECT, 2022
** minishell
** File description:
** parse args
*/

#include <string.h>
#include "my.h"

char **parse_args(char *command)
{
    char *token = NULL;
    int len = 0;
    char **cmd = malloc(sizeof(char * ) * my_strlen(command));
    token = strtok(command, " ");
    while (token) {
        cmd[len] = token;
        token = strtok(NULL, " ");
        len += 1;
    }
    cmd[len] = NULL;
    return cmd;
}