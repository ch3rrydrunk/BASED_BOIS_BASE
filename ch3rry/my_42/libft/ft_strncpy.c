/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caellis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 17:47:34 by caellis           #+#    #+#             */
/*   Updated: 2019/04/08 20:20:15 by caellis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	char	*buff;

	if ((buff = dst) && src)
	{
		while (*src && len--)
			*(buff++) = *(src++);
		*buff = '\0';
		while (len--)
			*(buff++) = '\0';
	}
	return (dst);
}
