/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caellis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 17:42:41 by caellis           #+#    #+#             */
/*   Updated: 2019/04/09 20:26:51 by caellis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	rb;
	char	*buff;

	if (dst && src && (size != 0))
	{
		rb = 0;
		buff = dst;
		while (*buff)
		{
			buff++;
			size--;
		}
		while (size--)
		{
			buff[rb] = *(src++);
			rb++;
		}
		*buff = '\0';
	}
	return (rb - size);
}
