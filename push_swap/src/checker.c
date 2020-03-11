/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ch3rryhq <ch3rryhq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/08 14:56:14 by caellis           #+#    #+#             */
/*   Updated: 2020/03/11 22:54:01 by ch3rryhq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error(void)
{
	ft_printf("Error\n");
	exit(-1);
}

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

static void     validate_input(char **args, int32_t **tab, int32_t size)
{
    ft_bzero(*tab, STACK_SIZE);
    while (size--)
    {

    }
}

int             main(int ac, char **av)
{
    t_stack     stackA;
    t_stack     stackB;
    int32_t     tab[STACK_SIZE];
    int8_t      commands[MAX_LINE];
    int32_t     rb;
    int32_t     fd;

    if (ac < 2)
        error();
    validate_input(av, &tab, ac);
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
    stack_util(&stackA, tab, size, PSM_PRINT);
    ft_printf("OK\n");
    return(0);
}