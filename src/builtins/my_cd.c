/*
** EPITECH PROJECT, 2021
** B-PSU-101-BDX-1-1-minishell1-arthur.py
** File description:
** my_cd.c
*/

#include "my.h"

int handle_cd_error(shell_t *shell, int err, char *pwd)
{
    char *npwd = NULL;
    if (err == 0) {
        update_env_value(shell, "OLDPWD", pwd);
        npwd = getcwd(npwd, 0);
        return update_env_value(shell, "PWD", npwd);
    } else {
        return 84;
    }
}

int change_directory(shell_t *shell, char *path, char *pwd, char *oldpwd)
{
    if (!path) {
        my_putstr("non\n");
        return 84;
    }
    int err = 0;
    err = chdir(path);
    err = handle_cd_error(shell, err, pwd);
    if (err != 0) {
        perror("cd: ");
        my_putstr(path);
        my_putstr(": Not a directory.\n");
    }
    return err;
}

int my_cd(char **args, shell_t *shell)
{
    char *path = NULL;

    char *pwd = get_env_value(shell, "PWD");
    char *oldpwd = get_env_value(shell, "OLDPWD");
    char *home = get_env_value(shell, "HOME");
    //if (args[0] != NULL && args[1] != NULL) {
    //    my_putstr("cd: Too many arguments.\n");
    //    return 84;
    //}
    if (my_strcmp(args[1], "-") == 0)
        path = oldpwd;
    else if (my_strcmp(args[1], "~") == 0)
        path = home;
    else
        path = args[1];
    return(change_directory(shell, path, pwd, oldpwd));
}