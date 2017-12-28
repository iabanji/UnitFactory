/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printflags.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: giabanji <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 20:01:08 by giabanji          #+#    #+#             */
/*   Updated: 2017/12/27 18:55:36 by giabanji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	print_wchar(wchar_t *str, int n)
{
	int		i;

	i = -1;
	while (str[++i] != '\0')
	{
		if (n >= len_wchar(str[i]))
		{
			ft_putwchar(str[i]);
			n = n - len_wchar(str[i]);
		}
		else
			return ;
	}
}

int		wstrlen_if(wchar_t *str, int n)
{
	int		count;
	int		i;

	i = -1;
	count = 0;
	while (str[++i] != '\0')
	{
		if (n >= len_wchar(str[i]))
		{
			if (str[i] <= 127)
				count++;
			else if (str[i] <= 2047)
				count += 2;
			else if (str[i] <= 65535)
				count += 3;
			else if (str[i] <= 1114111)
				count += 4;
			n = n - len_wchar(str[i]);
		}
	}
	return (count);
}

int		len_wchar(wchar_t c)
{
	if (c <= 127)
		return (1);
	else if (c <= 2047)
		return (2);
	else if (c <= 65535)
		return (3);
	else if (c <= 1114111)
		return (4);
	return (0);
}
