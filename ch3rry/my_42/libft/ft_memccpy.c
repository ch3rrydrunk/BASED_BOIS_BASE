/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caellis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 15:56:14 by caellis           #+#    #+#             */
/*   Updated: 2019/04/05 18:27:14 by caellis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void *ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*buff;
	unsigned char	*cast;
	unsigned char	x;

	if (dst == NULL || src == NULL || n == 0)
		return (NULL);
	buff = (unsigned char *)dst;
	cast = (unsigned char *)src;
	x = (unsigned char)c;
	while (n--)
	{
		*(buff++) = *(cast++);
		if (*cast == x)
			return (buff + 1);
	}
	return (NULL);
}
