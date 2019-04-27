/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ch3rryhq <ch3rryhq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 12:28:27 by ch3rryhq          #+#    #+#             */
/*   Updated: 2019/04/26 13:49:36 by ch3rryhq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_strnequ(char const *s1, char const *s2, size_t n)
{
	int	ans;

	ans = -1;
	if (s1 && s2 && n)
		ans = ft_strncmp(s1, s2, n) ? 0 : 1;
	return (ans); 
}
