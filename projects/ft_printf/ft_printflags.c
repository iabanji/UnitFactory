/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printflags.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: giabanji <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/19 17:48:19 by giabanji          #+#    #+#             */
/*   Updated: 2017/12/28 18:18:44 by giabanji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	print_sym(char **str)
{
	char	*s;

	s = *str;
	if (s[0] == '-' || g_data.plus > 0)
	{
		ft_putchar((s[0] == '-') ? '-' : '+');
		if (s[0] == '-' && g_data.defis == 0)
			g_data.plus = 0;
		if (s[0] == '-')
			*str = ft_strsub(s, 1, (int)ft_strlen(s));
		g_data.space = 0;
	}
	else if (g_data.space > 0)
		ft_putchar(' ');
}

void	print_cifer(char *s)
{
	int		char_l;

	if (g_data.accuracy == 0 && s[0] == '0')
		s[0] = '\0';
	if (g_data.defis > 0)
	{
		char_l = ((g_data.accuracy > (int)ft_strlen(s))
			? g_data.accuracy : (int)ft_strlen(s));
		if (s[0] == '-' && g_data.accuracy > (int)ft_strlen(s)
				&& g_data.plus == 0 && g_data.length <= char_l)
			g_size++;
		print_sym(&s);
		print_left_cif(s, char_l);
	}
	else
		print_wright_cif(s);
}

void	print_left_cif(char *s, int char_l)
{
	if (g_data.length <= char_l)
	{
		if (g_data.accuracy > (int)ft_strlen(s))
		{
			while (g_data.accuracy-- > (int)ft_strlen(s))
				ft_putchar('0');
		}
		ft_putstr(s);
		g_size += ((((g_data.plus > 0) || g_data.space > 0))
				? char_l + 1 : char_l);
	}
	else if (g_data.length > char_l)
	{
		if (g_data.accuracy > (int)ft_strlen(s))
		{
			while (g_data.accuracy-- > (int)ft_strlen(s))
				ft_putchar('0');
		}
		ft_putstr(s);
		if (g_data.plus > 0 || g_data.space > 0)
			char_l++;
		while (char_l++ != g_data.length)
			ft_putchar(' ');
		g_size += g_data.length;
	}
}

void	print_wright_cif(char *s)
{
	int		char_l;

	char_l = ((g_data.accuracy > (int)ft_strlen(s))
			? g_data.accuracy : (int)ft_strlen(s));
	if (g_data.length <= char_l)
	{
		if (s[0] == '-' && g_data.accuracy > (int)ft_strlen(s))
			g_size++;
		print_sym(&s);
		if (g_data.accuracy > (int)ft_strlen(s))
		{
			while (g_data.accuracy-- > (int)ft_strlen(s))
				ft_putchar('0');
		}
		ft_putstr(s);
		g_size += ((((g_data.plus > 0) || g_data.space > 0))
				? char_l + 1 : char_l);
	}
	else if (g_data.length > char_l)
		pr_d_c(s, char_l);
	if (g_data.length > char_l)
		g_size += g_data.length;
}

void	pr_d_c(char *s, int n)
{
	if (g_data.space > 0 && (g_data.plus == 0 && s[0] != '-'))
		n++;
	if (g_data.plus > 0 && s[0] != '-')
		n++;
	if (g_data.accuracy == (int)ft_strlen(s) && (g_data.plus > 0
				|| s[0] == '-'))
		n++;
	while (n++ != g_data.length && g_data.zero == 0)
		ft_putchar(' ');
	print_sym(&s);
	if (g_data.zero > 0)
	{
		while ((n++ - 1) != g_data.length)
			ft_putchar('0');
	}
	if (g_data.accuracy > (int)ft_strlen(s))
	{
		while (g_data.accuracy-- != (int)ft_strlen(s))
			ft_putchar('0');
	}
	ft_putstr(s);
}
