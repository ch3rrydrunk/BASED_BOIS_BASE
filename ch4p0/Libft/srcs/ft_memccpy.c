/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormund <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 16:14:07 by cormund           #+#    #+#             */
/*   Updated: 2019/04/09 17:12:58 by cormund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *restrict d, const void *restrict s, int c, size_t n)
{
	unsigned char *buf;

	buf = (unsigned char *)s;
	while (n--)
	{
		if ((*(unsigned char *)(d++) = *(buf++)) == (unsigned char)c)
			return (d);
	}
	return ((void*)0);
}
