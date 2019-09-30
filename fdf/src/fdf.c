/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caellis <caellis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 16:01:15 by caellis           #+#    #+#             */
/*   Updated: 2019/09/30 17:32:53 by caellis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_vec			*scaled_img(t_image *map)
{
	int32_t		s_factor;

	s_factor = (map->height * WIN_W) / (map->width * WIN_H);
	return (smul_vec(map->img, s_factor));
}

t_vec			*read_map(t_image *map)
{
	char	*line;
	char	**split;
	int		wid;

	map->img->next = NULL;
	while (get_next_line(map->fd, &line))
	{
		split = ft_strsplit(line, ' ');
		while (*split)
		{
			add_vec(&(map->img), new_vec(wid, map->height, ft_atoi(*split)));
			if (map->img == NULL)
				return (clean_vec(&(map->img)));
			wid++;
			split++;
			if (wid >= map->width)
				map->width = wid;
		}
		wid = 0;
		map->height += 1;
	}
	if (!map->img->next)
		return (NULL);
	return(scaled_img(map));
}

int8_t			output_fdf(t_image *map, void *x11)
{
	// Scale map->img
	// Draw lines
	// 
	return (0);
}

int32_t			main(int32_t ac, char **av)
{
	t_image		map;
	void		*mlx_ptr;

	ft_bzero((void *)&map, sizeof(t_image));
	if (ac == 2)
	{
		ZERO_IF_ERROR(mlx_ptr = mlx_init())
		ZERO_IF_ERROR((map.fd = open(av[1], O_RDONLY)))
		ZERO_IF_ERROR(map.img = read_map(&map))
		//ZERO_IF_ERROR(output_fdf(&map, mlx_ptr))
		while (map.img->next)
		{
			mlx_pixel_put(mlx_ptr, mlx_new_window(mlx_ptr, WIN_W, WIN_H, "derp"), map.img->x, map.img->y, 0x14278d);
			map.img = map.img->next;
		}
		mlx_loop(mlx_ptr);
		close(map.fd);
		// free(map and stuff in map)
	}
	return (0);
}
