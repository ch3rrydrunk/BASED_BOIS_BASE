/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ch3rryhq <ch3rryhq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 23:03:34 by ch3rryhq          #+#    #+#             */
/*   Updated: 2020/03/12 23:51:18 by ch3rryhq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int				is_in(char c, const char *s)
{
	while (*s)
	{
		if (*s == c)
			return (1);
		s++;
	}
	return (0);
}

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

int32_t			split_input(char const *input, char ***out)
{
	size_t		w_c;
	long		rb;
	size_t		i;
    
	*out = NULL;
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
