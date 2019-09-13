/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cycle_detector.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 14:33:20 by exam              #+#    #+#             */
/*   Updated: 2019/09/12 14:37:12 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

int		cycle_detector(const t_list *list)
{
	t_list		*check = list;
	int			i = 10000;

	while ((list && check))
	{
		if (list == check || i < 0)
			return (1);
		list = list->next;
		check = check->next->next;
		i--;
	}
	return (0);
}
