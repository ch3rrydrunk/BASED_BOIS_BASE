/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caellis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/05 21:45:25 by caellis           #+#    #+#             */
/*   Updated: 2019/05/06 11:44:21 by caellis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "../libft/libft.h"

static void	*read_line(t_list	**buff, char **line)
{
	
}

int			 get_next_line(const int fd, char **line)
{
	static t_list	*buff;

	if (buff)
	buff = ft_lstnew(NULL, 0);
		printf("yes there is no *buff on the 1st launch");
	return (1);
}

int			main()
{
	char	line[1000];
	int		fd;

	fd = open("get_next_line.h", O_RDONLY);
	get_next_line(fd, &line);
	printf("%s\n", line);
	return (0);
}