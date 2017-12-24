/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: giabanji <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/09 16:59:24 by giabanji          #+#    #+#             */
/*   Updated: 2017/08/09 21:02:36 by giabanji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define BUF_SIZE 4096

int		if_mak(char *str)
{
	int		i;
	char	*mak;

	i = 0;
	mak = "Makefile";
	while (str[i] != '\0')
	{
		if (str[i] == mak[i])
			i++;
		else
			return (0);
	}
	if (i == 8)
		return (1);
	return (0);
}

int		main(int argc, char *argv[])
{
	int		fd;
	int		ret;
	char	buf[BUF_SIZE];

	ret = 1;
	if (argc < 2)
		return (write(1, "File name missing.\n", 19));
	else if (argc > 2)
		return (write(1, "Too many arguments.\n", 20));
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (write(1, "OPEN() error.\n", 14));
	if (if_mak(argv[1]) == 1)
		return (write(1, "*contenu du Makefile*\n", 22));
	while (ret)
	{
		ret = read(fd, buf, BUF_SIZE);
		buf[BUF_SIZE - 1] = '\0';
		write(1, buf, ret);
	}
	fd = close(fd);
	if (fd == -1)
		return (write(1, "CLOSE() error.\n", 15));
	return (0);
}
