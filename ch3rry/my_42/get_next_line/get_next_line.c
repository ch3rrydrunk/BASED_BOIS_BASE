/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caellis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/05 21:45:25 by caellis           #+#    #+#             */
/*   Updated: 2019/05/23 18:23:34 by caellis          ###   ########.fr       */
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

static void		ft_add_file(t_file **files, t_file *new)
{
	t_file	*buff;

	if (files && (!*files) && new)
		*files = new;
	else if (files && *files && new)
	{
		buff = *files;
		*files = new;
		(*files)->next = buff;
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
	ft_add_file(files, buff);
	return (*files);
}

static long	ft_file2line_copy(char **line, t_file **cue)
{
	char	*file;
	char	*buff;
	long	rb;

	file = (*cue)->content;
	rb = 0;
	while (*file++)
	{
		if (*(file - 1) == (char)'\n')
			break ;
		rb++;
	}
	if (!(*line = ft_strnew(rb)))
			return (-1);
	if (!ft_memccpy((void *)*line, (*cue)->content, '\n', rb))
	{
		if (!(buff = ft_strnew(0)))
			return (-1);
	}
	else
	{
		if (!(buff = ft_strdup(file)))
			return (-1);
	}
	ft_strdel(&(*cue)->content);
	(*cue)->content = buff;
	return (rb);
}

int				get_next_line(const int fd, char **line)
{
	static t_file	*files;
	t_file			*cue;
	char			buff[BUFF_SIZE + 1];
	char			*temp;
	long			rb;

	ft_bzero((void *)buff, BUFF_SIZE + 1);
	if (!line || fd < 0 || BUFF_SIZE < 1 || !(cue = ft_get_file(&files, fd)) \
				|| read(fd, buff, 0) < 0)
		return (-1);
	while ((rb = read(fd, buff, BUFF_SIZE)))
	{
		if (!(temp = ft_strjoin(cue->content, buff)))
			return (-1);
		ft_strdel(&cue->content);
		cue->content = temp;
		if (ft_strchr(cue->content, (int)'\n'))
			break;
	}
	if (!(cue->content) || !*(cue->content))
	{
		ft_strdel(&cue->content);
		return (0);
	}
	if ((rb = ft_file2line_copy(line, &cue)) < 0)
		return (-1);
	return (1);
}


int				main(void)
{
	char		*line1;
	char		*line2;
	char		*line3;
	int			fd1;
	int			fd2;
	int			fd3;
	int			ret1;
	int			ret2;
	int			ret3;
	char		*filename1;
	char		*filename2;
	int			errors;

	filename1 = "./srcs/gnl/gnl11_1.txt";
	filename2 = "./srcs/gnl/gnl11_2.txt";
	fd1 = open(filename1, O_RDONLY);
	fd2 = open(filename2, O_RDONLY);
	fd3 = -1;
	if (fd1 > 2 && fd2 > 2)
	{
		errors = 0;
		line1 = NULL;
		line2 = NULL;
		line3 = NULL;

		ret1 = get_next_line(fd1, &line1);
		if (ret1 != 1 || strcmp(line1, "The getdelim() function reads a line from stream, delimited by the character") != 0)
		{
			printf("-> must have returned '1' and read line #1 \"The getdelim() function reads a line from stream, delimited by the character\" from file %s\n", filename1);
			errors++;
		}

		ret1 = get_next_line(fd1, &line1);
		if (ret1 != 1 || strcmp(line1, "delimiter.  The getline() function is equivalent to getdelim() with the new-") != 0)
		{
			printf("-> must have returned '1' and read line #2 \"delimiter.  The getline() function is equivalent to getdelim() with the new-\" from file %s\n", filename1);
			errors++;
		}

		ret1 = get_next_line(fd1, &line1);
		if (ret1 != 1 || strcmp(line1, "line character as the delimiter.  The delimiter character is included as") != 0)
		{
			printf("-> must have returned '1' and read line #3 \"line character as the delimiter.  The delimiter character is included as\" from file %s\n", filename1);
			errors++;
		}

		ret1 = get_next_line(fd1, &line1);
		if (ret1 != 1 || strcmp(line1, "part of the line, unless the end of the file is reached.") != 0)
		{
			printf("-> must have returned '1' and read line #4 \"part of the line, unless the end of the file is reached.\" from file %s\n", filename1);
			errors++;
		}

		ret2 = get_next_line(fd2, &line2);
		if (ret2 != 1 || strcmp(line2, "The Festival de Radio France et Montpellier is a summer festival of opera and other music held in Montpellier.") != 0)
		{
			printf("-> must have returned '1' and read line #1 \"The Festival de Radio France et Montpellier is a summer festival of opera and other music held in Montpellier.\" from file %s\n", filename2);
			errors++;
		}

		ret2 = get_next_line(fd2, &line2);
		if (ret2 != 1 || strcmp(line2, "The festival concentrates on classical music and jazz with about 150 events, including opera, concerts, films, and talks. ") != 0)
		{
			printf("-> must have returned '1' and read line #2 \"The festival concentrates on classical music and jazz with about 150 events, including opera, concerts, films, and talks. \" from file %s\n", filename2);
			errors++;
		}

		ret2 = get_next_line(fd2, &line2);
		if (ret2 != 1 || strcmp(line2, "Most of these events are free and are held in the historic courtyards of the city or in the modern concert halls of Le Corum. ") != 0)
		{
			printf("-> must have returned '1' and read line #3 \"Most of these events are free and are held in the historic courtyards of the city or in the modern concert halls of Le Corum. \" from file %s\n", filename2);
			errors++;
		}

		ret2 = get_next_line(fd2, &line2);
		if (ret2 != 1 || strcmp(line2, "Le Corum cultural and conference centre contains 3 auditoriums. ") != 0)
		{
			printf("-> must have returned '1' and read line #4 \"Le Corum cultural and conference centre contains 3 auditoriums. \" from file %s\n", filename2);
			errors++;
		}

		ret3 = get_next_line(fd3, &line3);
		if (ret3 != -1)
		{
			printf("-> must have returned '-1' with invalid file descriptor\n");
			errors++;
		}

		ret1 = get_next_line(fd1, &line1);
		if (ret1 != 1 || strcmp(line1, "") != 0)
		{
			printf("-> must have returned '1' and read line #5 \"\" from file %s\n", filename1);
			errors++;
		}

		ret1 = get_next_line(fd1, &line1);
		if (ret1 != 1 || strcmp(line1, "The caller may provide a pointer to a malloced buffer for the line in") != 0)
		{
			printf("-> must have returned '1' and read line #6 \"The caller may provide a pointer to a malloced buffer for the line in\" from file %s\n", filename1);
			errors++;
		}

		ret1 = get_next_line(fd1, &line1);
		if (ret1 != 1 || strcmp(line1, "*linep, and the capacity of that buffer in *linecapp.  These functions") != 0)
		{
			printf("-> must have returned '1' and read line #7 \"*linep, and the capacity of that buffer in *linecapp.  These functions\" from file %s\n", filename1);
			errors++;
		}

		ret1 = get_next_line(fd1, &line1);
		if (ret1 != 1 || strcmp(line1, "expand the buffer as needed, as if via realloc().  If linep points to a NULL") != 0)
		{
			printf("-> must have returned '1' and read line #8 \"expand the buffer as needed, as if via realloc().  If linep points to a NULL\" from file %s\n", filename1);
			errors++;
		}

		ret1 = get_next_line(fd1, &line1);
		if (ret1 != 1 || strcmp(line1, "pointer, a new buffer will be allocated.  In either case, *linep and") != 0)
		{
			printf("-> must have returned '1' and read line #9 \"pointer, a new buffer will be allocated.  In either case, *linep and\" from file %s\n", filename1);
			errors++;
		}

		ret1 = get_next_line(fd1, &line1);
		if (ret1 != 1 || strcmp(line1, "*linecapp will be up-dated accordingly.") != 0)
		{
			printf("-> must have returned '1' and read line #10 \"*linecapp will be up-dated accordingly.\" from file %s\n", filename1);
			errors++;
		}

		ret2 = get_next_line(fd2, &line2);
		if (ret2 != 1 || strcmp(line2, "The city is a center for cultural events since there are many students. ") != 0)
		{
			printf("-> must have returned '1' and read line #5 \"The city is a center for cultural events since there are many students. \" from file %s\n", filename2);
			errors++;
		}

		ret2 = get_next_line(fd2, &line2);
		if (ret2 != 1 || strcmp(line2, "Montpellier has two large concerts venues: Le Zenith Sud (7.000 seats) and L'Arena (14.000 seats).") != 0)
		{
			printf("-> must have returned '1' and read line #6 \"Montpellier has two large concerts venues: Le Zenith Sud (7.000 seats) and L'Arena (14.000 seats).\" from file %s\n", filename1);
			errors++;
		}

		ret1 = get_next_line(fd1, &line1);
		if (ret1 != 0)
		{
			printf("-> must have returned '0' at the end of file %s\n", filename1);
			errors++;
		}

		ret2 = get_next_line(fd2, &line2);
		if (ret2 != 0)
		{
			printf("-> must have returned '0' at the end of file %s\n", filename2);
			errors++;
		}

		close(fd1);
		close(fd2);
		if (errors == 0)
			printf("OK\n");
	}
	else
		printf("An error occured while opening files %s and/or %s\n", filename1, filename2);
	return (0);
}

/*
int				main(void)
{
	char		*line;
	int			fd;
	int			ret;

	ret = -100;
	fd = open("test_main.c", O_RDONLY);
	while((ret = get_next_line(fd, &line)))
	{
		if (ret == -1)
		{
			printf(":(\n");
			exit (-1);
		}
		printf("%s\n", line);
	}
	printf("\n\n\n\n\nThat's it?\n\n\n\n\n");

	fd = open("author", O_RDONLY);
	while((ret = get_next_line(fd, &line)))
	{
		if (ret == -1)
		{
			printf(":(\n");
			exit (-1);
		}
		printf("%s\n", line);
	}
	printf("\n\n\n\n\nThat's it?\n\n\n\n\n");

	ret = get_next_line(fd, &line);
	printf("This is bytes read from finished file: %i\n", ret);
	return (0);
}
*/