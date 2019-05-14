/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caellis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/05 21:45:25 by caellis           #+#    #+#             */
/*   Updated: 2019/05/14 03:14:39 by caellis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>	//DELETE_ME

static int	read_line(t_list	**files, char **line, size_t fd)
{
	char	*temp[BUFF_SIZE + 1];
	ssize_t	rb;
	char	*cue;

	while ((rb = read(fd, temp, BUFF_SIZE)))
	{
		if (!((*files)->content = ft_strjoin((*files)->content, (char*)temp)) \
									|| rb < 0)
			return (-1);
	}
	// считать из files->content в line
	return (0);	
}

int			get_next_line(const int fd, char **line)
{
	static t_list	*files;
	int				nice_fd;
	char			*newstr;
	t_list			*retard;

	files = NULL;
	nice_fd = (size_t)fd;
	if (!(newstr = ft_strnew(1)) || fd < 0 || !line || BUFF_SIZE < 1)
		return (-1);
	if (!(files))
	{
		if (!(files = ft_lstnew(newstr, nice_fd)))
			return (-1);
	}
	if (files->content_size == nice_fd) 
			return (read_line(&files, line, nice_fd));
	while ((files = files->next))
	{
		if (files->content_size == nice_fd)
			return (read_line(&files, line, nice_fd));
	}
	if (!(retard = ft_lstnew(newstr, nice_fd)))
		return (-1);
	ft_lstadd(&files,  retard);
	return (read_line(&files, line, nice_fd));
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