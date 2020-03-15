/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_validation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caellis <caellis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/15 15:58:37 by caellis           #+#    #+#             */
/*   Updated: 2020/03/15 18:06:40 by caellis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void			load_input(t_stack *stack, int32_t *tab)
// {
// 	int32_t size;

// 	stack = make_stack(tab + 1, *tab, STACK_A);
// // 	size = *tab++;
	
// }

static size_t	ft_wordlen(char const *s, char c)
{
	size_t len;

	len = 0;
	while (*s == c)
		s++;
	while (*s != c && *s)
	{
		len++;
		s++;
	}
	return (len);
}

static int		ft_populate(char ***arr, const char *s, char c, size_t pos)
{
	long	rb;
	long	w_l;

	rb = 0;
	while (*s == c && *s)
	{
		rb++;
		s++;
	}
	w_l = ft_wordlen(s, c);
	if (((*arr)[pos] = ft_strnew(w_l)))
		ft_strncpy((*arr)[pos], s, w_l);
	else
		return (-1);
	return (rb + w_l);
}

static int32_t	split_input(char const *input, char ***out)
{
	size_t		w_c;
	long		rb;
	size_t		i;
    
	w_c = 0;
	if (input)
	{
		w_c = ft_countwords((char *)input, SPACE);
		if ((*out = (char **)ft_memalloc(sizeof(char*) * (w_c + 1))))
		{
			i = 0;
			while (i < w_c)
			{
				if ((rb = ft_populate(out, input, SPACE, i)) < 0)
				{
					ft_freearray(out, w_c);
					break ;
				}
				input += rb;
				i++;
			}
		}
	}
	return (w_c);
}

int32_t     	validate_input(int32_t ac, char **argv, int32_t *tab)
{
    int32_t     *size;
    char        **buff;
    int32_t     n;

    size = tab;
    tab++;
    while (ac--)
    {
        if ((n = split_input(*argv++, &buff)) < 0)
            error(ERR_BASIC);
        else 
        {
            while (n--)
            {
                *tab = ft_atoi(*buff);
                if (ft_strcmp(ft_itoa(*tab), *buff))
                    error(ERR_BASIC);
                else
                    (*size)++;
                tab++;
                buff++;
            }
        }
    }
    return (1);
}