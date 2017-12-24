/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: giabanji <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 13:43:28 by giabanji          #+#    #+#             */
/*   Updated: 2017/11/18 18:34:19 by giabanji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int		ft_isnorm(char	*s)
{
	int		i;

	i = -1;
	while (s[++i])
	{
		if (s[i] == '\n')
			return (i);
	}
	return (-1);
}

int		get_next_line(const int fd, char **line)
{
	char		*old;
	char		*new;
	char		*tmp;
	static char	*buf;

	if (!line)
		return (-1);
	if (fd < 0 || !*line)
		return (-1);
	*line = ft_strnew(0);
	old = ft_strnew(0);
	new = ft_strnew(0);
	tmp = ft_strnew(BUFF_SIZE);
//	ft_memset(tmp,0, BUFF_SIZE);
	if (buf)
	{
		if (ft_isnorm(buf) == -1)
		{
			old = ft_strdup(buf);
			free(buf);
		}
		else 
		{
			if (!(*line = ft_strsub(buf, 0, ft_isnorm(buf))))
				return (-1);
			old = ft_strsub(buf, ft_isnorm(buf) + 1, BUFF_SIZE);
			free(buf);
			buf = ft_strdup(old);
			free(old);
			return (1);
		}
	}
	while (read(fd, tmp, BUFF_SIZE) > 0)
	{
		if (ft_isnorm(tmp) == -1)
		{
			new = ft_strjoin(old, tmp);
			free(old);
			old = ft_strdup(new);
			free(new);
		}
		else
		{
			old = ft_strjoin(old, ft_strsub(tmp, 0, ft_isnorm(tmp)));
			*line = ft_strdup(old);
			free(old);
			buf = ft_strsub(tmp, ft_isnorm(tmp) + 1, BUFF_SIZE);
			return (1);
		}
		ft_memset(tmp, 0, BUFF_SIZE);
	}
	if(!(*line = ft_strdup(old)))
		return (-1);
	return (0);
}
