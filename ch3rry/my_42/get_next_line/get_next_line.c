/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caellis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/05 21:45:25 by caellis           #+#    #+#             */
/*   Updated: 2019/05/21 13:07:06 by caellis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>	//DELETE_ME

static size_t	readc_to_lst(t_list **files, int fd, int c)
{
	t_list		*cue;
	char		*buff;
	size_t		rb;
	size_t		t_rb;

	if (!files)
		
	cue = *files;
	t_rb = 0;
	while ((rb = read(fd, buff, BUFF_SIZE)))
	{
		buff[rb] = '\0';
		if (!(cue->content = ft_strjoin(cue->content, buff)))
			return (-1);
		if (buff = ft_strchr(cue->content, c))
		{
			while (&((cue->content)++) != buff)
				t_rb++;
			break ;
		}
		t_rb += rb;
	}
	return (t_rb);
}

static t_list	*get_file(t_list **files, int fd)
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
	size_t			t_rb;

	if (!line || fd < 0 || BUFF_SIZE < 1 \
							|| !(cue = get_file(&files, fd)))
		return (-1);
	if ((t_rb = readc_to_lst(&cue, fd, (int)'\n')) < 0)
		return (-1);
	
	ft_memccpy(*line, cue->content, (int)'\n', t_rb);
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
	char		*line;
	int			fd;
	int			ret;

	line = ft_strnew(BUFF_SIZE * 4);
	ret = -100;
	fd = open("get_next_line.c", O_RDONLY);
	while(ret = get_next_line(fd, &line))
	{
		printf("%s\n", line);
	}
	printf("That's it?\n");
	get_next_line(fd, &line);
	printf("%s\n", line);
	return (0);
}

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
	return (-1);
}