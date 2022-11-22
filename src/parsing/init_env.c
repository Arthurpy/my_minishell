/*
** EPITECH PROJECT, 2021
** B-PSU-210-BDX-2-1-minishell2-arthur.py
** File description:
** init_env.c
*/

#include <string.h>
#include "my.h"

int add_node(char *name, char *data, shell_t *shell)
{
    env_t *node = NULL;
    if (!name || !data || !shell)
        return 84;
    node = malloc(sizeof(env_t));
    node->name = malloc(sizeof(char) * my_strlen(name) + 1);
    node->data = malloc(sizeof(char) * my_strlen(data) + 1);
    node->name = my_strcpy(node->name, name);
    node->data = my_strcpy(node->data, data);
    node->next = NULL;
    node->prev = NULL;
    if (!shell->list->first) {
        shell->list->first = node;
        shell->list->last = node;
        return 0;
    } else {
        shell->list->last->next = node;
        node->prev = shell->list->last;
        shell->list->last = node;
        return 0;
    }
}

int add_env_data(char *env, shell_t *shell)
{
    char *name = NULL;
    char *data = NULL;
    char *tok = NULL;

    tok = strtok(env, "=");
    if (tok == NULL)
        return 84;
    name = tok;
    tok = strtok(NULL, "=");
    if (tok == NULL)
        data = "";
    else
        data = tok;
    return add_node(name, data, shell);
}

shell_t *init_env(char **env, shell_t *shell)
{
    if (!shell || !env)
        return NULL;
    int i = 0;
    shell->list = malloc(sizeof(list_env_t));
    shell->list->size = 0;
    shell->list->first = NULL;
    shell->list->last = NULL;

    while (env[i] != NULL) {
        add_env_data(env[i], shell);
        shell->list->size += 1;
        i++;
    }
    return shell;
}