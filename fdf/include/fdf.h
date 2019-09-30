/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caellis <caellis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 12:37:23 by caellis           #+#    #+#             */
/*   Updated: 2019/09/30 17:45:04 by caellis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

#include <fcntl.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <stdio.h>
#include "mlx.h"
#include "libft.h"
#include "keys.h"

# define NULL_IF_ERROR(x) if (!(x)) {perror("fdf"); return (NULL);}
# define ZERO_IF_ERROR(x) if (!(x)) {perror("fdf"); return (0);}
# define WIN_W 1920
# define WIN_H 1080

typedef struct		s_vec
{
	u_int32_t		x;
	u_int32_t		y;
	u_int32_t		z;
	struct s_vec	*next;
}					t_vec;

typedef struct		s_map
{
	int				fd;
	int				width;
	int				height;
	int				col_1;
	int				col_2;
    t_vec			*img;
}					t_image;

t_vec		*new_vec(int	x, int y, int z);
void		add_vec(t_vec **img, t_vec *pnt);
t_vec		*smul_vec(t_vec *img, int scalar);
void		*clean_vec(t_vec **img);

#endif
