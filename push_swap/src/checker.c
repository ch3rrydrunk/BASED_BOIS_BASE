/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ch3rryhq <ch3rryhq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 18:24:35 by ch3rryhq          #+#    #+#             */
/*   Updated: 2020/01/27 16:00:20 by ch3rryhq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

/*
* Pop int from stack, if stack is empty - return NULL
*/
int     *st_pop(int stack[])
{
    if (stack[0])
    {
        stack[0] -= 1;
        return(&stack[stack[0] + 1]);
    }
    return(NULL);
}

/*
* Push int on stack, if stack is full - return 1
*/
int     st_push(int stack[], int val)
{
    if (stack[0] + 1 < STACK_SIZE)
    {
        stack[0] += 1;
        stack[stack[0]] = val;
        return(0);
    }
    return(1);
}

int     main(int ac, char **av)
{
    int stack[STACK_SIZE]; // stack[0] => stack pointer
    
    ft_memset((void *)stack, '\0', STACK_SIZE);
    if (ac == 1)
        return(1);
    while (ac-- > 1)
        st_push(stack, ft_atoi(av[ac]));
    while (stack[0])
        ft_printf("%d\n", *st_pop(stack));
    return(0);
}