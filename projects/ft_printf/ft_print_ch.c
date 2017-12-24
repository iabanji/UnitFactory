/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ch.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: giabanji <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/22 19:54:11 by giabanji          #+#    #+#             */
/*   Updated: 2017/12/22 20:24:10 by giabanji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	print_ch(int c)
{
	int		i;

	if (g_data.defis > 0)
	{
		ft_putchar((c >= 0 && c < 32) ? 32 : c);
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
		ft_putchar((c >= 0 && c < 32) ? 32 : c);
	}
	g_size += ((g_data.length > 1) ? g_data.length : 1);
}
