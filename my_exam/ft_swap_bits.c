/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_bits.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caellis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/24 18:45:26 by caellis           #+#    #+#             */
/*   Updated: 2019/08/24 19:23:52 by caellis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>		//* remember to get rid og this boi

void	print_bits(unsigned char octet)
{
	char i = 8;
	char result[9];

	while (i-- >= 0)
		result[7 - i] = ((octet >> i) & 1) + 48;
	write(1, result, 8);
}

unsigned char	ft_swap_bits(unsigned char octet)
{
	return (octet << 4 | octet >> 4);
}

int	main(int ac, char **av)
{
	unsigned char 	test = 0;

	if (ac == 2)
	{
		test = (unsigned char)atoi(av[1]);
		print_bits(test);
		write(1, "\n", 1);
		test = ft_swap_bits(test);
		print_bits(test);
	}

}
