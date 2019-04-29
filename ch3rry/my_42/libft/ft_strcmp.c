/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caellis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 16:13:58 by caellis           #+#    #+#             */
/*   Updated: 2019/04/28 02:39:30 by caellis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	int	res;

	while (*s1 == *s2++)
	{
		if (*s1++ == '\0')
			return (0);
	}
	return (*(unsigned char *)s1 - *(unsigned char *)(s2 - 1));
}