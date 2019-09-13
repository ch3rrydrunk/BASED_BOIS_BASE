/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_options.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caellis <caellis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 10:53:57 by caellis           #+#    #+#             */
/*   Updated: 2019/09/12 11:09:35 by caellis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int					usage(void)
{
	write(1, "options: abcdefghijklmnopqrstuvwxyz", 35);
	return (0);
}

int					error(void)
{
	write(1, "Invalid Option", 14);
	return (0);
}

int					main(int ac, char **av)
{
	unsigned int	opts = 0;
	int				i = 1;
	if (ac > 1)
	{
		while(i < ac)
		{
			while(*(av[i]))
			{
				if (*(av[i]) < 97 || *(av[i]) > 122)
					return (error());
				else 
				{
					
				}
			}
		}
	}
	return (usage());
}