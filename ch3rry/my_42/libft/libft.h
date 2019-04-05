/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caellis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 19:58:40 by caellis           #+#    #+#             */
/*   Updated: 2019/04/05 13:44:03 by caellis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H

# define LIBFT_H

#include <unistd.h>
#include <stdlib.h>
#include <string.h>

# define UC(n) (unsigned char)n

/*DELETE THIS AT ANY COST*/
#include <stdio.h>
/*UP TO THIS POINT*/

void	*ft_memset(void *s, int c, size_t len);
void	ft_bzero(void *s, size_t n);

#endif
