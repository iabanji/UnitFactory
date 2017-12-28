/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ch.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: giabanji <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/22 19:54:11 by giabanji          #+#    #+#             */
/*   Updated: 2017/12/27 19:48:05 by giabanji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	printch(int c)
{
	int		i;

	if (g_data.defis > 0)
	{
		ft_putchar(c);
		if (g_data.length > 1)
		{
			i = 0;
			while (++i < g_data.length)
				ft_putchar(' ');
		}
	}
	else
	{
		if (g_data.length > 1)
		{
			i = -1;
			while (++i < g_data.length - 1)
				ft_putchar(' ');
		}
		ft_putchar(c);
	}
	g_size += ((g_data.length > 1) ? g_data.length : 1);
}

void	print_strok(char *s)
{
	int		char_l;
	int		i;

	char_l = (((g_data.accuracy < (int)ft_strlen(s) && g_data.accuracy >= 0))
			? g_data.accuracy : (int)ft_strlen(s));
	if (g_data.length <= char_l)
	{
		i = -1;
		while (++i != char_l)
			ft_putchar(s[i]);
		g_size += char_l;
	}
	else
		print_str_len(s, char_l);
}

void	print_str_len(char *s, int char_l)
{
	int		i;

	i = -1;
	if (g_data.defis > 0)
	{
		while (++i != char_l)
			ft_putchar(s[i]);
		while (i++ != g_data.length)
			ft_putchar(' ');
	}
	else
	{
		while (++i != (g_data.length - char_l))
			ft_putchar(' ');
		i = -1;
		while (++i != char_l)
			ft_putchar(s[i]);
	}
	g_size += g_data.length;
}
