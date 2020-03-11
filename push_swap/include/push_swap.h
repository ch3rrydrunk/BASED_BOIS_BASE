/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ch3rryhq <ch3rryhq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 18:31:50 by ch3rryhq          #+#    #+#             */
/*   Updated: 2020/03/11 22:06:58 by ch3rryhq         ###   ########.fr       */
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

# define PSM_VERBOSE (1u << 0u)
# define PSM_PRINT (1u << 1u)
# define PSM_INDEX (1u << 2u)

# define ERR_OVERFLOW "Error: Stack overflow\n"
# define ERR_BADCOMMAND "Error: Incorrect command received\n"
# define ERR_BADINPUT "Error: Incorrect input\n"

typedef struct		s_stack
{
	int32_t			n;
	int32_t			index;
    int8_t          tag;
    struct s_list	*prev;
	struct s_list	*next;
}					t_stack;

int     st_push(int stack[], int val);
int     *st_pop(int stack[]);


void    com_swap(int stack[]);
void    com_push(int from[], int to[]);
void    com_rotate(int stack[], int order);

t_stack *make_stack(int *tab, int32_t size, int8_t tag);
void    free_stack(t_stack *s, int32_t size);
void	stack_util(t_stack *stack, int32_t *tab, int32_t size, int8_t mode);

#endif
