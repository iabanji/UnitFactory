# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: giabanji <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/08/09 16:51:53 by giabanji          #+#    #+#              #
#    Updated: 2017/08/09 17:59:50 by giabanji         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_display_file
FLAGS = -c -I -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
		gcc $(FLAGS) main.c
		gcc main.o -o $(NAME)

clean:
		/bin/rm -f main.o

fclean: clean
		/bin/rm -f $(NAME)

re: clean
		all
