/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: giabanji <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/19 15:37:08 by giabanji          #+#    #+#             */
/*   Updated: 2017/11/22 17:51:09 by giabanji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int		ft_isnorm(char *s)
{
	int		i;

	if (!s)
		return (-1);
	i = -1;
	while (s[++i])
	{
		if (s[i] == '\n')
			return (i);
	}
	return (-1);
}

void	ft_validbuf(char **buf, char **line)
{
	char	*tmp;

	tmp = ft_strsub(*buf, ft_isnorm(*buf) + 1, BUFF_SIZE - ft_isnorm(*buf));
	ft_memdel((void **)line);
	if (ft_isnorm(*buf) == -1)
	{
		*line = ft_strdup(*buf);
		ft_memdel((void **)buf);
		return ;
	}
	else if (ft_isnorm(*buf) != 0)
	{
		*line = ft_strsub(*buf, 0, ft_isnorm(*buf));
		ft_memdel((void **)buf);
		*buf = ft_strdup(tmp);
		return ;
	}
	*line = "\0\0";
	ft_memdel((void **)buf);
	*buf = ft_strdup(tmp);
	return ;
}

void	ft_readtmp(char **buf, char **line, char *str)
{
	char	*s;

	s = ft_strdup(*line);
	ft_memdel((void **)line);
	if (buf)
		ft_memdel((void **)buf);
	if (ft_isnorm(str) == -1)
	{
		*line = ft_strjoin(s, str);
		return ;
	}
	else if (ft_isnorm(str) != 0)
	{
		*line = ft_strjoin(s, ft_strsub(str, 0, ft_isnorm(str)));
		*buf = ft_strsub(str, ft_isnorm(str) + 1, BUFF_SIZE - ft_isnorm(str));
		return ;
	}
	*line = ft_strdup(s);
	*buf = ft_strsub(str, ft_isnorm(str) + 1, BUFF_SIZE - ft_isnorm(str));
}

int		get_next_line(const int fd, char **line)
{
	char		*tmp;
	static char	*buf = NULL;
	int			ret;

	if (fd < 0 || !line || BUFF_SIZE < 1 || (read(fd, 0, 0)))
		return (-1);
	*line = ft_strnew(0);
	if (buf)
	{
		ret = ft_isnorm(buf);
		ft_validbuf(&buf, line);
		if (ret > -1)
			return (1);
	}
	tmp = ft_strnew(BUFF_SIZE);
	while ((ret = read(fd, tmp, BUFF_SIZE)))
	{
		ft_readtmp(&buf, line, tmp);
		if (ft_isnorm(tmp) > -1)
			break ;
		ft_memset(tmp, 0, BUFF_SIZE);
	}
	return ((ret > 0) ? (1) : (ret));
}
