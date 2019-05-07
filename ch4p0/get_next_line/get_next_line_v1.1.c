/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormund <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/20 13:59:54 by cormund           #+#    #+#             */
/*   Updated: 2019/04/24 21:14:17 by cormund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
//#include <fcntl.h>
//#include <stdio.h>

char			*ft_strcut(char *s, char c)
{
	char		*p;
	char		*fresh;

	if ((p = ft_strchr(s, c)))
		fresh = ft_strndup(s, p - s);
	else
		fresh = ft_strdup(s);
	return (fresh);
}

int				get_next_line(const int fd, char **line)
{
	static char *str_line = "";
	char		*buf;
	char		*s_end;
	char		*tmp_free;
	int			n;

	if (!(buf = ft_strnew(BUFF_SIZE)) || fd < 0 || !line || read(fd, buf, 0) < 0)
		return (-1);
	if (!*str_line)
		str_line = ft_strnew(0);
	while (!(s_end = ft_strchr(str_line, '\n')) && (n = read(fd, buf, BUFF_SIZE) > 0))
	{
		tmp_free = str_line;
		str_line = ft_strjoin(str_line, buf);
		ft_strdel(&tmp_free);
	}
	ft_strdel(&buf);
	*line = ft_strcut(str_line, '\n');
	if (s_end)
		str_line = ft_strcpy(str_line, s_end + 1);
	else
		ft_bzero(str_line, ft_strlen(str_line));
	if (n == 0 && !*str_line && !**line && !s_end)
		return (0);
	return (1);
}

/*int			main(int ac, char **av)
{
	int		fd;
	char	*line;
	int 	k;

	fd = open(av[1], O_RDONLY);
	while ((k = get_next_line(fd, &line)) > 0)
		printf("%s\n", line);
	if (k == -1)
		ft_putendl("shopa");
	return (0);
}*/
