/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caellis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 13:50:03 by caellis           #+#    #+#             */
/*   Updated: 2019/04/08 14:20:39 by caellis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*st1;
	unsigned char	*st2;

	st1 = (unsigned char *)s1;
	st2 = (unsigned char *)s2;
	if (!(*st1) || !(*st2))
	{
		if (*st1 == '\0' && *st2 == '\0')
			return (0);
		return (*st1 - *st2);
	}
	while (n-- && (*st1 == *st2))
	{
		st1++;
		st2++;
	}
	return (*st1 - *st2);
}
