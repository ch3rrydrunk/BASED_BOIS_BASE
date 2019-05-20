/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caellis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/05 21:45:25 by caellis           #+#    #+#             */
/*   Updated: 2019/05/20 08:06:27 by caellis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>	//DELETE_ME

static t_list	*get_thefile(t_list **files, int fd)
{

	return (NULL);
}

int				get_next_line(const int fd, char **line)
{
	static t_list	*files;
	t_list			*cue;
	char			buff[BUFF_SIZE + 1];
	char			*tmp;
	size_t			rb;

	if (!line || fd < 0 || BUFF_SIZE < 1 \
				||read(fd, buff, 0) < 0 || (cue = get_thefile(&files, fd)))
		return (-1);
	while ((rb = read(fd, buff, BUFF_SIZE)))
	{
		buff[rb] = '\0';
		if (!(cue->content = ft_strjoin(cue->content, buff)))
			return (-1);
		if ((tmp = ft_strchr(cue->content, (int)'\n')))
			break ;
	}
	if (rb < BUFF_SIZE && !cue->content)
		return (0);
	// copy here - if we are here were are copying and returning 1
	
	//
	return (1);
}

int				main(void)
{
	char		line[BUFF_SIZE + 1];
	int			fd;
	int			ret;

	ret = -100;
	fd = open("get_next_line.h", O_RDONLY);
	ret = get_next_line(fd, (char**)&line);
	printf("%s\n", line);
	return (0);
}