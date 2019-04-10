/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormund <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 17:16:56 by cormund           #+#    #+#             */
/*   Updated: 2019/04/10 18:46:51 by cormund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strstr(const char *haystack, const char *needle)
{
	char	*a;
	char	*b;
	size_t	len;
	size_t	l;

	if (!*(needle))
		return ((char*)haystack);
	l = 0;
	len = ft_strlen(needle);
	b = (char *)needle;
	while (*(haystack) != '\0')
	{
		if (*(haystack) == *(needle))
		{
			a = (char *)haystack;
			while (*(a++) == *(b++))
				l++;
			if (l == len)
				return ((char*)haystack);
			l = 0;
			b = (char*)needle;
		}
		haystack++;
	}
	return ((void*)0);
}
