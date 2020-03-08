/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caellis <caellis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/08 15:49:03 by caellis           #+#    #+#             */
/*   Updated: 2020/03/08 18:26:48 by caellis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void     com_swap(int stack[])
{
    if (stack[SIZE] > 2 && stack[stack[SIZE]] != stack[BOTTOM])
    {
        stack[BOTTOM] ^= stack[stack[SIZE]];
        stack[stack[SIZE]] ^= stack[BOTTOM];
        stack[BOTTOM] ^= stack[stack[SIZE]];
    }
}

void       com_push(int from[], int to[])
{
    int     *buff;

    if (from[SIZE] > 0)
    {
        buff = st_pop(from);
        if (!st_push(to, *buff))
        {
            ft_fprintf(STDERR_FILENO, ERR_OVERFLOW);
            exit(1);
        }
    }
}

// void        com_rotate(int stack[], int order)
// {
//     int     buff;
//     int     i;
//     int     j;

//     i = BOTTOM;
//     j = stack[SIZE];
    
// }