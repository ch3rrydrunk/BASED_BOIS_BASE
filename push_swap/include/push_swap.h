/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caellis <caellis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 18:31:50 by ch3rryhq          #+#    #+#             */
/*   Updated: 2020/03/08 17:09:05 by caellis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdarg.h>
# include <stdlib.h>
# include <errno.h>
# include <stdio.h>
# include <unistd.h>
# include <stdint.h>
# include <float.h>

# include "libft.h"
# include "ft_printf.h"

# define STACK_SIZE 1024
# define MAX_LINE 90

# define STACK_A 0
# define STACK_B 1
# define SIZE 0
# define BOTTOM 1
# define REVROTATE 0
# define ROTATE 1

# define ERR_OVERFLOW "Error: Stack overflow\n"
# define ERR_BADCOMMAND "Error: Incorrect command received\n"
# define ERR_BADINPUT "Error: Incorrect input\n"

int     st_push(int stack[], int val);
int     *st_pop(int stack[]);


void     com_swap(int stack[]);
void     com_push(int from[], int to[]);
void     com_rotate(int stack[], int order);

#endif
