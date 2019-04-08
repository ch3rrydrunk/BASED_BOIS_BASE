/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caellis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 14:38:38 by caellis           #+#    #+#             */
/*   Updated: 2019/04/08 15:24:28 by caellis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*dup;

	dup = (char *)malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (!dup)
	{
		errno = ENOMEM;
		return (NULL);
	}
	while (*(s1++))
		*(dup++) = *s1;
	*dup = '\0';
   return (dup);	
}
