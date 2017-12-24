/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_negative.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: giabanji <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/26 18:07:51 by giabanji          #+#    #+#             */
/*   Updated: 2017/10/29 18:52:02 by giabanji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

void	ft_is_negative(int number)
{
	if (number >= 0)
	{
		ft_putchar('P');
	}
	else
	{
		ft_putchar('N');
	}
	return ;
}
