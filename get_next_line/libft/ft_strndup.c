/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caellis <caellis@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 17:19:05 by caellis           #+#    #+#             */
/*   Updated: 2020/07/22 19:33:47 by caellis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s, size_t n)
{
	char	*dup;

	dup = ft_strnew(ft_strlen(s));
	if (dup)
		ft_strncpy(dup, s, n);
	return (dup);
}
