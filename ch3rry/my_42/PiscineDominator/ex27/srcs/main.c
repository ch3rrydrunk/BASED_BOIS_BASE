/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caellis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 14:42:09 by caellis           #+#    #+#             */
/*   Updated: 2019/04/05 12:26:31 by caellis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "file.h"

int	main(int argc, char **argv)
{
	int		fd;
	int		rd_b;
	char	buff[BIG_JUICY_BUFF + 1];

	if (argc < 2)
		return (ft_error("File name missing.\n"));
	else if (argc > 2)
		return (ft_error("Too many arguments.\n"));
	else
	{
		fd = open(argv[1], O_RDONLY);
		if (fd != -1)
		{
			rd_b = 1;
			while (rd_b > 0)
			{
				rd_b = read(fd, buff, BIG_JUICY_BUFF);
				buff[rd_b] = '\0';
				write(1, buff, ft_strlen(buff));
			}
			close(fd);
		}
		return (0);
	}
}
