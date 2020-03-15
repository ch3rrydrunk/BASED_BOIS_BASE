/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caellis <caellis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/08 15:49:03 by caellis           #+#    #+#             */
/*   Updated: 2020/03/15 15:44:32 by caellis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void        com_rotate(t_stack **stack, int32_t *tab, int32_t size, char mode)
{
    if (mode & PS_ROT)
        *stack = (*stack)->next;
    else if (mode & PS_REVROT)
        *stack = (*stack)->prev;
}

void     com_swap(t_stack *stack, int32_t *tab, int32_t size, char mode)
{
    
    // if (stack[SIZE] > 2 && stack[stack[SIZE]] != stack[BOTTOM])
    // {
    //     stack[BOTTOM] ^= stack[stack[SIZE]];
    //     stack[stack[SIZE]] ^= stack[BOTTOM];
    //     stack[BOTTOM] ^= stack[stack[SIZE]];
    // }
}

void       com_push(t_stack *from, t_stack *to, int32_t *tab, int32_t size, char mode)
{
    
    // int     *buff;

    // if (from[SIZE] > 0)
    // {
    //     buff = st_pop(from);
    //     if (!st_push(to, *buff))
    //     {
    //         ft_fprintf(STDERR_FILENO, ERR_OVERFLOW);
    //         exit(1);
    //     }
    // }
}

