/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caellis <caellis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/08 14:56:14 by caellis           #+#    #+#             */
/*   Updated: 2020/03/15 18:04:26 by caellis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// static void     validate_commands(int32_t fd, t_stack *cmd, int32_t size)
// {
//     int32_t     rb;
//     char      com_s[BUFF_SIZE];
    
//     while ((rb = get_next_line(fd, &com_s))
//     {
//         if (rb < 0 || rb > 4)
//         {
//             free_stack(cmd, size);
//             error(ERR_BASIC);
//         }
//     }
// }

static int     parse(char **av, int32_t *flags, int32_t *tab, t_stack *stack)
{
    int32_t     i;
    int32_t     ac;
    int         fd;

    ac = *tab;
    ft_bzero(tab, STACK_SIZE);
    fd = STDIN_FILENO;
    i = 1;
    while (i < ac && av[i][0] == '-')
    {
        parse_options(av[i++], flags);
        if (*flags & PS_FILE)
            fd = open(av[i++], O_RDONLY);
    }
    ac -= (i - 1);
    validate_input(ac, &av[i], tab);
    // load_input(stack, tab);
    return (fd);
}

int             main(int ac, char **av)
{
    t_stack     *stackA;
    t_stack     *cmd;
    int32_t     tab[STACK_SIZE + 1];
    int32_t     flags;
    int32_t     i;
    int         fd;

    i = 1;
    if (--ac > 0)
    {
        *tab = ac;
        fd = parse(av, &flags, tab, stackA);
        // validate_commands(fd, cmd, ac);
        i=1;
        while (tab[0]--)
            ft_printf("%d\n", tab[i++]);
        // check_commands(stackA, tab);
        //close fd, clean stack;
    }
    return (0);
}