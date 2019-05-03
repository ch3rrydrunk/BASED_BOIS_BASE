/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caellis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/27 15:26:56 by caellis           #+#    #+#             */
/*   Updated: 2019/05/03 20:10:37 by caellis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_strnequ(char const *s1, char const *s2, size_t n)
{
	int	ans;

	ans = -1;
	if (n == 0)
		return (1);
	if (s1 && s2 && n)
		ans = ft_strncmp(s1, s2, n) ? 0 : 1;
	return (ans);
}
