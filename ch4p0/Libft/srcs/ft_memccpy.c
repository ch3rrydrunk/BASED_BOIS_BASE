/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormund <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 16:14:07 by cormund           #+#    #+#             */
/*   Updated: 2019/04/08 17:45:23 by cormund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void    *ft_memccpy(void *restrict dst, const void *restrict src, int c, size_t n)
{
	while (n--)
	{
		if ((*(unsigned char *)(dst++) = *(unsigned char *)(src++)) == (unsigned char)c)
			return (dst);
	}
	return ((void*)0);
}
