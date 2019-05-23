/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caellis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/05 21:45:29 by caellis           #+#    #+#             */
/*   Updated: 2019/05/23 14:43:17 by caellis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GNL_H
# define GNL_H

#ifndef LIBFT_H
#include "../libft.h"
#endif

# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <stdio.h>

# define BUFF_SIZE 2040

typedef struct		s_file
{
	char			*content;
	size_t			size;
	int				fd;
	struct s_file	*next;
}					t_file;


int					get_next_line(const int fd, char **line);
#endif
