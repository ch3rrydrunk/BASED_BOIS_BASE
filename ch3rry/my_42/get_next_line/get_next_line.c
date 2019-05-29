/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caellis <caellis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/05 21:45:25 by caellis           #+#    #+#             */
/*   Updated: 2019/05/29 15:19:22 by caellis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static t_file	*ft_new_file(const char *content, const int fd)
{
	t_file	*file;
	size_t	size;

	if (content)
		size = ft_strlen(content);
	if ((file = (t_file *)malloc(sizeof(t_file))))
	{
		if (!content)
		{
			file->content = NULL;
			file->size = -1;
		}
		else if ((file->content = ft_strnew(size)))
		{
			ft_memcpy(file->content, content, size);
			file->size = size + 1;
		}
		else
			return (NULL);
		file->fd = fd;
		file->next = NULL;
	}
	return (file);
}

static void		ft_move_file(t_file **files, t_file *new, int mode)
{
	t_file	*buff;

	if (mode == ADD)
	{
		if (files && (!*files) && new)
			*files = new;
		else if (files && *files && new)
		{
			buff = *files;
			*files = new;
			(*files)->next = buff;
		}
	}
	else if (files && *files)
	{
		ft_strdel(&((*files)->content));
		free(*files);
		*files = NULL;
	}
}

static t_file	*ft_get_file(t_file **files, int fd)
{
	t_file	*buff;

	buff = *files;
	while (buff)
	{
		if (buff->fd == fd)
			return (buff);
		buff = buff->next;
	}
	buff = ft_new_file("", fd);
	ft_move_file(files, buff, ADD);
	return (*files);
}

static long		ft_file2line_copy(char **line, t_file **cue)
{
	char	*file;
	char	*buff;
	long	rb;
	long	c_rb;

	file = (*cue)->content;
	rb = 0;
	while (*file++)
	{
		if (*(file - 1) == (char)'\n')
			break ;
		rb++;
	}
	ERR_CHECK((!(buff = ft_strdup(file))));
	ERR_CHECK((!(*line = ft_strnew(rb))));
	*line = (char *)ft_memcpy(*line, (*cue)->content, rb);
	c_rb = (long)ft_strlen((*cue)->content);
	ft_strdel(&(*cue)->content);
	if (c_rb != rb)
		(*cue)->content = buff;
	else
		ft_strdel(&buff);
	return (rb);
}

int				get_next_line(const int fd, char **line)
{
	static t_file	*files;
	t_file			*cue;
	char			buff[BUFF_SIZE + 1];
	char			*temp;
	long			rb;

	ERR_CHECK(!line || fd < 0 || BUFF_SIZE < 1 \
				|| !(cue = ft_get_file(&files, fd)) || read(fd, buff, 0) < 0);
	while ((rb = read(fd, buff, BUFF_SIZE)))
	{
		buff[rb] = '\0';
		ERR_CHECK(!(temp = ft_strjoin(cue->content, buff)));
		ft_strdel(&cue->content);
		cue->content = temp;
		if (ft_strchr(cue->content, (int)'\n'))
			break ;
	}
	if (!(cue->content) || !*(cue->content))
	{
		ft_move_file(&files, NULL, DELETE);
		return (0);
	}
	ERR_CHECK((rb = ft_file2line_copy(line, &cue)) < 0);
	return (1);
}
