# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kceder <kceder@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/05 13:12:58 by pietari           #+#    #+#              #
#    Updated: 2022/02/08 14:36:26 by kceder           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
SRC = main.c main_2.c solver.c solver_2.c solver_3.c output.c utility.c
OBJ = $(SRC:.c=.o)
HEADER = fillit.h
LIBFT = libft/
FLAGS = -Wall -Wextra -Werror

.PHONY = all clean fclean clean re

all: $(NAME)

$(NAME):
	make -C $(LIBFT)
	gcc $(FLAGS) -c $(SRC)
	gcc $(OBJ) libft/libft.a $(FLAGS) -o $(NAME)

clean:
		rm -f $(OBJ)
		make clean -C libft/

fclean: clean
		rm -f $(NAME)
		make fclean -C libft/
		
re: fclean all

andclean: all clean