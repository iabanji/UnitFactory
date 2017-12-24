/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: giabanji <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 18:10:49 by giabanji          #+#    #+#             */
/*   Updated: 2017/12/05 19:07:54 by giabanji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_isdisc(char s)
{
	if (s == 's' || s == 'S' || s == 'p' || s == 'd' || s == 'i' || s == 'O'
			|| s == 'u' || s == 'U' || s == 'x' || s == 'X' ||
			s == 'c' || s == 'C' || s == '%')
		return ((int)s);
	if (s == '\0')
		return (1);
	return (0);
}

void	ft_joinchar(char **line, char c)
{
	char	*tmp;
	size_t	size;

	if (!(*line))
	{
		*line = (char *)malloc(sizeof(char) * 2);
		*line[0] = c;
		*line[1] = '\0';
	}
	else
	{
		tmp = ft_strdup(*line);
		ft_memdel((void **)line);
		size = ft_strlen(tmp);
		*line = (char *)malloc(sizeof(char) * (size + 2));
		*line = ft_strcpy(*line, tmp);
		*line[size] = c;
		*line[size + 1] = '\0';
		free(tmp);
	}
}

int		ft_printf(char *str, ...)
{
	char	*line;
	int		i;

	if (!str)
		return (0);
	i = -1;
	while (str[++i])
	{
		if (str[i] != '%')
			ft_joinchar(&line, str[i]);
		else if (str[i] == '%')
		{
			i++;
			ft_validconvers(&line, i, &str); 
			while (str[i] || ft_isdisc(str[i]) < 1)
				i++;
			i--;
		}
	}
	if (str[0] != '\0')
		ft_pustr(line);
	ft_putchar('\n');
	return (0);
}
