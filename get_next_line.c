/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbabahmi <zbabahmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 18:38:19 by zbabahmi          #+#    #+#             */
/*   Updated: 2022/12/12 18:47:57 by zbabahmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *helper(char *likan, int fd)
{
    char *buffer;
    int i;
    
    i = 1;
    buffer = calloc(BUFFER_SIZE + 1,1);
    while(i != 0 && !(ft_strchr(likan, '\n')))
    {
        i = read(fd, buffer, BUFFER_SIZE);
        if(i < 0)
        {
            free(likan);
            likan = 0;
            return 0;
        }
        buffer[i] = '\0';
        likan = ft_strjoin(likan, buffer);
    }
    free (buffer);
    return likan;
}

char *get_next_line(int fd)
{
    static char *likan;
    char *str;
    char *p;
    
    if(fd < 0 && BUFFER_SIZE <= 0)
        return 0;
    likan = helper(likan , fd);
    p = likan;
    if(!likan)
        return 0;
    if(likan[0] == '\0')
    {
        free(likan);
        likan = 0;
        return 0;
    }
    str = mkas(likan);
    likan = mos(likan);
    free(p);
    return str;
}