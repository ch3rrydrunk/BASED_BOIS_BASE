/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caellis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 10:14:47 by caellis           #+#    #+#             */
/*   Updated: 2019/04/06 11:36:27 by caellis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*buff;
	unsigned char	waldo;
	int				i;

	if (s == NULL || n == 0)
		return (NULL);
	buff = (unsigned char *)s;
	waldo = (unsigned char)c;
	i = 0;
	while (*buff != waldo && n--)
	{
		buff++;
		i++;
	}
	if (*buff == waldo)
		return (buff);
	return (NULL);
}
