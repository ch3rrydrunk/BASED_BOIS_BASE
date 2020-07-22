/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caellis <caellis@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/05 21:45:25 by caellis           #+#    #+#             */
/*   Updated: 2020/07/22 19:32:57 by caellis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int		read_file(const int fd, char **buff)
{
	char	*tmp;
	char	*tofree;
	int		n;

	if (!*buff)
		return (0);
	if (!(tmp = (char *)malloc(sizeof(char) * (BUFF_SIZE + 1))))
		return (0);
	while (!ft_strchr(*buff, '\n'))
	{
		if (!(n = read(fd, tmp, BUFF_SIZE)))
			break ;
		if (n < 0)
		{
			free(tmp);
			ft_memdel((void**)buff);
			return (0);
		}
		tmp[n] = '\0';
		tofree = *buff;
		*buff = ft_strjoin(*buff, tmp);
		free(tofree);
	}
	free(tmp);
	return (1);
}

static t_file	*new_file(const int fd)
{
	t_file	*file;

	if (!(file = (t_file *)malloc(sizeof(t_file))))
		return (NULL);
	if (!(file->content = (char *)malloc(sizeof(char) * (BUFF_SIZE + 1))))
	{
		free(file);
		return (NULL);
	}
	*file->content = '\0';
	file->fd = fd;
	file->next = NULL;
	return (file);
}

int				gnl_worker(const int fd, char **line, t_file **files)
{
	char			*buff;
	char			*eol;
	size_t			rb;

	ERR_CHECK(read(fd, (buff = NULL), 0) < 0);
	if (!*files)
		ERR_CHECK(!(*files = new_file(fd)));
	if (fd != (*files)->fd)
		return (gnl_worker(fd, line, &(*files)->next));
	buff = *(*files)->content ? ft_strdup((*files)->content) : ft_strnew(0);
	ERR_CHECK(!(read_file(fd, &buff)));
	if ((rb = ft_strlen(buff)))
	{
		eol = ft_strchr(buff, '\n');
		*line = (eol ? ft_strndup(buff, eol - buff) : ft_strdup(buff));
		if (eol)
			(*files)->content = ft_strcpy((*files)->content, eol + 1);
		else
			ft_bzero((*files)->content, BUFF_SIZE);
		ft_memdel((void **)&buff);
		return (1);
	}
	ft_memdel((void **)&buff);
	return (0);
}

int				get_next_line(const int fd, char **line)
{
	static t_file	*files;

	ERR_CHECK(!line || fd < 0 || BUFF_SIZE < 1);
	return (gnl_worker(fd, line, &files));
}
