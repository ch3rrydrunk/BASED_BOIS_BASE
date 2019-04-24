/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormund <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/20 13:59:54 by cormund           #+#    #+#             */
/*   Updated: 2019/04/24 12:09:11 by cormund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
//#include <fcntl.h>

int				get_next_line(const int fd, char **line)
{
	static char *str_line = "";
	char		*buf;
	char		*s_end;
	char		*tmp_free;
	int			n;

	if (fd >= 0 && line && (buf = ft_strnew(BUFF_SIZE)))
	{
		if (!*str_line)
			str_line = ft_strnew(0);
		s_end = ft_strchr(str_line, '\n');
		while (!s_end && (n = read(fd, buf, BUFF_SIZE) > 0))
		{
//			tmp_free = str_line;
			str_line = ft_strjoin(str_line, buf);
//			free(tmp_free);
			s_end = ft_strchr(str_line, '\n');
		}
		ft_strdel(&buf);
		if ((*str_line || s_end) && n >= 0)
		{
			tmp_free = *line;
			if (s_end)
			{
				*line = ft_strndup(str_line, s_end - str_line);
				str_line = ft_strcpy(str_line, s_end + 1);
			}
			else
			{
				*line = ft_strdup(str_line);
				ft_strclr(str_line);
			}
//			if (tmp_free)
//				free(tmp_free);
			return (1);
		}
//	free(str_line);
		if (n != -1)
			return (0);
	}
	return (-1);
}

/*int			main(int ac, char **av)
{
	int		fd;
	char	*line;
	int 	k;

	fd = open(av[1], O_RDONLY);
	while ((k = get_next_line(fd, &line)) > 0)
		ft_putendl(line);
	if (k == -1)
		ft_putendl("shopa");
	return (0);
}*/
