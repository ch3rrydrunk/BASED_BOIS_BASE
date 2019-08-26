/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_union.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caellis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/24 18:17:55 by caellis           #+#    #+#             */
/*   Updated: 2019/08/24 18:37:04 by caellis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	hash_union(char *a, char *b)
{
	char	hash[256];

	while (*a)
	{
		if (hash[(int)*a] == 0)
		{
			hash[(int)*a] = 1;
			write(1, a, 1);
		}
		a++;
	}
	while (*b)
	{
		if (hash[(int)*b] == 0)
		{
			hash[(int)*b] = 1;
			write(1, b, 1);
		}
		b++;
	}
}

int	main(int ac, char **av)
{
	if (ac == 3)
		hash_union(av[1], av[2]);
	write(1, "\n",1);
	return (0);
}
