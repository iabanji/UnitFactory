/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: giabanji <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 19:48:06 by giabanji          #+#    #+#             */
/*   Updated: 2017/12/19 17:16:18 by giabanji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 1
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "libft/libft.h"

typedef struct		s_lst
{
	int				index;
	char			*bufer;
	struct s_lst	*next;
}					t_lst;

int					get_next_line(const int fd, char **line);
void				ft_readtmp(t_lst **list, char *tmp, int n);
int					ft_validbuf(char **line, t_lst **list, int n);
int					ft_isnorm(char *s);

#endif
