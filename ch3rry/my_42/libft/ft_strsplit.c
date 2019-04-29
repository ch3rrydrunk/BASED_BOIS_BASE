/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caellis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/28 14:37:51 by caellis           #+#    #+#             */
/*   Updated: 2019/04/29 16:31:15 by caellis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_words(const char *s, char c)
{
	int		w_c;
	int		cue;
	
	cue = -1;
	w_c = 0;
	while (*s)
	{
		if (ft_memcmp(s, &c, 1))
		{
			if (cue == c)
				w_c++;
		}
		cue = *s++;
	}
	return (w_c);
}

char	**ft_strsplit(char const *s, char c)
{
	char	**split;
	int		cue;
	int		w_c;
	int		w_l;

	split = NULL;
	cue = -1;
	w_c = 0;
	if (s && c)
	{
		if ((split = (char **)malloc(sizeof(s) * (ft_count_words(s, c) + 1))))
		{
			while (*s)
			{
				w_l = 0;
				while (ft_memcmp(s, &c, 1))
				{
					if (cue == c)
						w_c++;
					w_l++;
					s++;
				}
				if (w_l && w_c)
				{
					split[w_c - 1] = ft_strncpy(ft_strnew(w_l), (s - w_l), w_l);
					w_l = 0;				
				}
				cue = *s++;
			}
		}
	}
	return (split);
}
