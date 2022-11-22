/*
** EPITECH PROJECT, 2022
** my_str_to_word_array
** File description:
** char * in char **
*/

#include "my.h"

int cont_word(char *str)
{
    if (str == NULL)
        return -1;
    int i = 0;
    int word = 1;

    while (str[i] != '\0') {
        if (str[i] == ' '&& str[i - 1] != ' ') {
            word++;
        }
        i++;
    }
    return word;
}

int size_of_word(int i , char *str)
{
    int size = 0;

    while (str[i] != ' ' && str[i] != '\0' && str[i] != '\n') {
        size++;
        i++;
    }
    return size;
}


char **my_str_to_word_array(char *str, char delim)
{
	int	word = cont_word(str);
	char	**result = malloc(sizeof(char *) * word + 1);
	int	i = 0;
	int	j = 0;
	int	k = 0;

	while (j <= word){
		k = 0;
		result[j] = malloc(sizeof(char) * size_of_word(i, str));
		while (str[i] != '\0' && str[i] != delim && str[i] != '\n') {
			result[j][k] = str[i];
			k += 1;
			i += 1;
		}
		result[j][k] = '\0';
		i += 1;
		j += 1;
	}
	result[j] = NULL;
	return result;
}