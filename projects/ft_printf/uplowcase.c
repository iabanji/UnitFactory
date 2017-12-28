/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uplowcase.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: giabanji <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 17:29:14 by giabanji          #+#    #+#             */
/*   Updated: 2017/12/28 20:03:38 by giabanji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	lower(char **str)
{
	int		i;
	char	*s;

	i = 0;
	s = *str;
	while (s[i])
	{
		if (s[i] >= 'A' && s[i] <= 'Z')
			s[i] = s[i] + 32;
		i++;
	}
}

void	ft_nullstr(void)
{
	g_data.plus = 0;
	g_data.defis = 0;
	g_data.space = 0;
	g_data.hash = 0;
	g_data.zero = 0;
	g_data.length = 0;
	g_data.accuracy = -1;
	g_data.mod = 0;
	g_data.h = 0;
	g_data.hh = 0;
	g_data.l = 0;
	g_data.ll = 0;
	g_data.z = 0;
	g_data.j = 0;
	g_data.convers = 0;
}

void	workinstruct_cont(void)
{
	if (g_data.convers == 'p')
		g_data.hash = 1;
	if ((g_data.convers == 'o' || g_data.convers == 'x' || g_data.convers == 'O'
				|| g_data.convers == 'X') && g_data.accuracy == 0)
		g_data.hash = ((g_data.convers == 'o') ? g_data.hash : 0);
	if (g_data.mod == 1 && g_data.convers == 'O')
		g_data.convers = 'o';
}

void	workinstruct(void)
{
	if (g_data.plus > 0)
		g_data.space = 0;
	if (g_data.defis > 0)
		g_data.zero = 0;
	if (g_data.accuracy >= 0)
		g_data.zero = 0;
	if (g_data.convers > 64 && g_data.convers < 91 && g_data.convers != 'X')
	{
		g_data.h = 0;
		g_data.hh = 0;
		g_data.l = 0;
		g_data.ll = 0;
		g_data.j = 0;
		g_data.z = 0;
	}
	if (g_data.convers == 'U' || g_data.convers == 'u')
	{
		g_data.plus = 0;
		g_data.space = 0;
	}
	workinstruct_cont();
}

int		val_jz(char c)
{
	if (c == 'j')
		g_data.j = 1;
	else if (c == 'z')
		g_data.z = 1;
	return (1);
}
