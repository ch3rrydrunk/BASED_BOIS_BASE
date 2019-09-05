/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caellis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 18:50:29 by caellis           #+#    #+#             */
/*   Updated: 2019/09/05 13:19:03 by caellis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"
#include <stdio.h>
#include <stdlib.h>

/*
typedef	struct		s_list
{
	int		data;
	struct s_list	*next;
}			t_list;
*/

int ascending(int a, int b)
{
	return (a <= b);
}

int descending(int a, int b)
{
	return (a >= b);
}

void	ft_swap(t_list *a, t_list *b)
{
	t_list	*c;

	c = a;
	a = b;
	b = c;
}

t_list	*sort_list(t_list *lst, int (*cmp)(int, int))
{
	t_list	*cue = lst;
	t_list	*buff;
	
	if (lst)
	{
		while (cue)
		{
			buff = lst->next;
			while (buff)
			{
				if (!cmp(cue->data, buff->data))
					ft_swap(cue, buff);
				buff = buff->next;
			}
			cue = cue->next;
		}
		
	}
	return (lst);
}

int	main(void)
{
	t_list	*test = (t_list *)malloc(sizeof(t_list));
	t_list	*tmp = test;
	t_list	*cue = NULL;
	int		i = 0;

	// Prepare a list with 0-9 digits than sort descending
	test->data = i++;
	while (i < 10)
	{
		if (!cue)
		{
			cue = (t_list *)malloc(sizeof(t_list));
			cue->data = i++;
			cue->next = NULL;
		}
		tmp->next = cue;
		tmp = tmp->next;
		cue = cue->next;
	}
	test = sort_list(test, descending);
	while (test)
	{
		printf("%i\n", test->data);
		test = test->next;
	}
	return (0);
}
