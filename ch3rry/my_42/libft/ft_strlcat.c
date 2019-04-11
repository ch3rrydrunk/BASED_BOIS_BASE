/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caellis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 17:42:41 by caellis           #+#    #+#             */
/*   Updated: 2019/04/11 21:26:54 by caellis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t		l_dst;
	size_t		l_src;

	l_dst = ft_strlen(dst);
	l_src = ft_strlen(src);
	if (size < l_dst + 1 || size == 0)
		return (l_dst + size);
	else if (*src)
		ft_strncat(dst + l_dst - 1, src, size - l_dst - 1);
	return (l_dst + l_src);
	
	
}
