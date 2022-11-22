/*
** EPITECH PROJECT, 2021
** my_strlen.c
** File description:
** B-CPE-110-BDX-1-1-BSQ-arthur.py
*/

#include <my.h>

int my_strlen(const char *str)
{
    if(str == NULL){
        return -1;
    }
    int i = 0;
    while (str[i] != '\0'){
        i++;
    }
    return i;
}