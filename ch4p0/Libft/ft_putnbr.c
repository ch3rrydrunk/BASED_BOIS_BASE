/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormund <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 14:44:43 by cormund           #+#    #+#             */
/*   Updated: 2019/04/17 16:10:01 by cormund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n)
{
	int minus;
	int len;
	int res;

	minus = 1;
	len = 10;
	if (n < 0)
	{
		minus = -1;
		write(1, "-", 1);
	}
	while (n / len)
		len *= 10;
	while (len)
	{
		len /= 10;
		res = n / len % 10 + '0';
		write (1, &res, 1);
	}
}
