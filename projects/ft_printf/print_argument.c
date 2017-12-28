/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_argument.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: giabanji <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 17:10:05 by giabanji          #+#    #+#             */
/*   Updated: 2017/12/28 18:18:59 by giabanji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	print_d(va_list ap)
{
	void	*tmp;
	char	*str;

	if (g_data.convers == 'D')
		g_data.l = 1;
	tmp = va_arg(ap, void*);
	if (g_data.h != 0)
		str = ft_itoa((short int)tmp);
	else if (g_data.hh != 0)
		str = ft_itoa((char)tmp);
	else if (g_data.l != 0)
		str = ft_itoa((long int)tmp);
	else if (g_data.ll != 0)
		str = ft_itoa((long long int)tmp);
	else if (g_data.z != 0)
		str = ft_itoa((ssize_t)tmp);
	else if (g_data.j != 0)
		str = ft_itoa((intmax_t)tmp);
	else
		str = ft_itoa((int)tmp);
	print_cifer(str);
	free(str);
}

void	print_u(va_list ap)
{
	void	*tmp;
	char	*str;

	if (g_data.convers == 'U')
		g_data.l = 1;
	tmp = va_arg(ap, void*);
	if (g_data.h != 0)
		str = ft_itoa_base_u((unsigned short int)tmp, 10);
	else if (g_data.hh != 0)
		str = ft_itoa_base_u((unsigned char)tmp, 10);
	else if (g_data.l != 0)
		str = ft_itoa_base_u((unsigned long int)tmp, 10);
	else if (g_data.ll != 0)
		str = ft_itoa_base_u((unsigned long long int)tmp, 10);
	else if (g_data.z != 0)
		str = ft_itoa_base_u((size_t)tmp, 10);
	else if (g_data.j != 0)
		str = ft_itoa_base_u((uintmax_t)tmp, 10);
	else
		str = ft_itoa_base_u((unsigned int)tmp, 10);
	print_cifer(str);
	free(str);
}

void	print_x(va_list ap)
{
	void	*tmp;
	char	*str;

	tmp = va_arg(ap, void*);
	if (g_data.h != 0)
		str = ft_itoa_base((unsigned short int)tmp, 16);
	else if (g_data.hh != 0)
		str = ft_itoa_base((unsigned char)tmp, 16);
	else if (g_data.l != 0)
		str = ft_itoa_base_u((unsigned long int)tmp, 16);
	else if (g_data.ll != 0)
		str = ft_itoa_base_u((unsigned long long int)tmp, 16);
	else if (g_data.z != 0)
		str = ft_itoa_base_u((size_t)tmp, 16);
	else if (g_data.j != 0)
		str = ft_itoa_base_u((uintmax_t)tmp, 16);
	else
		str = ft_itoa_base_u((unsigned int)tmp, 16);
	if (g_data.convers == 'x')
		lower(&str);
	printox(str);
	free(str);
}

void	print_o(va_list ap)
{
	void	*tmp;
	char	*str;

	tmp = va_arg(ap, void*);
	if (g_data.convers == 'O')
		g_data.l = 1;
	if (g_data.h != 0)
		str = ft_itoa_base_u((unsigned short int)tmp, 8);
	else if (g_data.hh != 0)
		str = ft_itoa_base_u((unsigned char)tmp, 8);
	else if (g_data.l != 0)
		str = ft_itoa_base_u((unsigned long int)tmp, 8);
	else if (g_data.ll != 0)
		str = ft_itoa_base_u((unsigned long long int)tmp, 8);
	else if (g_data.z != 0)
		str = ft_itoa_base_u((size_t)tmp, 8);
	else if (g_data.j != 0)
		str = ft_itoa_base_u((uintmax_t)tmp, 8);
	else
		str = ft_itoa_base_u((unsigned int)tmp, 8);
	printox(str);
	free(str);
}

void	print_c(va_list ap)
{
	void		*tmp;
	char		*str;

	if (g_data.convers == '%')
		printch(g_data.convers);
	else if (g_data.convers == 'p')
	{
		tmp = va_arg(ap, void*);
		str = ft_itoa_base_u((unsigned long long)tmp, 16);
		lower(&str);
		printox(str);
		free(str);
	}
	else
	{
		tmp = va_arg(ap, void*);
		printch((unsigned char)tmp);
	}
}
