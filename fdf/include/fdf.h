/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ch3rryhq <ch3rryhq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 12:37:23 by caellis           #+#    #+#             */
/*   Updated: 2019/09/24 16:15:04 by ch3rryhq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <stdio.h>
#include "mlx.h"
#include "libft.h"

#ifndef FDF_H
# define FDF_H

# define NULL_IF_ERROR(x) if (!(x)) {perror("fdf"); return (NULL);}
# define ZERO_IF_ERROR(x) if (!(x)) {perror("fdf"); return (0);}

typedef struct		s_vec
{
	u_int32_t		x;
	u_int32_t		y;
	u_int32_t		z;
	struct s_pixel	*next;
}					t_vec;

typedef struct		s_map
{
	int				fd;
	int				width;
	int				height;
	int				col_1;
	int				col_2;
    t_vec			*image;
}					t_image;

t_vec		*new_vector(int	x, int y, int z);
void		add_vector(t_vec *img,)

#endif
