/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anestor <anestor@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 14:52:02 by anestor           #+#    #+#             */
/*   Updated: 2017/11/22 19:50:14 by giabanji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int		main(int argc, char **argv)
{
	char	**test;
	int		fd;
	char	*temp;
	int		size;

	size = 0;
	temp = ft_strnew(BUFF_SIZE);
	if (argc == 1)
		fd = 0;
	if (argc == 2)
		fd = open(argv[1], O_RDWR);
	if (argc > 2)
		printf("error\n");
	while (read(fd, temp, BUFF_SIZE))
	{
		int		n;

		n = 0;
		while (n != BUFF_SIZE)
		{
			if (temp[n] == '\n')
				size++;
			n++;
		}
		ft_strclr(temp);
	}
	printf("Size: %d\n", size);
	test = (char **)malloc(sizeof(char*) * (size + 1));
	if (argc == 2)
		close(fd);
	if (argc == 2)
		fd = open(argv[1], O_RDWR);
	int		l = 0;
	printf("FD = %d\n", fd);
	while (l++ != size)
	{
		get_next_line(fd, test);
		///printf("EXIT\n");
		printf("line %d: %s\n", l, *test);
		test++;
	}
	return (0);
}
