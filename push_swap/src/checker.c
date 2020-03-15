/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caellis <caellis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/08 14:56:14 by caellis           #+#    #+#             */
/*   Updated: 2020/03/15 16:27:06 by caellis          ###   ########.fr       */
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

int             main(int ac, char **av)
{
    t_stack     stackA;
    t_stack     cmd;
    int32_t     tab[STACK_SIZE + 1];
    int32_t     flags;
    int32_t     fd;
    int32_t     i;

    i = 1;
    if (--ac > 0)
    {
        ft_bzero(tab, STACK_SIZE);
        fd = STDIN_FILENO;
        while (i < ac && av[i][0] == '-')
		{
            parse_options(av[i++], &flags);
            // if (flags & PS_FILE)
            //     fd = open(av[i++], O_RDONLY);
        }
        ac -= (i - 1);
        validate_input(ac, &av[i], tab);
        while (tab[0]--)
            ft_printf("%d\n", tab[++fd]);
        // validate_commands(fd, cmd, ac);
        // check_commands(stackA, tab);
    }
    return (0);
}