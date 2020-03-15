/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caellis <caellis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/15 15:49:07 by caellis           #+#    #+#             */
/*   Updated: 2020/03/15 16:11:24 by caellis          ###   ########.fr       */
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

int		char_at(const char *s, char c)
{
	int		i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

void    parse_options(char *options, int32_t *flags)
{
    int		i;
	int		at;

	if (options[0] == '-' && options[1] == '-')
	{
		if (ft_strcmp(options, "--help") == 0)
			display_help();
		else if (ft_strcmp(options, "--") == 0)
			return ;
		unrecognized_option(options, ft_strlen(options));
	}
	i = 1;
	while (options[i])
	{
		if ((at = char_at(PS_FLAGS, options[i])) < 0)
			unrecognized_option(options, 1);
		*flags |= (1u << at);
		i++;
	}
	return ;
}