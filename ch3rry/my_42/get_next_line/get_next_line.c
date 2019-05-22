/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caellis <caellis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/05 21:45:25 by caellis           #+#    #+#             */
/*   Updated: 2019/05/22 15:42:26 by caellis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>	//DELETE_ME

static long	readc_to_lst(t_list **files, int fd, int c)
{
	t_list		*cue;
	char		*buff;
	long		rb;
	long		t_rb;

	if (!files)
		return (-1);
	cue = *files;
	t_rb = 0;
	while ((rb = (long)read(fd, buff, BUFF_SIZE)))
	{
		buff[rb] = '\0';
		if (!(cue->content = ft_strjoin(cue->content, buff)))
			return (-1);
		if ((buff = ft_strchr(cue->content, c)))
			break ;
		t_rb += rb;
	}	
	while (*(char *)(cue->content) && *(char *)(cue->content) != (char)c)
	{
		(cue->content)++;
		t_rb++;
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
		return (*files);
	}
	return (NULL);
}

int				get_next_line(const int fd, char **line)
{
	static t_list	*files;
	t_list			*cue;
	long			t_rb;
	char			*buff;

	if (!line || fd < 0 || BUFF_SIZE < 1 \
			|| !(cue = get_file(&files, fd)) || !(*line = ft_strnew(BUFF_SIZE)))
		return (-1);
	if ((t_rb = readc_to_lst(&cue, fd, (int)'\n')) < 0)
		return (-1);
	if (!t_rb && !cue->content)
	{
		ft_strclr(cue->content);
		return (0);
	}
	buff = ft_memccpy(*line, cue->content, (int)'\n', t_rb);
	printf("%s\n\n\n%s\n", *line, (char *)cue->content);
	if (buff)
	{
		ft_memdel(&(cue->content));
		cue->content = ft_strdup(buff);
	}
	else
		ft_strdel(cue->content);
	return (1);
}

int				main(void)
{
	char		*line;
	int			fd;
	int			ret;

	ret = -100;
	fd = open("test_main.c", O_RDONLY);
	while((ret = get_next_line(fd, &line)))
	{
		printf("%s\n", line);
		free(line);
	}
	printf("That's it?\n");
	get_next_line(fd, &line);
	printf("%s\n", line);
	return (0);
}
