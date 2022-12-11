/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbabahmi <zbabahmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 18:38:19 by zbabahmi          #+#    #+#             */
/*   Updated: 2022/12/11 20:02:38 by zbabahmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *helper(char *likan, int fd)
{
    char buffer[BUFFER_SIZE + 1];
    int i;
    
    i = 1;
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
    return likan;
}

char *get_next_line(int fd)
{
    static char *likan;
    char *str;
    
    if(fd < 0 && BUFFER_SIZE <= 0)
        return 0;
    likan = helper(likan , fd);
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
    return str;
}