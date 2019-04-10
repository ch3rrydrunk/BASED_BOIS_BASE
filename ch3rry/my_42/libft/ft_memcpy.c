/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caellis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 13:50:03 by caellis           #+#    #+#             */
/*   Updated: 2019/04/10 16:14:05 by caellis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*buff;
	unsigned char	*cast;

	buff = (unsigned char *)dst;
	cast = (unsigned char *)src;
	while (n--)
		*(buff++) = *(cast++);
	return (dst);
}
