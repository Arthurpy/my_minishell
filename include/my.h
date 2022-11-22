/*
** EPITECH PROJECT, 2022
** B-PSU-101-BDX-1-1-minishell1-arthur.py
** File description:
** my
*/

#ifndef MY_H_
    #define MY_H_

    #include <stdlib.h>
    #include <unistd.h>
    #include <stdio.h>
    #include <string.h>
    #include <sys/wait.h>
    #include <sys/types.h>

typedef struct env_s {
    char *name;
    char *data;
    struct env_s *next;
    struct env_s *prev;
} env_t;

typedef struct list_env {
    env_t *first;
    env_t *last;
    int size;
} list_env_t;

typedef struct shell {
    char **env;
    int loop;
    list_env_t *list;
    char **path;
 } shell_t;

void my_putchar(char c);
int my_put_nbr(int nb);
int my_putstr(char const *str);
int my_strlen(const char *str);
int print_env(char **env);
int my_strcmp(const char *s1, const char *s2);
char *my_strcpy(char *dest, char const *src);
int main(int argc, char **argv, char **env);
shell_t *get_cmd(shell_t *shell);
int shell_loop(char **env);
int compare_str(char *str1, char *str2);
shell_t *cmd_given(char *buffer, shell_t *shell);
char *find_cmd_path_bin(char **env, char *str, char **cmd);
char *path_parth(char **env, int line);
int find_line(char **env, char *str);
char *my_strcat(char *dest , char const *src );
char **my_str_to_word_array(char *str, char delim);
int size_of_word(int i , char *str);
int cont_word(char *str);
char **my_str_to_char(char *str, char c);
int size_of_word(int i, char *str);
int cont_word(char *str);
int my_puttab(char **tab);
int my_cd(char **args, shell_t *shell);
int find_line(char **env, char *str);
char **parse_separators(char *command);
char **parse_args(char *command);
char *clean_string(char *str);
shell_t *init_env(char **env, shell_t *shell);
int my_env(shell_t *shell);
char *get_env_value(shell_t *shell, char *name);
int update_env_value(shell_t *shell, char *name, char *value);
int save_path(shell_t *shell);
char *search_in_path(char *binary_name, shell_t *shell);

#endif 
