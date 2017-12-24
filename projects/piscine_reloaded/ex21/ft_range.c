/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: giabanji <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/03 14:51:46 by giabanji          #+#    #+#             */
/*   Updated: 2017/10/24 14:48:32 by giabanji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		*ft_range(int min, int max)
{
	int		*point;
	int		len;
	int		i;

	if (min >= max)
		return (0);
	else
	{
		len = max - min;
		i = 0;
		point = (int*)malloc(sizeof(*point) * len);
		while (min < max)
		{
			point[i] = min;
			min++;
			i++;
		}
	}
	return (point);
}
