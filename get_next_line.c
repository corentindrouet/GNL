/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrouet <cdrouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/09 08:40:55 by cdrouet           #+#    #+#             */
/*   Updated: 2015/12/11 10:18:15 by cdrouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int				get_next_line(int const fd, char **line)
{
	static char	*c = NULL;
	int			j[3];

	j[0] = -1;
	j[1] = -1;
	if (c == NULL)
	{
		c = (char*)malloc(sizeof(char) * (BUFF_SIZE + 1));
		if ((j[2] = read_gnl(c, fd)) <= 0)
			return (j[2]);
	}
	while (c[++j[1]] != '\n' && c[j[1]])
	{
		(*line)[++j[0]] = c[j[1]];
		if (c[j[1] + 1] == '\0')
		{
			if ((j[2] = read_gnl(c, fd)) <= 0)
				return (j[2]);
			j[1] = -1;
		}
	}
	(*line)[++j[0]] = '\0';
	if ((j[2] = verif_end(j, &c)) == 1)
		return (0);
	return (1);
}

int				read_gnl(char *c, int fd)
{
	int		ret;

	if ((ret = read(fd, c, BUFF_SIZE)) <= 0)
		return (ret);
	c[ret] = '\0';
	return (ret);
}

int				verif_end(int *i, char **c)
{
	if ((*c)[i[1]] == '\0')
	{
		free(*c);
		c = NULL;
		return (1);
	}
	else if ((*c)[i[1]] == '\n' && (*c)[i[1] + 1] != '\0')
	{
		ft_memcpy(*c, &(*c)[i[1] + 1], BUFF_SIZE - i[1]);
		(*c)[BUFF_SIZE - i[1] - 1] = '\0';
		return (2);
	}
	else if ((*c)[i[1]] == '\n' && (*c)[i[1] + 1] == '\0')
	{
		free(*c);
		*c = NULL;
		return (0);
	}
	if (*c == NULL)
		return (1);
	return (-1);
}
