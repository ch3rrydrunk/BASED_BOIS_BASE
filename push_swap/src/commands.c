/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ch3rryhq <ch3rryhq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/08 15:49:03 by caellis           #+#    #+#             */
/*   Updated: 2020/03/12 10:33:54 by ch3rryhq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void        com_rotate(t_stack **stack, int32_t *tab, int32_t size, int8_t mode)
{
    if (mode & PSM_ROT)
        *stack = (*stack)->next;
    else if (mode & PSM_REVROT)
        *stack = (*stack)->prev;
}

void     com_swap(t_stack *stack, int32_t *tab, int32_t size, int8_t mode)
{
    
    // if (stack[SIZE] > 2 && stack[stack[SIZE]] != stack[BOTTOM])
    // {
    //     stack[BOTTOM] ^= stack[stack[SIZE]];
    //     stack[stack[SIZE]] ^= stack[BOTTOM];
    //     stack[BOTTOM] ^= stack[stack[SIZE]];
    // }
}

void       com_push(t_stack *from, t_stack *to, int32_t *tab, int32_t size, int8_t mode)
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

