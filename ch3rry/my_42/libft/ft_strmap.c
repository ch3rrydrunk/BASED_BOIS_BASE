/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caellis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/22 16:51:52 by caellis           #+#    #+#             */
/*   Updated: 2019/04/25 17:49:44 by caellis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*map;
	char	*ret;

	ret = NULL;
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
