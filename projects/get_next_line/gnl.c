/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: giabanji <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 18:10:28 by giabanji          #+#    #+#             */
/*   Updated: 2017/11/29 17:53:05 by giabanji         ###   ########.fr       */
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
	char	*s;

	s = ft_strdup(*buf);
	ft_memdel((void **)buf);
	if (ft_isnorm(s) == -1)
	{
		ft_memdel((void **)line);
		*line = ft_strdup(s);
		*buf = ft_strnew(0);
		free(s);
		return ;
	}
	else if (ft_isnorm(s) == 0)
	{
		*buf = ft_strsub(s, 1, ft_strlen(s) - 1);
		free(s);
		return ;
	}
	ft_memdel((void **)line);
	*line = ft_strsub(s, 0, ft_isnorm(s));
	if (ft_isnorm(s) < (int)ft_strlen(s) - 1)
		*buf = ft_strsub(s, ft_isnorm(s) + 1, ft_strlen(s) - ft_isnorm(s) + 1);
	else
		*buf = ft_strnew(0);
	free(s);
}

void	ft_readtmp(char **buf, char *tmp)
{
	char	*s;

	if ((*buf))
	{
		s = ft_strdup(*buf);
		ft_memdel((void **)buf);
		*buf = ft_strjoin(s, tmp);
		free(s);
		return ;
	}
	else if (!(*buf))
	{
		*buf = ft_strdup(tmp);
		return ;
	}
}

char	*ft_lstsearch(int n, t_lst *p)
{
	while (p != NULL)
	{
		if (p->index == n)
			return (p->bufer);
		p = p->next;
	}
	if (!(p))
	{
		p = (t_lst *)malloc(sizeof(t_lst));
		p->index = n;
		p->bufer = NULL;
		p->next = NULL;
		return (p->bufer);
	}
	return (NULL);
}

int		get_next_line(const int fd, char **line)
{
	char			*buf;
	char			*tmp;
	int				ret;
	static t_lst	*p;

	if (fd < 0 || !line || BUFF_SIZE < 1 || (read(fd, 0, 0)))
		return (-1);
	*line = ft_strnew(0);
	buf = ft_lstsearch(fd, p);
	tmp = ft_strnew(BUFF_SIZE);
	while ((ret = read(fd, tmp, BUFF_SIZE)) > 0)
	{
		ft_readtmp(&buf, tmp);
		ft_memset(tmp, 0, BUFF_SIZE);
	}
	free(tmp);
	if (ret == -1)
		return (-1);
	if (!buf)
		return (0);
	ft_validbuf(&buf, line);
	if (buf[0] == '\0')
		ft_memdel((void **)&buf);
	return (1);
}
