/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caellis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/05 21:45:25 by caellis           #+#    #+#             */
/*   Updated: 2019/05/17 01:54:50 by caellis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>	//DELETE_ME

static size_t	ft_strccpyi(char **dst, char *src, int c)
{
	unsigned char	*d;
	unsigned char	*s;
	size_t			rb;

	d = (unsigned char *)*dst;
	s = (unsigned char *)*src;
	rb = 0;
	while (*s)
	{
		if (*s == (unsigned char)c)
			return (rb);
		*d++ = *s++;
		rb++;
	}
	return (rb);
}

static int	read_line(t_list **files, char **line, size_t fd)
{
	return (0);
}

static int	read_static_line(t_list **files, char **line, size_t fd)
{
	char			temp[BUFF_SIZE + 1];
	ssize_t			rb;
	char			*cue;
	char			*dst;
	enum e_flags	flag;

	cue = (char *)(*files)->content;
	dst = *line;
	flag = NONE_READ;
	if ((*files)->content)
	{
		if (ft_strccpyi(line, (*files)->content, (int)'\n') < ;
	}
	while (*cue)
	{
		flag = SOME_READ;
		if (*cue == '\n')
		{
			*dst = '\0';
			cue = ft_strdup(++cue);
			free((*files)->content);
			(*files)->content = cue;
			return (1);
		}
		*dst++ = *cue++;
	}
	if (flag == SOME_READ && !*cue)
		flag = MORE_READ;
	while ((rb = read(fd, temp, BUFF_SIZE)))
	{
		if (!((*files)->content = ft_strjoin((*files)->content, (char*)temp)) \
									|| rb < 0)
			return (-1);
		if (ft_strchr(temp, (int)'\n'))
		{
			while (*cue !=)
			{

			}
		}
	}
	return (0);	
}
	// если в files->content пусто (или мы дошли до конца files->content и не нашли \n)
	// читаем из файла в files->content И line
		// в конце каждого цикла считывания проверяем, не считали ли мы \n
		// в этом случае копируем все до \n из а


int			get_next_line(const int fd, char **line)
{
	static t_list	*files;
	int				nice_fd;
	char			*newstr;
	t_list			*retard;

	nice_fd = (size_t)fd;
	if (fd < 0 || !line || BUFF_SIZE < 1)
		return (-1);
	if (!(files))
	{
		if (!(files = ft_lstnew("\0", nice_fd)))
			return (-1);
	}
	if (files->content_size == nice_fd) 
			return (read_line(&files, line, nice_fd));
	while ((files = files->next))
	{
		if (files->content_size == nice_fd)
			return (read_line(&files, line, nice_fd));
	}
	if (!(retard = ft_lstnew("\0", nice_fd)))
		return (-1);
	ft_lstadd(&files, retard);
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