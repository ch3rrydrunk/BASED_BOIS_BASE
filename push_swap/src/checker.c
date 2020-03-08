/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caellis <caellis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/08 14:56:14 by caellis           #+#    #+#             */
/*   Updated: 2020/03/08 19:52:16 by caellis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
* Pop int from stack, if stack is empty - return NULL
*/
int     *st_pop(int stack[])
{
    if (stack[SIZE])
    {
        stack[SIZE] -= 1;
        return(&stack[stack[SIZE] + 1]);
    }
    return(NULL);
}

/*
* Push int on stack, if stack is full - return 1
*/
int     st_push(int stack[], int val)
{
    if (stack[SIZE] + 1 < STACK_SIZE)
    {
        stack[SIZE] += 1;
        stack[stack[SIZE]] = val;
        return(1);
    }
    return(0);
}

int     main(int ac, char **av)
{
    int     stackA[STACK_SIZE]; // stack[0] => stack pointer
    int     stackB[STACK_SIZE]; // stack[0] => stack pointer
    char    commands[MAX_LINE];
    int     rb;
    int     fd;

    ft_memset((void *)stackA, '\0', STACK_SIZE);
    ft_memset((void *)stackB, '\0', STACK_SIZE);
    if (ac == 1)
        return(1);
    while (ac-- > 1)
        st_push(stackA, ft_atoi(av[ac]));     // ATTENTION NO CHECK FOR BAD INPUT!
    fd = open("test_input.txt", O_RDONLY);
    while ((rb = read(fd, commands, 4)) > 1)
    {
        if (rb > 4)
        {
            ft_fprintf(STDERR_FILENO, ERR_BADCOMMAND);
            return(1);
        }
        commands[rb - 1] = '\0';
    }
    // com_rotate(stackA, ROTATE);
    // com_rotate(stackA, REVROTATE);
    print_stack(stackA);
    ft_printf("OK\n");
    return(0);
}