/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: giabanji <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 16:44:34 by giabanji          #+#    #+#             */
/*   Updated: 2017/12/28 18:20:49 by giabanji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	print_str(va_list ap)
{
	if (g_data.convers == 'd' || g_data.convers == 'i'
			|| g_data.convers == 'D')
		print_d(ap);
	else if (g_data.convers == 'u' || g_data.convers == 'U')
		print_u(ap);
	else if (g_data.convers == 'x' || g_data.convers == 'X')
		print_x(ap);
	else if (g_data.convers == 'o' || g_data.convers == 'O')
		print_o(ap);
	else if (g_data.convers == 'c' || g_data.convers == 'C'
			|| g_data.convers == '%' || g_data.convers == 'p')
		print_c(ap);
	else if (g_data.convers == 's')
		print_s(ap);
	else if (g_data.convers == 'S')
		print_ws(ap);
}

int		ft_validstruct(char *s, int n)
{
	while (s[n] && ft_validflag(s, n) != 0)
		n++;
	while (s[n] && ft_validlength(s, n) != 0)
		n++;
	if (s[n] == '.')
	{
		n++;
		while (s[n] && ft_validacc(s, n) != 0)
			n++;
	}
	while (s[n] && ft_validmod(s, n) != 0)
		n++;
	if (ft_isdisc(s[n]) < 1)
		g_data.convers = -1;
	else
		g_data.convers = ft_isdisc(s[n]);
	return (n);
}

void	ft_readformat(char *s, va_list ap)
{
	int		i;

	i = -1;
	while (s[++i])
	{
		if (s[i] == '%')
		{
			ft_nullstr();
			i++;
			i = ft_validstruct(s, i);
			workinstruct();
			if (g_data.convers > 0)
				print_str(ap);
			else
				i--;
		}
		else
		{
			ft_putchar(s[i]);
			g_size++;
		}
	}
}

int		ft_printf(char *format, ...)
{
	va_list	ap;

	g_size = 0;
	if (format && format[0] != '\0')
	{
		va_start(ap, format);
		ft_readformat(format, ap);
		va_end(ap);
	}
	return (g_size);
}
