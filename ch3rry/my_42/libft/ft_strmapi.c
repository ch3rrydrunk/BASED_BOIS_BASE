/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caellis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 17:52:21 by caellis           #+#    #+#             */
/*   Updated: 2019/04/25 18:01:30 by caellis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(char))
{
	char	*map;
	char	*ret;

	if (s && f)
	{
		map = ft_strdup(s);
		ret = map;
		while (map && *map)
		{
			*map = (*f)(*map);
			map++;
		}
	}
	return (ret);
}
