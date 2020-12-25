# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hmzah <hmzah@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/07 03:55:23 by hmzah             #+#    #+#              #
#    Updated: 2020/11/13 00:54:12 by hmzah            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell
LIB_PATH = libft/
LIB = libft.a
SRC = src/builtins.c \
	src/exec_cmd.c \
	src/expansions.c \
	src/list_tools.c \
	src/minishell.c \
	src/tools.c \
	src/builtins/ft_cd.c \
	src/builtins/ft_echo.c \
	src/builtins/ft_env.c \
	src/builtins/ft_exit.c \
	src/builtins/ft_setenv.c \
	src/builtins/ft_unsetenv.c \

FLAGS = -Wall -Wextra -Werror
all: $(NAME)

$(NAME): $(LIB)
	gcc $(FLAGS) $(SRC) $(LIB_PATH)/$(LIB) -o $(NAME)

$(LIB):
	make -C $(LIB_PATH)

clean:
	make clean -C $(LIB_PATH)

fclean: clean
	make fclean -C $(LIB_PATH)
	rm -rf $(NAME)

re: fclean all