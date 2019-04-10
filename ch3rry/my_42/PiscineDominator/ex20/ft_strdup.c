/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caellis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 15:45:06 by caellis           #+#    #+#             */
/*   Updated: 2019/04/04 13:59:08 by caellis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_strlen(char *str)
{
	int		i;
	char	*p_str;

	i = 0;
	p_str = str;
	while (*p_str++)
		i++;
	return (i);
}

char	*ft_strdup(char *src)
{
	char	*cp;
	int		i;

	cp = (char*)malloc(sizeof(char) * (ft_strlen(src) + 1));
	if (!cp)
		return (NULL);
	i = 0;
	while (i < ft_strlen(src))
	{
		cp[i] = src[i];
		i++;
	}
	cp[i] = '\0';
	return (cp);
}
