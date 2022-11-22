##
## EPITECH PROJECT, 2021
## makefile
## File description:
## makefile
##

SRC 	=	./lib/my/my_putchar.c 	\
			./lib/my/my_put_nbr.c 	\
			./lib/my/my_putstr.c	\
			./lib/my/my_strlen.c	\
			./lib/my/my_strcat.c 	\
			./lib/my/my_str_to_word_array.c 	\
			./lib/my/my_str_to_char.c 	\
			./lib/my/my_puttab.c 	\
			./lib/my/my_strcpy.c \
			./lib/my/my_strcmp.c \
			./src/parsing/init_env.c \
			./src/parsing/find_line.c \
			./src/main.c			\
			./src/shell_env.c		\
			./src/launch_cmd.c 		\
			./src/parth_argv.c		\
			./src/parsing/find_cmd_path.c	\
			./src/parsing/look_env.c	\
			./src/parsing/save_path.c	\
			./src/builtins/my_cd.c			\
			./src/builtins/my_env.c			\
			./src/parsing/parsing_commas.c	\
			./src/parsing/parse_command.c	\
			./src/parsing/clean_string.c

OBJ 	= 	$(SRC:.c=.o)

CPPFLAGS	= -I include -g 

NAME	= mysh

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(OBJ) -L./ -lmy -ggdb3

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:	fclean all

auteur:
	echo $(USER) > auteur