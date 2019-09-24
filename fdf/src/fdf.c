/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ch3rryhq <ch3rryhq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 16:01:15 by caellis           #+#    #+#             */
/*   Updated: 2019/09/24 16:14:42 by ch3rryhq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

char			*read_map(t_image *map)
{
	char	*line;
	char	**split;
	int		width;

	map->image->next = NULL;
	while (get_next_line(map->fd, &line))
	{
		split = ft_strsplit(line, ' ');
		while (*split)
		{
			//add vectors to image here
			width++;
			split++;
			if (width >= map->width)
				map->width = width;
		}
		map->height += 1;
	}
	return(NULL);
}

int8_t			output_fdf(int32_t fd, void *x11)
{
	return (0);
}

int32_t			main(int32_t ac, char **av)
{
	t_image		map;
	void		*mlx_ptr;

	ft_bzero((void *)&map, sizeof(t_image));
	if (ac == 2)
	{
		ZERO_IF_ERROR((mlx_ptr = mlx_init()))
		ZERO_IF_ERROR((map.fd = open(av[1], O_RDONLY)))
		ZERO_IF_ERROR(map.image = read_map(&map))
		//ZERO_IF_ERROR(output_fdf(map.fd, mlx_ptr))
		mlx_loop(mlx_ptr);
		close(map.fd);
	}
	return (0);
}
