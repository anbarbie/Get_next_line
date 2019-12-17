/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antbarbi <antbarbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 17:40:49 by antbarbi          #+#    #+#             */
/*   Updated: 2019/12/17 01:09:13 by antbarbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
** Function "cut" : cut and stock the extra string for the next call of the function
** If the cut is not possible then error is returned
** Function "ft_readbuff" : read and stock the line 
** Strnchr : Check '/n' until Buffer_size;
*/

static int	cut(char **stock)
{
	int i;
	char *tmp;

	i = 0;
	tmp = *stock;
	while(tmp[i])
	{
		if (tmp[i] == '\n')
		{
			i++;
			break ;
		}
		i++;
	}
	if (!(*stock = ft_substr(tmp, i, ft_strlen(tmp))))
		return (-1);
	free(tmp);
	return (0);
}

static int	ft_readbuff(int fd, char *buff, char **stock)
{
	int		rd;
	char	*tmp;
	
	while (rd = read(fd, buff, BUFFER_SIZE))
	{
		buff[rd] = '\0';
		tmp = *stock;
		if(!(*stock = ft_strjoin(tmp, buff)))
			return (-1);
		free(tmp);
		if (ft_strnchr(buff, '\n', BUFFER_SIZE))
			break ;
	}
	return (rd);
}

 int		get_next_line(int fd, char **line)
 {
	char	buff[BUFFER_SIZE + 1];
	int		rd;
	char	*stock;

	if (read(fd, NULL, 0) < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
	if (!stock)
	{
		if (!(stock = malloc(sizeof(char))))
			return (-1);
		stock[0] = '\0';
	}
	if (rd = ft_readbuff(fd, buff, &stock) == -1)
		return (-1);
	*line = ft_strndup(stock);
	if (!ft_strnchr(stock, '\n', ft_strlen(stock)))
	{
		free(stock);
		stock = NULL;
		return (0);
	}
	if (cut(&stock) == -1)
		return (-1);
	return (1);
 }
