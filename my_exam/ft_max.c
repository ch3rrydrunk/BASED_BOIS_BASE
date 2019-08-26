/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_max.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caellis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 15:57:03 by caellis           #+#    #+#             */
/*   Updated: 2019/08/26 15:57:32 by caellis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
# include <unistd.h>
# include <stdlib.h>

int	max(int *tab, unsigned int len)
{
	int	max = 0;
	
	if (len && tab)
	{
		while (len--)
		{
			max = *tab > max ? *tab : max;
			tab++;
		}
	}
	return (max);
}

int	main(void)
{
	int	tab[3] = {0, 49, 50};
	char	out = (char)max(tab, 3);

	write(1, &out, 1);	//Should output: 2
	return (0);
}
