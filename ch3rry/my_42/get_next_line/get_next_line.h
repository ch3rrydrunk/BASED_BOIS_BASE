/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caellis <caellis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/05 21:45:29 by caellis           #+#    #+#             */
/*   Updated: 2019/05/29 13:33:54 by caellis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <stdio.h>
# include "libft/includes/libft.h"

# define BUFF_SIZE 2040
# define ERR_CHECK(x) if (x) return (-1)

typedef struct		s_file
{
	char			*content;
	size_t			size;
	int				fd;
	struct s_file	*next;
}					t_file;

enum				e_modes
{
	ADD,
	DELETE
}					;

int					get_next_line(const int fd, char **line);
#endif
