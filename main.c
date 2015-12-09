/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrouet <cdrouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/09 08:51:06 by cdrouet           #+#    #+#             */
/*   Updated: 2015/12/09 16:29:28 by cdrouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"
#include "fcntl.h"

int		main(int argc, char **argv)
{
	int		fd;
	char	*ptr;

	if (argc == 2)
	{
		if ((ptr = (char*)malloc(sizeof(char)* 100)) == NULL)
			return (0);
		fd = open(argv[1], O_RDWR);
		while (get_next_line(fd, &ptr) > 0)
		{
			ft_putchar('|');
			ft_putstr(ptr);
			ft_putchar('|');
		}
		close(fd);
		free(ptr);
	}
	return (0);
}
