/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 13:53:07 by exam              #+#    #+#             */
/*   Updated: 2019/09/12 14:29:29 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int			main(int ac, char **av)
{
	unsigned int	options = 0;
	int				i = 1;
	int				j = 0;
	char			c = 0;

	if (ac > 1)
	{
		while (i < ac)
		{
			while (av[i][j])
			{
				if (av[i][j] == '-')
					j++;
				if (av[i][j] >= 'a' && av[i][j] <= 'z')
				{
					options |= (1U << (av[i][j] - 'a'));
					j++;
				}
				else
				{
					write(1, "Invalid Option\n", 15);
					return (1);
				}
			}
			i++;
			j = 0;
		}
		i = 32;
		if (((options >> 7) & 1U) == 1)
		{
			write(1, "options: abcdefghijklmnopqrstuvwxyz\n", 36);
			return (0);
		}
		while (i--)
		{
			c = ((options >> i) & 1U) + 48U;
			write(1, &c, 1);
			if (i % 8 == 0 && i)
				write (1, " ", 1);
		}
		write(1, "\n", 1);
	}
	else
		write(1, "options: abcdefghijklmnopqrstuvwxyz\n", 36);
	return (0);
}
