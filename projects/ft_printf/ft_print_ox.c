/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ox.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: giabanji <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/22 21:15:54 by giabanji          #+#    #+#             */
/*   Updated: 2017/12/23 18:13:49 by giabanji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	add_prefix(int n)
{
	if (g_data.convers == 'x' || g_data.convers == 'X')
	{
		if (g_data.convers == 'x')
			ft_putstr("0x");
		else
			ft_putstr("0X");
	}
	else if (g_data.convers == 'o' || g_data.convers == 'O')
		ft_putchar('0');
	if ((g_data.convers == 'x' || g_data.convers == 'X') && g_data.length <= n)
		g_size += 2;
	else if ((g_data.convers == 'o' || g_data.convers == 'O') && g_data.length <= n)
		g_size++;
}

void	print_ox(char *s)
{
	int		char_l;

	if (g_data.defis > 0)
	{
		char_l = ((g_data.accuracy > (int)ft_strlen(s))
				? g_data.accuracy : (int)ft_strlen(s));
		print_lef(s, char_l);
	}
	else
		print_wright(s);
}

void	print_lef(char *s, int char_l)
{
	if (g_data.length <= char_l)
	{
		if (g_data.hash > 0)
			add_prefix(char_l);
		if (char_l > (int)ft_strlen(s))
		{
			while (g_data.accuracy-- != (int)ft_strlen(s))
				ft_putchar('0');
		}
		ft_putstr(s);
		g_size += char_l;
	}
	else if (g_data.length > char_l)
	{
		if (g_data.hash > 0)
			add_prefix(0);
		if (char_l > (int)ft_strlen(s))
		{
			while (g_dataaccuracy-- != (int)ft_strlen(s))
				ft_putchar('0');
		}
		ft_putstr(s);
		while ((char_l++ + 2) != g_data.length)
			ft_putchar(' ');
		if (g_data.hash == 0)
			ft_putstr("  ");
		if (g_data.hash > 0 && (g_data.convers == 'o' || g_data.convers == 'O'))
			ft_putchar(' ');
		g_size += g_data.length;
	}
}
