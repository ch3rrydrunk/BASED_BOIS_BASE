/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caellis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 16:27:02 by caellis           #+#    #+#             */
/*   Updated: 2019/05/03 16:58:00 by caellis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd(t_list **alst, t_list *new)
{
	t_list	*buff;

	if ((!*alst) && new)
		*alst = new;
	else if (alst && *alst && new)
	{
		buff = *alst;
		*alst = new;
		(*alst)->next = buff;
	}
}