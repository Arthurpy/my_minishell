/*
** EPITECH PROJECT, 2021
** days06
** File description:
** arthur py
*/

char *my_strcpy(char *dest, char const *src)
{
    int a = 0;
    while (src[a] != '\0') {
        dest[a] = src[a];
        a++;;
    }
    return (dest);
}