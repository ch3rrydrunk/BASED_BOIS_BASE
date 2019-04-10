/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caellis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 17:42:41 by caellis           #+#    #+#             */
/*   Updated: 2019/04/10 22:26:34 by caellis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	l_dst;
	char	*cat;
	char	*org;

	cat = dst;
	l_dst = 0;
	while (*cat++ && (l_dst < size))
		l_dst++;
	while (*org && (l_dst < size - 1))
	{
		*(cat++) = *(org++);
		l_dst++;
	}
	if (l_dst < size)
		*cat  = '\0';
	return (l_dst + (org - src));
}
