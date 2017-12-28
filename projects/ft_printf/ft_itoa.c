/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: giabanji <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/03 18:09:51 by giabanji          #+#    #+#             */
/*   Updated: 2017/12/28 16:05:04 by giabanji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long long int	count_chars(long long int a)
{
	long long int	i;

	if (a < 0)
	{
		i = 2;
		a = -a;
	}
	else
		i = 1;
	while (a > 9)
	{
		a /= 10;
		i++;
	}
	return (i);
}

char					*min_int(void)
{
	char	*s;

	s = ft_strdup("-9223372036854775808");
	return (s);
}

char					*ft_itoa(long long int n)
{
	long long int	m;
	long long int	i;
	long long int	num;
	char			*str;

	if (n == -9223372036854775807 - 1)
		return (min_int());
	m = n;
	i = count_chars(m);
	if (!(str = (char*)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	num = 0;
	if (n < 0)
	{
		str[0] = '-';
		num = 1;
		m = -m;
	}
	str[i] = '\0';
	while (i > num)
	{
		str[--i] = (char)(48 + m - (m / 10 * 10));
		m = m / 10;
	}
	return (str);
}
