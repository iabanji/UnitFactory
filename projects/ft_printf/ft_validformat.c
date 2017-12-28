/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validformat.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: giabanji <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 16:59:43 by giabanji          #+#    #+#             */
/*   Updated: 2017/12/28 18:30:27 by giabanji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		ft_isdisc(char s)
{
	if (s == 's' || s == 'S' || s == 'p' || s == 'd' || s == 'i' || s == 'O'
			|| s == 'u' || s == 'U' || s == 'x' || s == 'X' ||
			s == 'c' || s == 'C' || s == '%' || s == 'o' || s == 'D')
		return ((int)s);
	return (0);
}

void	print_s(va_list ap)
{
	char	*str;

	str = va_arg(ap, char*);
	if (!str)
	{
		str = ft_strdup("(null)");
		print_strok(str);
		free(str);
	}
	else
		print_strok(str);
}

void	print_ws(va_list ap)
{
	wchar_t	*str;
	int		char_l;

	str = va_arg(ap, wchar_t*);
	if (!str)
	{
		str = (wchar_t*)malloc(sizeof(wchar_t) * 7);
		str[0] = '(';
		str[1] = 'n';
		str[2] = 'u';
		str[3] = 'l';
		str[4] = 'l';
		str[5] = ')';
		str[6] = '\0';
	}
	char_l = ((g_data.accuracy >= 0 && g_data.accuracy < (int)ft_wstrlen(str))
			? g_data.accuracy : (int)ft_wstrlen(str));
	if (g_data.length <= char_l)
	{
		print_wchar(str, char_l);
		g_size += wstrlen_if(str, char_l);
	}
	else
		print_wdef(str, char_l);
}

void	print_wdef(wchar_t *s, int char_l)
{
	int		i;

	i = 0;
	if (g_data.defis > 0)
	{
		print_wchar(s, char_l);
		while (i++ < (g_data.length - wstrlen_if(s, char_l)))
			ft_putchar(' ');
	}
	else
	{
		while (i++ < (g_data.length - wstrlen_if(s, char_l)))
			ft_putchar(' ');
		print_wchar(s, char_l);
	}
	g_size += g_data.length;
}
