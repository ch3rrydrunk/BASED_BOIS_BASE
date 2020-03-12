/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ch3rryhq <ch3rryhq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 18:31:50 by ch3rryhq          #+#    #+#             */
/*   Updated: 2020/03/12 23:53:22 by ch3rryhq         ###   ########.fr       */
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
# define SPACE ' '

# define PSM_VERBOSE (1u << 0u)
# define PSM_PRINT (1u << 1u)
# define PSM_INDEX (1u << 2u)
# define PSM_ROT (1u << 3u)
# define PSM_REVROT (1u << 4u)
# define PSM_FROMFILE (1u << 5u)

# define ERR_BASIC (const char *)"Error\n"
# define ERR_OVERFLOW "Error: Stack overflow\n"
# define ERR_BADCOMMAND "Error: Incorrect command received\n"
# define ERR_BADINPUT "Error: Incorrect input\n"

typedef struct		s_stack
{
	int32_t			n;
	int32_t			index;
    char            tag;
    // char            com[4];
    struct s_stack	*prev;
	struct s_stack	*next;
}					t_stack;


void    com_swap(t_stack *stack, int32_t *tab, int32_t size, char mode);
void    com_push(t_stack *from, t_stack *to, int32_t *tab, int32_t size, char mode);
void    com_rotate(t_stack **stack, int32_t *tab, int32_t size, char mode);

t_stack *make_stack(int *tab, int32_t size, char tag);
void    free_stack(t_stack *s, int32_t size);
void	stack_util(t_stack *stack, int32_t *tab, int32_t size, char mode);

int32_t			split_input(char const *input, char ***out);
int				is_in(char c, const char *s);
#endif
