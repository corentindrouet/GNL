/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrouet <cdrouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/09 08:51:06 by cdrouet           #+#    #+#             */
/*   Updated: 2015/12/15 08:13:49 by cdrouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"
#include <fcntl.h>
#include <limits.h>

int		main(int argc, char **argv)
{
	int		fd;
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
	}
	return (0);
}
