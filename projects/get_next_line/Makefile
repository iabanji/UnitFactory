# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anestor <anestor@student.unit.ua>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/14 15:46:46 by anestor           #+#    #+#              #
#    Updated: 2017/11/15 15:48:12 by anestor          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAGS = -Wall -Werror -Wextra
NAME = test_gnl

all:
	clang -Wall -Wextra -Werror -g -I libft/includes -o get_next_line.o -c get_next_line.c
	clang -Wall -Wextra -Werror -g -I libft/includes -o main.o -c main.c
	clang -g -o test_gnl main.o get_next_line.o -I libft/includes -L libft/ -lft

lib:
	make -C libft/ fclean && make -C libft/

clean:
	rm -f *.o

fclean: clean
	rm -f test_gnl

re: fclean all
