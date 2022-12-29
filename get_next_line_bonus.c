/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbabahmi <zbabahmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 01:56:14 by zbabahmi          #+#    #+#             */
/*   Updated: 2022/12/29 01:57:53 by zbabahmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*helper(char *likan, int fd)
{
	char	*buffer;
	int		i;

	i = 1;
	buffer = calloc(BUFFER_SIZE + 1, 1);
	while (i != 0 && !(ft_strchr(likan, '\n')))
	{
		i = read(fd, buffer, BUFFER_SIZE);
		if (i < 0)
		{
			free (likan);
			likan = 0;
			return (0);
		}
		buffer[i] = '\0';
		likan = ft_strjoin(likan, buffer);
	}
	free (buffer);
	return (likan);
}

char	*get_next_line(int fd)
{
	static char	*likan[OPEN_MAX];
	char		*str;
	char		*p;

	if (fd < 0 && BUFFER_SIZE <= 0)
		return (0);
	likan[fd] = helper(likan[fd], fd);
	p = likan[fd];
	if (!likan[fd])
		return (0);
	if (likan[fd][0] == '\0')
	{
		free (likan[fd]);
		likan[fd] = 0;
		return (0);
	}
	str = mkas(likan[fd]);
	likan[fd] = mos(likan[fd]);
	free (p);
	return (str);
}
