/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caellis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 18:50:44 by caellis           #+#    #+#             */
/*   Updated: 2019/04/02 19:01:24 by caellis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_factorial(int nb)
{
	if (nb <= 0 || nb > 12)
	{
		if (nb == 0)
			return (1);
		else
			return (0);
	}
	if (nb > 0)
	{
		return (nb * ft_recursive_factorial(nb - 1));
	}
	else
		return (1);
}
