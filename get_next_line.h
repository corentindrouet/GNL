/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrouet <cdrouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/09 08:41:13 by cdrouet           #+#    #+#             */
/*   Updated: 2015/12/10 16:10:21 by cdrouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>
# include "libft.h"
# define BUFF_SIZE 8
# define INTJ()	int	j[2] = {-1, -1}

int				get_next_line(int const fd, char **line);
int				verif_end(int *i, char **c);
int				read_gnl(char *c, int fd);

#endif
