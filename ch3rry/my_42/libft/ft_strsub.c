/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caellis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/27 15:26:44 by caellis           #+#    #+#             */
/*   Updated: 2019/04/27 16:30:04 by caellis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	int		maxl;

	sub = NULL;
	if (s && len)
	{
		maxl = ft_strlen(s);
		if ((sub = ft_strnew(len)) && maxl && maxl >= start + maxl - len)
			sub = ft_strncpy(sub, &s[start], len);
	}
	return (sub);
}