/*
** EPITECH PROJECT, 2022
** mini-shell1
** File description:
** B-PSU-101
*/

#include "../include/my.h"

int compare_str(char *str1, char *str2)
{
    int i = 0;
    int size1 = my_strlen(str1);
    int size2 = my_strlen(str2);
    if(size1 != size2){
        return 0;
    }
    while(str1[i] != '\0' && str2[i] != '\0'){
        if(str1[i] != str2[i])
            return 0;
        i++;
    }
    return 1;
}

char *get_dir(void)
{
    char *dir = NULL;
    char *pwd = NULL;
    char *token = NULL;
    pwd = getcwd(pwd, 0);
    if (!pwd)
        return "";
    token = strtok(pwd, "/");
    while (token) {
        dir = token;
        token = strtok(NULL, "/");
    }
    return dir;
}

shell_t *get_cmd(shell_t *shell)
{
    size_t size = 1000;
    char *buffer = NULL;
    char **cmd_list = NULL;
    buffer = malloc(sizeof(char) * size);
    my_putstr("\x1b[34m");
    my_putstr("[my mini-shell]$ \x1b[91m\x1b[1m");
    my_putstr(get_dir());
    my_putstr("\x1b[34m ✗➜ \x1b[0m");
    if (getline(&buffer, &size, stdin) == -1) {
        shell->loop = 1;
        return shell;
    }
    cmd_list = parse_separators(buffer);
    for (int i = 0; cmd_list[i]; i++) {
        shell = cmd_given(cmd_list[i], shell);
    }
    return shell;
}

shell_t *init_shell(char **env)
{
    shell_t *shell = malloc(sizeof(shell_t));
    int size = 0;
    int i = 0;
    if (init_env(env, shell) == NULL)
        return NULL;
    if (save_path(shell) == 84)
        return NULL;
    for (; env[size] != NULL; size++);
    shell->env = malloc(sizeof(char *) * (size + 1));
    while(env[i] != NULL) {
        shell->env[i] = malloc(sizeof(char) * (my_strlen(env[i])));
        shell->env[i] = env[i];
        i++;
    }
    shell->loop = 0;
    return shell;
}

int shell_loop(char **env)
{
    if (!env)
        return 84;
    shell_t *shell = init_shell(env);

    if (!shell)
        return 84;
    while(shell->loop == 0) {
        get_cmd(shell);
        if (shell->loop != 0) {
            my_putstr("exit\n");
            break;
        }
    }
    return 0;
}
