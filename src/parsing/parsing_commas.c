/*
** EPITECH PROJECT, 2022
** minishell
** File description:
** parse ; from command
*/

#include <string.h>
#include "my.h"

char **parse_separators(char *command)
{
    char *token = NULL;
    if (!command)
        return NULL;
    char **cmd = malloc(sizeof(char *) * my_strlen(command));
    int len = 0;
    for (token = strtok(command, ";"); token; token = strtok(NULL, ";"), len++)
        cmd[len] = token;
    cmd[len + 1] = NULL;
    return cmd;
}