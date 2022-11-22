/*
** EPITECH PROJECT, 2022
** mini-shell1
** File description:
** B-PSU-101
*/

#include "../include/my.h"
#include <sys/wait.h>
#include <sys/types.h>

int exec_my_bin(char *file_path, char **cmd, char **env)
{
    int i = 0;
    pid_t ls_pid = fork();
    wait(NULL);
    if (ls_pid != 0)
        return 1;
    while (file_path != NULL) {
        file_path = my_strcat(file_path, cmd[0]);
        if (execve(file_path, cmd, env) != -1 && ls_pid == 0) { //access(file_path[i], F_OK) >= 0
            exit(0);
            return i;
        }
        i++;
    }
    my_putstr("command not found...\n");
    if (ls_pid == 0)
        exit(0);
    return -1;
}

int exec_builtin(char *file_path, char **cmd, char **env)
{
    int i = 0;
    pid_t ls_pid = fork();
    wait(NULL);
    if (ls_pid != 0)
        return 1;
        if (execve(file_path, cmd, env) != -1 && ls_pid == 0) {
            exit(0);
            return i;
        }
        i++;
    my_putstr("command not found...\n");
    if (ls_pid == 0)
        exit(0);
    return -1;
}

int is_binary(char *cmd)
{
    if (cmd[0] == '.' && cmd[1] == '/')
        return 0;
    return 1;
}

shell_t *cmd_given(char *buff, shell_t *shell)
{
    if (buff[0] == '\n')
        return shell;
    buff = clean_string(buff);
    char **cmd = parse_args(buff);
    char *cmd_path = NULL;
    if (is_binary(buff) == 1)
        cmd_path = search_in_path(cmd[0], shell);
    else
        cmd_path = cmd[0];
    if (my_strcmp(buff, "cd") == 0) {
        char **cmd_cd = my_str_to_word_array(buff, ' ');
        my_cd(cmd_cd, shell);
        free(cmd_cd);
        return shell;
    }
    int ret = exec_builtin(cmd_path, cmd, shell->env);
    if (ret == -1) {
        shell->loop = -1;
        return shell;
    }
    return shell;
}