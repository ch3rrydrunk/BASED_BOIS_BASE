/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_bits.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caellis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 13:17:05 by caellis           #+#    #+#             */
/*   Updated: 2019/08/24 19:13:18 by caellis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_bits(unsigned char octet)
{
	char i = 8;
	char result[9];

	while (i-- >= 0)
		result[7 - i] = ((octet >> i) & 1) + 48;
	write(1, result, 8);
}

int	main(void)
{
	ft_print_bits(2U);
	return (0);
}
