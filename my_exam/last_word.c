/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_word.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 12:04:24 by exam              #+#    #+#             */
/*   Updated: 2019/08/28 12:34:53 by caellis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*ft_strrev(char *str, int len)
{
	char 	a;
	int		i = 0;

	while (i < len / 2)
	{
		a = str[i];
		str[i] = str[len - i];
		str[len - i] = a;
		i++;
	}
	return (str);
}

int		ft_strlen(char *str)
{
	int	i = 0;

	while (*str)
	{
		i++;
		str++;
	}
	return (i);
}

int		main(int ac, char** av)
{
	char	last_word[5000] = {0};
	int		i;
	int		j = 0;

	if (ac == 2)
	{
		i = ft_strlen(av[1]);
		while (i > 0)
		{
			if (av[1][i] == ' ' || av[1][i] == '\t' || av[1][i] == '\v')
				i--;
			else
			{
				while (i >= 0 && av[1][i] != ' ' && av[1][i] != '\t' && av[1][i] != '\v')
				{
					last_word[j++] = av[1][i--];
				}
				write(0, ft_strrev(last_word, j), 5000);
				return (0);
			}
		}
	}
	write(1, "\n", 1);
	return (0);
}
