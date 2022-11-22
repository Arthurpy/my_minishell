/*
** EPITECH PROJECT, 2022
** B-PSU-101-BDX-1-1-minishell1-arthur.py
** File description:
** find_cmd_path
*/

#include <dirent.h>
#include <sys/types.h>
#include "my.h"


int is_here(char *dir, char *command)
{
    struct dirent *directory = NULL;
    DIR *op = NULL;

    if (!dir || !command)
        return 1;
    op = opendir(dir);
    if (op == NULL)
        return 1;
    while ((directory = readdir(op)) != NULL) {
        if (my_strcmp(directory->d_name, command) == 0 && directory->d_type != DT_DIR)
            return 0;
    }
    return 1;
}

char *search_in_path(char *binary_name, shell_t *shell)
{
    char *tmp = NULL;
    if (!binary_name || !shell || !shell->path)
        return NULL;
    for (int i = 0; shell->path[i]; i += 1) {
        if (is_here(shell->path[i], binary_name) == 0) {
            tmp = malloc(strlen(binary_name) + 2);
            tmp = strcpy(tmp, shell->path[i]);
            tmp = strcat(tmp, "/");
            tmp[strlen(tmp)] = 0;
            binary_name = strcat(tmp, binary_name);
            return binary_name;
        }
    }
    return NULL;
}
