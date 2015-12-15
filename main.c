/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrouet <cdrouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/09 08:51:06 by cdrouet           #+#    #+#             */
/*   Updated: 2015/12/15 14:05:05 by cdrouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"
#include <fcntl.h>
#include <limits.h>
#include <assert.h>


int		main(void)
{
	/*	int		fd;
		int		i;
		char	*ptr;

		if (argc >= 2)
		{
		fd = open(argv[1], O_RDWR);
		i = get_next_line(fd, &ptr);
		ft_putchar('|');
		ft_putstr(ptr);
		ft_putchar('-');
		ft_putnbr(i);
		ft_strdel(&ptr);
		i = get_next_line(fd, &ptr);
		ft_putchar('|');
		ft_putstr(ptr);
		ft_putchar('-');
		ft_putnbr(i);
		ft_strdel(&ptr);
		i = get_next_line(fd, &ptr);
		ft_putchar('|');
		ft_putstr(ptr);
		ft_putchar('-');
		ft_putnbr(i);
		ft_strdel(&ptr);
		i = get_next_line(fd, &ptr);
		ft_putchar('|');
		ft_putchar('-');
		ft_putnbr(i);
		ft_strdel(&ptr);
		i = get_next_line(fd, &ptr);
		ft_putchar('|');
		ft_putchar('-');
		ft_putnbr(i);
		ft_strdel(&ptr);
		i = get_next_line(fd, &ptr);
		ft_putchar('|');
		ft_putchar('-');
		ft_putnbr(i);
		close(fd);
		ft_strdel(&ptr);
		}
		if (argc == 1)
		{
		if ((ptr = (char*)malloc(sizeof(char)* 100)) == NULL)
		return (0);
		write(1, "bonjour\n", 8);
		ft_putstr("|-|");
		get_next_line(1, &ptr);
		ft_putchar('|');
		ft_putstr(ptr);
		ft_putchar('|');
		free(ptr);
		}*/
	char *line;
	int fd;
	int fd2;
	int fd3;
	int diff_file_size;

	system("mkdir -p sandbox");
	system("openssl rand -out sandbox/large_file.txt -base64 $((50 * 1000 * 3/4)) 2> /dev/null");

	fd = open("sandbox/large_file.txt", O_RDONLY);
	fd2 = open("sandbox/large_file.txt.mine", O_CREAT | O_RDWR | O_TRUNC, 0755);

	while (get_next_line(fd, &line) == 1)
	{
		write(fd2, line, strlen(line));
		write(fd2, "\n", 1);
	}

	close(fd);
	close(fd2);

	system("diff sandbox/large_file.txt sandbox/large_file.txt.mine > sandbox/large_file.diff");
	fd3 = open("sandbox/large_file.diff", O_RDONLY);
	diff_file_size = read(fd3, NULL, 10);
	close(fd3);
	return (0);
}
