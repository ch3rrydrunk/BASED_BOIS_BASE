/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caellis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/05 21:45:25 by caellis           #+#    #+#             */
/*   Updated: 2019/05/20 12:12:46 by caellis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>	//DELETE_ME

static size_t	ft_count_char(void **s, int c, size_t *t_rb)
{
	char	*buff;
	char	waldo;
	size_t	size;
	size_t	rb;

	buff = (char *)*s;
	waldo = (char)c;
	size = ft_strlen(buff) + 1;
	rb = 0;
	while (size--)
	{
		if (*buff == waldo)
			return (rb);
		buff++;
		rb++;
		(*t_rb)++;
	}
	return (rb);
}

static t_list	*get_thefile(t_list **files, int fd)
{
	t_list	*buff;
	char	*newstr;
	size_t	st_fd;

	buff = *files;
	st_fd = (size_t)fd;
	while (buff)
	{
		if (buff->content_size == st_fd)
			return (buff);
		buff = buff->next;
	}
	if ((newstr = ft_strdup("")))
	{
		buff = ft_lstnew(newstr, st_fd);
		ft_lstadd(files, buff);
		buff = *files;
		return (buff);
	}
	return (NULL);
}

int				get_next_line(const int fd, char **line)
{
	static t_list	*files;
	t_list			*cue;
	char			buff[BUFF_SIZE + 1];
	size_t			rb;
	size_t			t_rb;

	if (!line || fd < 0 || BUFF_SIZE < 1 ||read(fd, buff, 0) < 0 || (cue = get_thefile(&files, fd)))
		return (-1);
	while ((rb = read(fd, buff, BUFF_SIZE)))
	{
		buff[rb] = '\0';
		if (!(cue->content = ft_strjoin(cue->content, buff)))
			return (-1);
		if (ft_count_char(&cue->content, (int)'\n', &t_rb) < rb)
			break;
		t_rb += rb;
	}
	*line = ft_memccpy((void *)*line, cue->content, (int)'\n', t_rb);
	cue->content += t_rb;
	if (!t_rb && !cue->content)
	{
		ft_strclr(cue->content);
		return (0);
	}
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