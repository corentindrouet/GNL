/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrouet <cdrouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/09 08:40:55 by cdrouet           #+#    #+#             */
/*   Updated: 2015/12/09 16:29:26 by cdrouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_next_line(int const fd, char **line)
{
	static char	*c = NULL;
	char		buf[BUFF_SIZE + 1];
	int			j;
	int			ret;

	j = -1;
	if (c == NULL)
	{
		ret = read(fd, buf, BUFF_SIZE);
		buf[ret + 1] = '\0';
		c = buf;
	}
	while (c[++j])
		if (c[j] != '\n')
		{
			(*line)[j] = c[j];
			if ((j + 1) == ret && ret == BUFF_SIZE)
			{
				ret = read(fd, buf, BUFF_SIZE);
				buf[ret + 1] = '\0';
				c = buf;
				j = -1;
			}
		}
		else
			break ;
	(*line)[j] = '\0';
	if (j == ret && ret < BUFF_SIZE)
		return (0);
	if (ret == BUFF_SIZE)
		return (1);
	return (-1);
}
