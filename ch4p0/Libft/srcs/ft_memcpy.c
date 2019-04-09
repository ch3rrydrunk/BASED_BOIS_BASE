/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormund <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 09:50:56 by cormund           #+#    #+#             */
/*   Updated: 2019/04/08 14:39:06 by cormund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *restrict dst, const void *restrict src, size_t n)
{
	unsigned char *dst_str;

	dst_str = (unsigned char *)dst;
	while (n--)
		*(unsigned char *)(dst_str++) = *(unsigned char *)(src++);
	return ((void *)dst);
}
