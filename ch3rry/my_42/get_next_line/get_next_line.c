/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caellis <caellis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/05 21:45:25 by caellis           #+#    #+#             */
/*   Updated: 2019/05/07 17:59:03 by caellis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>	//DELETE_ME

static int	read_line(t_list	**buff, char **line, int mode)
{
	return (NULL);	
}

int			get_next_line(const int fd, char **line)
{
	static t_list	*buff;
	t_list			*selecta;
	int				mode;

	if (fd > -1 && line && *line)
		return (-1);
	if (!(buff = (t_list*)malloc(sizeof(t_list)))
			return (-1);
	}
	if (buff->content_size == (size_t)fd)
		return (read_line(&buff, line, (mode=READF_L)));
	while ((buff = buff->next))
	{
		if (buff->content_size == (size_t)fd)
			return(read_line(&selecta, line, (mode=READF_L)));
	}
	ft_lstadd(&buff, ft_lstnew(&buff, fd));
	return(read_line(&buff, line, (mode=READF_I));

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