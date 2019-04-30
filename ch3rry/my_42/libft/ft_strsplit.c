/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caellis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/28 14:37:51 by caellis           #+#    #+#             */
/*   Updated: 2019/04/30 21:03:31 by caellis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

static int		ft_populate(char ***arr, const char *s,
							char c, size_t pos, int max)
{
	size_t	rb;
	size_t	w_l;

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
		{
			ft_freearray(arr, max);
			return (-1);
		}
	return (rb + w_l);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**split;
	size_t		w_c;
	size_t		rb;
	size_t		i;

	split = NULL;
	if (s && c)
	{
		w_c = ft_countwords(s, c);
		if ((split = (char **)malloc(sizeof(char*) * (w_c + 1))))
		{
			i = 0;
			while (i < w_c)
			{
				if ((rb = ft_populate(&split, s, c, i, w_c)) < 0)
					break;
				s += rb;
				i++;
			}
			split[w_c] = NULL;
		}
	}
	return (split);
}