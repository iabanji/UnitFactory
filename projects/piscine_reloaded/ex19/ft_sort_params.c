/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: giabanji <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/02 17:37:17 by giabanji          #+#    #+#             */
/*   Updated: 2017/08/02 19:24:46 by giabanji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_putchar(char c);

void	ft_sort_arr(char *val[], int nb)
{
	int		i;
	int		j;
	char	*tmp;

	i = 1;
	while (i < (nb - 1))
	{
		j = 0;
		while (val[i][j] == val[i + 1][j])
			j++;
		if (val[i][j] > val[i + 1][j])
		{
			tmp = val[i];
			val[i] = val[i + 1];
			val[i + 1] = tmp;
			i = 0;
		}
		i++;
	}
}

void	ft_print(char *val[], int nb)
{
	int i;
	int j;

	if (nb > 1)
	{
		i = 1;
		while (i < nb)
		{
			j = 0;
			while (val[i][j] != '\0')
			{
				ft_putchar(val[i][j]);
				j++;
			}
			ft_putchar('\n');
			i++;
		}
	}
}

int		main(int argc, char *argv[])
{
	ft_sort_arr(argv, argc);
	ft_print(argv, argc);
	return (0);
}
