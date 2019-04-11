/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caellis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 17:42:41 by caellis           #+#    #+#             */
/*   Updated: 2019/04/11 13:53:02 by caellis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t		l_dst;
	char		*cat;
	const char	*s;

	cat = dst;
	s = src;
	l_dst = 0;
	while (*cat && size)
	{
		cat++;
		size--;
	}
	l_dst = cat - dst;
	if (size == 0)
		return (l_dst + ft_strlen(src));
	while (*s && size != 1)
	{
		*cat++ = *s;
		size--;
		s++;
	}
	*cat = '\0';
	return (l_dst + (s - src));
}
