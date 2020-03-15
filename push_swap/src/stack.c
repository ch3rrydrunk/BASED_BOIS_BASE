/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caellis <caellis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 23:03:23 by ch3rryhq          #+#    #+#             */
/*   Updated: 2020/03/15 16:05:39 by caellis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack	*new_stack(int n)
{
	t_stack *s;

	s = (t_stack *)malloc(sizeof(t_stack));
	s->n = n;
	s->index = 0;
	s->next = NULL;
	s->prev = NULL;
	return (s);
}

void			free_stack(t_stack *s, int32_t size)
{
	while (size--)
	{
		s = s->next;
		free(s->prev);
	}
	free(s);
}

t_stack			*make_stack(int *tab, int32_t size, char tag)
{
	t_stack *stack;
	t_stack *top;

	stack = new_stack(*tab++);
	top = stack;
	stack->tag = tag;
	while (size--)
	{
		stack->next = new_stack(*tab++);
		stack->next->prev = stack;
		stack->next->tag = tag;
		stack = stack->next;
	}
	stack->next = top;
	top->prev = stack;
	return (top);
}

void			stack_util(t_stack *stack, int32_t *tab, int32_t size, char mode)
{
	int32_t i;

	i = 1;
    if (mode & PS_INDEX)
    {
        if (mode & PS_VERBOSE)
            ft_printf("+++INITIATING INDEXATION+++\n");
	    while (size--)
	    {
		    while (stack->n != *tab)
			    stack = stack->next;
            if ((mode & PS_VERBOSE) && !(mode & PS_PRINT))
                ft_printf("stack num: {%d}; index: [%d];\n", *tab, i);
		    stack->index = i++;
		    tab++;
	    }
    }
    if (mode & PS_PRINT)
    {
        while (size--)
        {
            ft_printf("stack num: {%d}; index: [%d];\n", stack->n, stack->index);
            stack = stack->next;
        }
    }
}
