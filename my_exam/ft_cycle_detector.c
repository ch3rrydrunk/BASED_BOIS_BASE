/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cycle_detector.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caellis <caellis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 14:37:47 by caellis           #+#    #+#             */
/*   Updated: 2019/09/11 15:03:39 by caellis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"
#include <stdlib.h>
#include <stdio.h>

int        cycle_detector(const t_list *list)
{
	t_list	*check = list;

	while (list && check)
	{
		list = list->next;
		check = check->next->next;
		if (list == check)
			return (1);
	}
	return (0);
}

int		main(void)
{
	t_list a, b, c;

	a.next = &b, b.next = &c, c.next = &a;
	if (cycle_detector(&a))
		printf("OK\n");
	else
		printf("NOK\n");
	return (0);
}