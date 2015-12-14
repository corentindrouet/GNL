/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrouet <cdrouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/09 08:51:06 by cdrouet           #+#    #+#             */
/*   Updated: 2015/12/14 08:35:09 by cdrouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"
#include <fcntl.h>
#include <limits.h>

int		main(int argc, char **argv)
{
	int		fd;
	int		fd2;
	int		fd3;
	char	*ptr;

	if (argc >= 2)
	{
		if ((ptr = (char*)malloc(sizeof(char)* 100)) == NULL)
			return (0);
		fd = open(argv[1], O_RDWR);
		fd2 = open(argv[2], O_RDWR);
		fd3 = open(argv[3], O_RDWR);
		get_next_line(fd, &ptr);
			ft_putchar('|');
			ft_putstr(ptr);
			ft_putchar('|');
		get_next_line(fd2, &ptr);
			ft_putchar('|');
			ft_putstr(ptr);
			ft_putchar('|');
		get_next_line(fd3, &ptr);
			ft_putchar('|');
			ft_putstr(ptr);
			ft_putchar('|');
		get_next_line(fd, &ptr);
			ft_putchar('|');
			ft_putstr(ptr);
			ft_putchar('|');
		get_next_line(fd2, &ptr);
			ft_putchar('|');
			ft_putstr(ptr);
			ft_putchar('|');
		get_next_line(fd2, &ptr);
			ft_putchar('|');
			ft_putstr(ptr);
			ft_putchar('|');
		get_next_line(fd3, &ptr);
			ft_putchar('|');
			ft_putstr(ptr);
			ft_putchar('|');
		get_next_line(fd, &ptr);
			ft_putchar('|');
			ft_putstr(ptr);
			ft_putchar('|');
		get_next_line(fd3, &ptr);
			ft_putchar('|');
			ft_putstr(ptr);
			ft_putchar('|');
		close(fd);
		close(fd2);
		free(ptr);
	}
	if (argc == 1)
	{
		if ((ptr = (char*)malloc(sizeof(char)* 100)) == NULL)
			return (0);
		while (get_next_line(0, &ptr) > 0)
		{
			ft_putchar('|');
			ft_putstr(ptr);
			ft_putchar('|');
		}
		free(ptr);
	}
	return (0);
}
