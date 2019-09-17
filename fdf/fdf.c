/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caellis <caellis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 16:01:15 by caellis           #+#    #+#             */
/*   Updated: 2019/09/17 16:35:18 by caellis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <stdio.h>
#include "mlx.h"

int8_t			output_fdf(int32_t fd)
{
	return (0);
}

int32_t			main(int32_t ac, char **av)
{
	int32_t		map_fd;

	if (ac == 2)
	{
		// init X11 server
		if ((map_fd = open(av[1], O_RDONLY)) && output_fdf(map_fd))
			perror("fdf");
		close(map_fd);
	}
	return (0);
}