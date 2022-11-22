/*
** EPITECH PROJECT, 2021
** B-PSU-210-BDX-2-1-minishell2-arthur.py
** File description:
** my_env.c
*/

#include "my.h"

int my_env(shell_t *shell)
{
    env_t *node = shell->list->first;
    while (node) {
        my_putstr(node->name);
        my_putstr("=");
        my_putstr(node->data);
        my_putstr("\n");
        node = node->next;
    }
    return 0;
}