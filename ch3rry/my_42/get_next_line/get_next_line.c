/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caellis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/05 21:45:25 by caellis           #+#    #+#             */
/*   Updated: 2019/05/17 02:04:56 by caellis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>	//DELETE_ME

int			get_next_line(const int fd, char **line)
{
	static t_list	*files;
	
	return (0);
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