/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ch3rryhq <ch3rryhq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 18:31:50 by ch3rryhq          #+#    #+#             */
/*   Updated: 2020/03/15 21:49:38 by ch3rryhq         ###   ########.fr       */
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
# include <time.h>
# include <pwd.h>
# include <grp.h>
# include <dirent.h>
# include <limits.h>
# include <uuid/uuid.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/acl.h>
# include <sys/xattr.h>
# include <sys/ioctl.h>
# include <fcntl.h>

# include "libft.h"
# include "ft_printf.h"

# define STACK_SIZE 1024
# define MAX_LINE 90

# define STACK_A 'A'
# define STACK_B 'B'
# define SIZE 0
# define BOTTOM 1
# define SPACE ' '
# define REVROTATE 0
# define ROTATE 1

# define PS_STATUSOK 0
# define PS_STATUSNOK -1

# define PS_FLAGS   "fvpirR"
# define PS_CMDFILE    (1u << 0u)
# define PS_VERBOSE (1u << 1u)
# define PS_PRINT (1u << 2u)
# define PS_INDEX (1u << 3u)
# define PS_ROT (1u << 4u)
# define PS_REVROT (1u << 5u)


# define ERR_BASIC "Error"
# define ERR_OVERFLOW "Error: Stack overflow"
# define ERR_BADCOMMAND "Error: Incorrect command received"
# define ERR_BADINPUT "Error: Incorrect input"

typedef struct		s_stack
{
	int32_t			n;
	int32_t			index;
    char            tag;
    // char            com[4];
    struct s_stack	*prev;
	struct s_stack	*next;
}					t_stack;

void        parse_options(char *options, int32_t *flags);
int32_t     validate_input(int32_t ac, char **argv, int32_t *tab);
void		load_input(t_stack *stack, int32_t *tab);
int         char_at(const char *s, char c);
int			is_in(char c, const char *s);
void		sort_array(int32_t *begin, int32_t *end);
void        check_duplicates(int32_t *tab);


void        com_swap(t_stack *stack, int32_t *tab, int32_t size, char mode);
void        com_push(t_stack *from, t_stack *to, int32_t *tab, int32_t size, char mode);
void        com_rotate(t_stack **stack, int32_t *tab, int32_t size, char mode);

t_stack     *make_stack(int *tab, int32_t size, char tag);
void        free_stack(t_stack *s, int32_t size);
void	    stack_util(t_stack *stack, int32_t *tab, int32_t size, char mode);

void        error(const char *msg);
int		    display_help(void);
int		    unrecognized_option(char *option, size_t len);

#endif
