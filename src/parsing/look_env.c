/*
** EPITECH PROJECT, 2022
** mysh
** File description:
** find data in env
*/

#include "my.h"

char *get_env_value(shell_t *shell, char *name)
{
    if (!name || !shell)
        return NULL;
    env_t *env = shell->list->first;
    while (env) {
        if (my_strcmp(name, env->name) == 0)
            return env->data;
        env = env->next;
    }
    return NULL;
}

int update_env_value(shell_t *shell, char *name, char *value)
{
    if (!shell || !name || !value)
        return 84;
    env_t *env = shell->list->first;
    while (env) {
        if (strcmp(name, env->name) == 0) {
            env->data = value;
            return 0;
        }
        env = env->next;
    }
    return 84;
}