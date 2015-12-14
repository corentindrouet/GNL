/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrouet <cdrouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/09 08:40:55 by cdrouet           #+#    #+#             */
/*   Updated: 2015/12/14 09:05:16 by cdrouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int				get_next_line(int const fd, char **line)
{
	static char	*c[20] = {NULL};
	int			j[4];

	init_j(j);
	j[3] = search_index(c, fd);
	if (c[j[3]] == NULL)
	{
		c[j[3]] = (char*)malloc(sizeof(char) * (BUFF_SIZE + 3));
		if ((j[2] = read_gnl(c[j[3]], fd)) <= 0)
			return (j[2]);
	}
	while (c[j[3]][++j[1]] != '\n' && c[j[3]][j[1]])
	{
		(*line)[++j[0]] = c[j[3]][j[1]];
		if (c[j[3]][j[1] + 1] == '\0')
		{
			if ((j[2] = read_gnl(c[j[3]], fd)) <= 0)
				return (j[2]);
			j[1] = -1;
		}
	}
	(*line)[++j[0]] = '\0';
	if ((j[2] = verif_end(j, c)) == 1)
		return (0);
	return (1);
}

void			init_j(int *j)
{
	j[0] = -1;
	j[1] = -1;
	j[2] = -1;
	j[3] = -1;
}

int				search_index(char **c, int fd)
{
	int	j;

	j = -1;
	while (++j < 20)
	{
		if (c[j] != NULL)
		{
			if (c[j][BUFF_SIZE + 2] == fd)
				return (j);
		}
	}
	j = -1;
	while (++j < 5)
		if (c[j] == NULL)
			return (j);
	return (j);
}

int				read_gnl(char *c, int fd)
{
	int		ret;

	if ((ret = read(fd, c, BUFF_SIZE)) <= 0)
		return (ret);
	c[ret] = '\0';
	c[BUFF_SIZE + 2] = fd;
	return (ret);
}

int				verif_end(int *i, char **c)
{
	if (c[i[3]][i[1]] == '\0')
	{
		free(c[i[3]]);
		c[i[3]] = NULL;
		return (1);
	}
	else if (c[i[3]][i[1]] == '\n' && c[i[3]][i[1] + 1] != '\0')
	{
		ft_memcpy(c[i[3]], &c[i[3]][i[1] + 1], BUFF_SIZE + 2);
		c[i[3]][BUFF_SIZE - i[1]] = '\0';
		return (2);
	}
	else if (c[i[3]][i[1]] == '\n' && c[i[3]][i[1] + 1] == '\0')
	{
		free(c[i[3]]);
		c[i[3]] = NULL;
		return (0);
	}
	if (c[i[3]] == NULL)
		return (1);
	return (-1);
}
