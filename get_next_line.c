/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrouet <cdrouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/09 08:40:55 by cdrouet           #+#    #+#             */
/*   Updated: 2015/12/10 16:11:10 by cdrouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int				get_next_line(int const fd, char **line)
{
	static char	*c = NULL;
	int			ret;

	INTJ();
	if (c == NULL)
	{
		c = (char*)malloc(sizeof(char) * (BUFF_SIZE + 1));
		if ((ret = read_gnl(c, fd)) <= 0)
			return (ret);
	}
	while (c[++j[1]] != '\n' && c[j[1]])
	{
		(*line)[++j[0]] = c[j[1]];
		if (c[j[1] + 1] == '\0')
		{
			if ((ret = read_gnl(c, fd)) <= 0)
				return (ret);
			j[1] = -1;
		}
	}
	(*line)[++j[0]] = '\0';
	if ((ret = verif_end(j, &c)) == 1)
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
		ft_strncpy(*c, &(*c)[i[1] + 1], BUFF_SIZE - i[1]);
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
