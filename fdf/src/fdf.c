/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caellis <caellis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 16:01:15 by caellis           #+#    #+#             */
/*   Updated: 2019/09/20 16:38:02 by caellis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

char			*read_map(t_image *map)
{
	char	*line;
	char	**split;

	while (get_next_line(map->fd, &line))
	{
		split = ft_strsplit(line, " ");
		while (*split)
		{
			
			map->width += 1 
			split++;
		}
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
	void		*x11;
	void		*mlx_pt;

	// if (ac == 2)
	// {
	// 	ZERO_IF_ERROR((x11 = mlx_init()))
	// 	ZERO_IF_ERROR((map.fd = open(av[1], O_RDONLY)))
	// 	ZERO_IF_ERROR(map.image = read_map(&map))
	// 	ZERO_IF_ERROR(output_fdf(map.fd, x11))
	// 	close(map.fd);
	// }
	x11 = mlx_init();
	mlx_pt = mlx_new_window(x11, 100, 100, "derp");
	return (0);
}
