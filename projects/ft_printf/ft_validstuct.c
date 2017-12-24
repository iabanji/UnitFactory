/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validstuct.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: giabanji <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 17:34:28 by giabanji          #+#    #+#             */
/*   Updated: 2017/12/20 19:45:26 by giabanji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		ft_isflag(char c)
{
	if (c == '-' || c == '+' || c == ' '
			|| c == '#' || c == '0')
		return (1);
	return (0);
}

int		ft_validflag(char *s, int n)
{
	if (s[n] == '-')
		g_data.defis = 1;
	else if (s[n] == '+')
		g_data.plus = 1;
	else if (s[n] == ' ')
		g_data.space = 1;
	else if (s[n] == '#')
		g_data.hash = 1;
	else if (s[n] == '0')
		g_data.zero = 1;
	if (ft_isflag(s[n]) > 0)
		return (1);
	return (0);
}

int		ft_validlength(char *s, int n)
{
	if (s[n] > 47 && s[n] < 58)
	{
		g_data.length = g_data.length * 10 + ((int)s[n] - 48);
		return (1);
	}
	return (0);
}

int		ft_validacc(char *s, int n)
{
	if (g_data.accuracy == -1)
		g_data.accuracy = 0;
	if (s[n] > 47 && s[n] < 58)
	{
		g_data.accuracy = g_data.accuracy * 10 + ((int)s[n] - 48);
		return (1);
	}
	return (0);
}

int		ft_validmod(char *s, int n)
{
	if (s[n] == 'l')
	{
		if (g_data.l == 1)
		{
			g_data.l = 0;
			g_data.ll = 1;
		}
		else
			g_data.l = 1;
		return (1);
	}
	else if (s[n] == 'h')
	{
		if (g_data.h == 1)
		{
			g_data.h = 0;
			g_data.hh = 1;
		}
		else
			g_data.h = 0;
		return (1);
	}
	else if (s[n] == 'j' || s[n] == 'z')
		return (val_jz(s[n]));
	return (0);
}
