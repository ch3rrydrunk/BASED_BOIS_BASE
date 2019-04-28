/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caellis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/28 03:16:06 by caellis           #+#    #+#             */
/*   Updated: 2019/04/28 04:18:32 by caellis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*trim;
	int		cue;

	trim = NULL;
	if (s)
	{
		while (ft_isspace(*s))
			s++;
		cue = ft_strlen(s) - 1;
		while (cue > -1 && ft_isspace(s[cue]))
			cue--;
		cue++;
		if ((trim = ft_strnew(cue)))
			ft_strncpy(trim, s, cue);
	}
	return (trim);
}

int main()
{
	char *s1 = "  \t \t \n   \n\n\n\t";
	char *s2 = "";
	char *ret = ft_strtrim(s1);
	int result = 0;

	if (!strcmp(ret, s2))
		result = 1;
	return (0);
}