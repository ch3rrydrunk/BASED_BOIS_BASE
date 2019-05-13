/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caellis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/05 21:45:25 by caellis           #+#    #+#             */
/*   Updated: 2019/05/13 15:51:45 by caellis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>	//DELETE_ME

static int	read_line(t_list	**files, char **line)
{
	char	*temp[BUFF_SIZE];
	long	rb;

	// проверить пустой ли files->content
		// если пустой (указывает на Нуль или начинается с \0): выделить память (BUFF_SIZE)
		// (ecли выделена память) считываем из входного_потока в files->content
		// ПОСЛЕ считывания (целиком) копируем из files->content в line пока не встретим \n или \0
			// ПОСЛЕ считывания кидаем 
	// 
	return (0);	
}

int			get_next_line(const int fd, char **line)
{
	static t_list	*files;
	char			buff[BUFF_SIZE + 1]

	if (!(fd > -1 && line && BUFF_SIZE > 0))
		return (-1);
	if (!(files))
	{
		if (!(files = ft_lstnew(ft_strnew(BUFF_SIZE), (size_t)fd)))
			return (-1);
	}
	if (files->content_size == (size_t)fd) 
			return (read_line(&files, line));
	while ((files = files->next))
	{
		if (files->content_size == (size_t)fd)
			return(read_line(&files, line));
	}
	ft_lstadd(&files, ft_lstnew(ft_strnew(BUFF_SIZE), (size_t)fd));
	return(read_line(&files, line));
}

int			main(void)
{
	char	line[BUFF_SIZE + 1];
	int		fd;
	int		ret;

	ret = -100;
	fd = open("get_next_line.h", O_RDONLY);
	ret = get_next_line(fd, (char**)&line);
	printf("%s\n", line);
	return (0);
}