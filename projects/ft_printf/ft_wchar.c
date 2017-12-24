/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printflags.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: giabanji <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 20:01:08 by giabanji          #+#    #+#             */
/*   Updated: 2017/12/19 17:47:09 by giabanji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	print_wchar(wchar_t *str, int n)
{
	while (*str != '\0' && n > 0)
	{
		if (*str <= 127 && (n = n - 1) >= 0)
		{
			ft_putwchar(*str);
			g_size++;
		}
		else if (*str <= 2047 && (n = n - 2) >= 0)
		{
			ft_putwchar(*str);
			g_size += 2;
		}
		else if (*str <= 65535 && (n = n - 3) >= 0)
		{
			ft_putwchar(*str);
			g_size += 3;
		}
		else if (*str <= 1114111 && (n = n - 4) >= 0)
		{
			ft_putwchar(*str);
			g_size += 4;
		}
		str++;
	}
}
