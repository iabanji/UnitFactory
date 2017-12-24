/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validformat.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: giabanji <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 16:59:43 by giabanji          #+#    #+#             */
/*   Updated: 2017/12/19 17:25:39 by giabanji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		ft_isdisc(char s)
{
	if (s == 's' || s == 'S' || s == 'p' || s == 'd' || s == 'i' || s == 'O'
			|| s == 'u' || s == 'U' || s == 'x' || s == 'X' ||
			s == 'c' || s == 'C' || s == '%')
		return ((int)s);
	return (0);
}

/*int		ft_validformat(char *format)
{
	int		i;

	if (!format)
		return (-1);
	if (format[0] == '\0')
		return (0);
	i = -1;
	while (format[++i])
	{
		if (format[i] == '%' && format[i + 1] != '\0')
		{
			i++;
			while (format[i] && ft_isdisc(format[i]) < 1)
				i++;
			if (ft_isdisc(format[i]) < 2)
				return (-1);
		}
		else if (format[i] == '%' && format[i + 1] == '\0')
			return (-1);
	}
	return (1);
}*/

void	print_s(va_list ap)
{
	char	*str;

	str = va_arg(ap, char*);
	if (!str)
	{
		ft_putstr("(null)");
		g_size += 6;
	}
	else
	{
		ft_putstr(str);
		g_size += (int)ft_strlen(str);
	}
}

/*void	print_ws(va_list ap)
{
	wchar_t	*str;
	int		char_l;

	str = va_arg(ap, wchar_t*);
	if (!str)
		str = (wchar_t*)ft_strdup("(null)");
	char_l = ((g_data.accuracy >= 0 && g_data.accuracy < (int)ft_wstrlen(str))
			? g_data.accuracy : (int)ft_wstrlen(str));
	if (g_data.length <= char_l)
		print_wchar(str, char_l);
	else if (g_data.length > char_l)
		print_Str(str, char_l);
}

void	print_Str(wchar_t *str, int n)
{
	if (g_data.defis > 0)
	{
		print_wchar(str, n);
		while (n++ != g_data.length)
		{
			ft_putchar(32);
			g_size++;
		}
		if (g_data.accuracy >= n)
		{
			print_wchar(str, n);
			while (n++ < g_data.length)
			{
				ft_putchar(32);
				g_size++;
			}
		}*/
		/*else if (g_data.accuracy >= 0)
		{
			print_wchar(str, g_data.accuracy);
			while (g_data.accuracy++ != g_data.length)
			{
				ft_putchar(32);
				g_size++;
			}
		}
	}
	else
	{
		while (g_data.length-- != n)
		{
			ft_putchar(32);
			g_size++;
		}
		print_wchar(str, n);
	}
}*/
