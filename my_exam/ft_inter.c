/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_inter.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caellis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/24 16:24:13 by caellis           #+#    #+#             */
/*   Updated: 2019/08/24 18:42:44 by caellis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	hash_intersection(char *a, char *b)
{
	char	hash[256] = {0};

	while (*b)
	{
		if (hash[(int)*b] == 0)
			hash[(int)*b] = 1;
		b++;
	}
	while (*a)
	{
		if (hash[(int)*a] == 1)
		{
			write(1, a, 1);
			hash[(int)*a] = 2;
		}
		a++;
	}
}

int	main(int ac, char **av)
{	
	if (ac == 3)
		hash_intersection(av[1], av[2]);
	write(1, "\n",1);
	return (0);
}
