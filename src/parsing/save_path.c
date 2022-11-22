/*
** EPITECH PROJECT, 2021
** B-PSU-210-BDX-2-1-minishell2-arthur.py
** File description:
** save_path.c
*/

#include "my.h"

int save_path(shell_t *shell)
{
    char *data = NULL;
    char *tok = NULL;
    int len = 0;

    if (!shell || !shell->list)
        return 84;
    data = get_env_value(shell, "PATH");
    if (!data)
        return 84;
    shell->path = malloc(sizeof(char *) * my_strlen(data) + 1);
    tok = strtok(data, ":");
    while (tok) {
        shell->path[len] = tok;
        len += 1;
        tok = strtok(NULL, ":");
    }
    shell->path[len] = NULL;
    return 0;
}