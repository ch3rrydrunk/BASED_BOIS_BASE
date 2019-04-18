/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caellis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 12:53:09 by caellis           #+#    #+#             */
/*   Updated: 2019/04/18 13:57:35 by caellis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*waldo;
	size_t	len;

	len = ft_strlen(s);
	while (len--)
	{
		if (waldo[len - 1] == (unsigned char)c)
			return (&waldo[len - 1]);
	}
	return (NULL);
}
