/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caellis <caellis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 12:37:23 by caellis           #+#    #+#             */
/*   Updated: 2019/09/20 16:31:54 by caellis          ###   ########.fr       */
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