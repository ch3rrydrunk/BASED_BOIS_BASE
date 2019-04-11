/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caellis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 17:47:34 by caellis           #+#    #+#             */
/*   Updated: 2019/04/11 10:45:26 by caellis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	char	*buff;

	if (((buff = dst) || src) && len != 0)
	{
		while (len && *src)
		{
			*(buff++) = *(src++);
			len--;
		}
		if (len)
			ft_bzero(buff, len);
	}
	return (dst);
}
