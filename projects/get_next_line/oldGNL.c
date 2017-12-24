/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: giabanji <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 19:42:20 by giabanji          #+#    #+#             */
/*   Updated: 2017/11/19 20:03:12 by giabanji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include <stdio.h>

int		ft_isnorm(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

char	*ft_isvalid(char *s)
{
	char	*tmp;
	int		count;

	count = ft_isnorm(s);
	tmp = ft_strnew(0);
	if (count == -1)
	{
		tmp = ft_strdup(s);
		return (tmp);
	}
	if (count == 0)
	   return (NULL);
	if (count == BUFF_SIZE - 1)
		return (tmp);
	if (count > 0 && count < BUFF_SIZE - 1)
	{
		tmp = ft_strsub(s, 0, count);
		return (tmp);
	}
	tmp = ft_strsub(s, 0, BUFF_SIZE);
	return (tmp);	
}

int		get_next_line(int fd, char **line)
{
	char		*old;
	char		*tmp;
	static char	*buf;
	char		*new;

	if (fd < 0)
		return (-1);
	if (!(*line = (char*)malloc(sizeof(char) * BUFF_SIZE)))
		return (-1);
	old = ft_strnew(0);
	if (buf)
	{
		if (ft_isnorm(buf) == -1)
		{
			old  = ft_strdup(buf);
			free(buf);
		}
		else if (ft_isnorm(buf) == BUFF_SIZE - 1)
		{
			*line = ft_strsub(buf, 0, BUFF_SIZE - 1);
			free(buf);
			return (1);
		}
		else if (ft_isnorm(buf) > 0 && ft_isnorm(buf) < BUFF_SIZE - 1)
		{
			*line = ft_strsub(buf, 0, ft_isnorm(buf));
			old = ft_strsub(buf, ft_isnorm(buf) + 1, BUFF_SIZE);
			free(buf);
			buf = ft_strdup(old);
			free(old);
			return (1);
		}
	}
	new = ft_strnew(0);
	tmp = ft_strnew(BUFF_SIZE);
	while (read(fd, tmp, BUFF_SIZE))
	{
		if (ft_isnorm(tmp) == -1)
			old = ft_strjoin(old, tmp);

		ft_memset(tmp, 0, BUFF_SIZE);
	}
	free(tmp);
	free(old);
	return (0);
}
