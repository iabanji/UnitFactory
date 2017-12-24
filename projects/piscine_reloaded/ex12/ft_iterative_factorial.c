/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: giabanji <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/28 10:12:44 by giabanji          #+#    #+#             */
/*   Updated: 2017/10/24 13:31:40 by giabanji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_iterative_factorial(int nb)
{
	int res;
	int i;

	i = 1;
	res = 1;
	if (nb == 0)
		return (1);
	if ((nb > 0) && (nb <= 12))
	{
		while (i <= nb)
		{
			res *= i;
			i++;
		}
	}
	else
	{
		return (0);
	}
	return (res);
}
