/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ch3rryhq <ch3rryhq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/08 14:56:14 by caellis           #+#    #+#             */
/*   Updated: 2020/03/14 12:47:16 by ch3rryhq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error(const char *msg)
{
	ft_fprintf(STDERR_FILENO, "%s\n", msg);
	exit(-1);
}

// void    parse_options(int32_t *ac, char ***av, char *mode)
// {
// if (*argv == '-')
//     {
//         parse_options(*argv, mode) && ac--;
//         if (mode & PSM_FROMFILE)
//             fd = open(filename, O_RDONLY);
//     }
// }

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

static int32_t     validate_input(int32_t ac, char **argv, int32_t *tab)
{
    int32_t     *size;
    char        **buff;
    char        *tmp;
    int32_t     n;
    int32_t     digits;

    size = tab;        // tab[0] holds size lika a cool stack :)
    tab++;              // Shift tab 1 up to keep size in tab[0]
    while (ac--)
    {
        if ((n = split_input(*argv++, &buff)) < 0)
            error(ERR_BASIC);
        else 
        {
            while (n--)
            {
                tmp = (*buff);
                *tab = ft_atoi(*buff);
                digits = count_digits(*tab);
                buff += digits;
                if (ft_strncmp(ft_itoa(*tab), tmp, digits))
                {
                    free(*buff);
                    error(ERR_BASIC);
                }
                else
                    (*size)++;
                tab++;
            }
        }
    }
    return(0);
}

int             main(int ac, char **av)
{
    t_stack     stackA;
    t_stack     stackB;
    t_stack     cmd;
    int32_t     tab[STACK_SIZE + 1];
    int32_t     filename;
    char      mode;
    int32_t     fd;

    if (--ac > 0)
    {
        // parse_options(&ac, &av, &mode)
        ft_bzero(tab, STACK_SIZE);
        fd = validate_input(ac, ++av, tab);
        while (tab[0]--)
        {
            ft_printf("%d\n", tab[++fd]);
        }
        exit(0);
        // validate_commands(STDIN_FILENO, cmd, ac);
    }
    return(0);
}