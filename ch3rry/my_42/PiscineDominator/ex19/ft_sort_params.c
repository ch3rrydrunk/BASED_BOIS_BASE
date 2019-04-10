/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caellis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 13:19:18 by caellis           #+#    #+#             */
/*   Updated: 2019/04/04 13:16:22 by caellis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

void	ft_putstr(char *str)
{
	char	*p_str;

	p_str = str;
	while (*p_str)
	{
		ft_putchar(*p_str);
		p_str++;
	}
}

int		ft_strcmp(char *s1, char *s2)
{
	char	*p_s1;
	char	*p_s2;

	p_s1 = s1;
	p_s2 = s2;
	while (*p_s1 && *p_s1 == *p_s2)
	{
		p_s1++;
		p_s2++;
	}
	return (*p_s1 - *p_s2);
}

void	ft_sort_params(int ac, char **av)
{
	int		a;
	int		b;
	char	*buff;

	a = 1;
	while (a < ac)
	{
		b = a + 1;
		while (b < ac)
		{
			if (ft_strcmp(av[a], av[b]) > 0)
			{
				buff = av[a];
				av[a] = av[b];
				av[b] = buff;
			}
			b++;
		}
		a++;
	}
}

int		main(int argc, char **argv)
{
	int		p;

	if (!(argc < 2))
	{
		ft_sort_params(argc, argv);
		p = 1;
		while (p < argc)
		{
			ft_putstr(argv[p]);
			ft_putstr("\n");
			p++;
		}
	}
	return (0);
}
