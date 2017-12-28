/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ox.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: giabanji <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/22 21:15:54 by giabanji          #+#    #+#             */
/*   Updated: 2017/12/28 19:26:38 by giabanji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	add_prefix(int n)
{
	if (g_data.convers == 'x' || g_data.convers == 'X' || g_data.convers == 'p')
	{
		if (g_data.convers == 'x' || g_data.convers == 'p')
			ft_putstr("0x");
		else
			ft_putstr("0X");
	}
	else if (g_data.convers == 'o' || g_data.convers == 'O')
		ft_putchar('0');
	if ((g_data.convers == 'x' || g_data.convers == 'X') && g_data.length <= n)
		g_size += 2;
	else if ((g_data.convers == 'o' || g_data.convers == 'O')
			&& g_data.length <= n)
		g_size++;
	if (g_data.convers == 'p' && g_data.length <= n)
		g_size += 2;
}

void	printox(char *s)
{
	int		char_l;

	if (g_data.accuracy == 0 && s[0] == '0' && g_data.convers != 'O')
		s[0] = '\0';
	char_l = ((g_data.accuracy > (int)ft_strlen(s))
				? g_data.accuracy : (int)ft_strlen(s));
	if (g_data.length <= char_l)
	{
		if ((g_data.hash > 0 && s[0] != '0') || g_data.convers == 'p')
			add_prefix(char_l);
		if (char_l > (int)ft_strlen(s))
		{
			while (g_data.accuracy-- != (int)ft_strlen(s))
				ft_putchar('0');
		}
		ft_putstr(s);
		g_size += char_l;
	}
	else
	{
		if (g_data.defis > 0)
			printlef(s, char_l);
		else
			printwri(s, char_l);
	}
}

void	printlef(char *s, int char_l)
{
	if (g_data.length > char_l)
	{
		if ((g_data.hash > 0 && s[0] != '0') || g_data.convers == 'p')
			add_prefix(0);
		if (char_l > (int)ft_strlen(s))
		{
			while (g_data.accuracy-- != (int)ft_strlen(s))
				ft_putchar('0');
		}
		ft_putstr(s);
		if (g_data.length == char_l + 1)
			ft_putchar(' ');
		while ((char_l++ + 2) < g_data.length)
			ft_putchar(' ');
		if (g_data.hash == 0 && char_l != g_data.length)
			ft_putstr("  ");
		if (g_data.hash > 0 && (g_data.convers == 'o' || g_data.convers == 'O'))
			ft_putchar(' ');
		g_size += g_data.length;
	}
}

void	printwri(char *s, int char_l)
{
	if (g_data.length > char_l)
	{
		if (g_data.zero > 0 && g_data.hash > 0)
			add_prefix(0);
		if (g_data.hash == 0 && char_l + 2 <= g_data.length)
			ft_putstr((g_data.zero > 0) ? "00" : "  ");
		else if (g_data.hash == 0)
			ft_putchar((g_data.zero > 0) ? '0' : ' ');
		if (g_data.hash > 0 && (g_data.convers == 'o' || g_data.convers == 'O'))
			ft_putchar((g_data.zero > 0) ? '0' : ' ');
		while ((char_l++ + 2) < g_data.length)
			ft_putchar((g_data.zero > 0) ? '0' : ' ');
		if (g_data.hash > 0 && s[0] != '0' && g_data.zero == 0)
			add_prefix(0);
		if (g_data.accuracy > (int)ft_strlen(s))
		{
			while (g_data.accuracy-- != (int)ft_strlen(s))
				ft_putchar('0');
		}
		ft_putstr(s);
		g_size += g_data.length;
	}
}
