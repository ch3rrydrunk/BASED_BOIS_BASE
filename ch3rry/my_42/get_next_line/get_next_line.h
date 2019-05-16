/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caellis <caellis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/05 21:45:29 by caellis           #+#    #+#             */
/*   Updated: 2019/05/16 14:53:46 by caellis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GNL_H
# define GNL_H

#ifndef LIBFT_H
#include "../libft/libft.h"
#endif

# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>

# define BUFF_SIZE 2040

enum				e_flags
{
	ALL_READ,
	SOME_READ,
	NONE_READ,
	MORE_READ
};

/*
typedef struct		s_file
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;
*/

#endif
