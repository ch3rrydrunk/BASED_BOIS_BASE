/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caellis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/22 16:51:52 by caellis           #+#    #+#             */
/*   Updated: 2019/04/22 17:23:47 by caellis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*map;

	if (s && f)
	{
		map = ft_strcpy(ft_strnew(ft_strlen(s)), s);
		while (*s)
			*map++ = (*f)(*map);
	}
	return (map);
}
