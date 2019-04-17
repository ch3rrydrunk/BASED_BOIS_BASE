/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormund <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 16:17:37 by cormund           #+#    #+#             */
/*   Updated: 2019/04/17 16:32:23 by cormund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int len;
	int minus;
	char res;

	len = 10;
	minus = 1;
	if (n < 0)
	{
		minus = -1;
		ft_putchar_fd('-', fd);
	}
	while (n / len)
		len *= 10;
	while (len)
	{
		len /= 10;
		res = n / len % 10 +'0';
		ft_putchar_fd(res, fd);
	}
}
