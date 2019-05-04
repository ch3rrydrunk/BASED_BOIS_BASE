/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caellis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 13:53:39 by caellis           #+#    #+#             */
/*   Updated: 2019/05/04 16:37:38 by caellis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static size_t	countdigits(int n)
{
	size_t	i;

	i = (n < 0) ? 2 : 1;
	while ((n = n / 10))
		i++;
	return (i);
}

char			*ft_itoa(int n)
{
	char	*num;
	int		sign;
	int		i;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n == 0)
		return (ft_strdup("0"));
	sign = (n >= 0) ? 1 : -1;
	if ((num = ft_strnew(countdigits(n))))
	{
		n = (sign >= 0) ? n : -n;
		i = 0;
		while (n > 0)
		{
			num[i++] = n % 10 + '0';
			n /= 10;
		}
		if (sign < 0)
			num[i++] = '-';
		ft_strrev(num);
	}
	return (num);
}
