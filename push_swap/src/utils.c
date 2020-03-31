/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ch3rryhq <ch3rryhq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/15 15:58:20 by caellis           #+#    #+#             */
/*   Updated: 2020/03/15 21:23:22 by ch3rryhq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* 
* Increments tab's size and throws error on duplicates.
*/
void    update_tab(int32_t *tab)
{
    int32_t size;
    int32_t check;

	(*tab)++;
	size = *tab;
    check = tab[size--];
    while (size--)
    {
        if (check == *tab)
            error(ERROR);
        check = *tab++;
    }
}

void	error(const char *msg)
{
	ft_fprintf(STDERR_FILENO, "%s\n", msg);
	exit(-1);
}

int		display_help(void)
{
	ft_printf(
	"Usage: ./checker [OPTION] ... [List of numbers] < [List of Commands]"
	"Give a list of integers as arguments. Then feed commands on STDIN.\n"
	"  -f *file_name*	read commands from file_name;\n"
	"  -v				give verbose output;\n"
	"+++ UNDOCUMENTED +++\n"
	"+++ # define PS_PRINT (1u << 2u)\n"
	"+++ # define PS_INDEX (1u << 3u)\n"
	"+++ # define PS_ROT (1u << 4u)\n"
	"+++ # define PS_REVROT (1u << 5u)\n");
	exit(PS_STATUSOK);
}

int		unrecognized_option(char *option, size_t len)
{
	ft_fprintf(STDERR_FILENO,
	"./checker: unrecognized option '%.*s'\n"
	"Try './checker --help' for more information.\n",
	len, option);
	exit(PS_STATUSNOK);
}
