/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caellis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 20:42:28 by caellis           #+#    #+#             */
/*   Updated: 2019/04/02 21:05:35 by caellis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

void	ft_print_params(int ac, char **av)
{
	int	p;

	p = 1;
	while (p < ac)
	{
		ft_putstr(av[p]);
		ft_putstr("\n");
		p++;
	}
}

int		main(int argc, char **argv)
{
	if (!(argc < 2))
	{
		ft_print_params(argc, argv);
	}
	return (0);
}
