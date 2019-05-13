/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caellis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/05 21:45:25 by caellis           #+#    #+#             */
/*   Updated: 2019/05/13 14:18:42 by caellis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>	//DELETE_ME

static int	read_line(t_list	**buff, char **line)
{
	char	*temp[BUFF_SIZE];
	long	rb;

	// проверить пустой ли buff->content
		// если пустой (указывает на Нуль или начинается с \0): выделить память (BUFF_SIZE)
		// (ecли выделена память) считываем из входного_потока в buff->content
		// ПОСЛЕ считывания (целиком) копируем из buff->content в line пока не встретим \n или \0
			// ПОСЛЕ считывания кидаем 
	// 
	return (0);	
}

int			get_next_line(const int fd, char **line)
{
	static t_list	*buff;
	int				rb;
	char			buf[BUFF_SIZE + 1];
	char			*cue;

	// Error-check + List creation
	if (!(fd > -1 && line && BUFF_SIZE > 0))
		return (-1);
	if (!(buff))
	{
		if (!(buff = ft_lstnew(NULL, 0)))
			return (-1);
		buff->content_size = (size_t)fd;
	}

	// find right node
	if (buff->content_size == (size_t)fd) 
		{
			// read to current node
			return (read_line(&buff, line));
		}
	while ((buff = buff->next))
	{
		if (buff->content_size == (size_t)fd)
			// read to current node
			return(read_line(&buff, line));
	}
	// OKAY, I haven't found any node (but ) - so let's add!
	//
	ft_lstadd(&buff, ft_lstnew(&buff, fd));
	return(read_line(&buff, line));

	return (1);
}

int			main(void)
{
	char	line[1000];
	int		fd;

	fd = open("get_next_line.h", O_RDONLY);
	get_next_line(fd, (char**)&line);
	printf("%s\n", line);
	return (0);
}