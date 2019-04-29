/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caellis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/28 03:16:06 by caellis           #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2019/04/28 04:20:56 by caellis          ###   ########.fr       */
=======
/*   Updated: 2019/04/29 15:52:08 by caellis          ###   ########.fr       */
>>>>>>> ac620fd3c3ac5f549a8b8887112b48b359247dec
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
<<<<<<< HEAD
}
=======
}
>>>>>>> ac620fd3c3ac5f549a8b8887112b48b359247dec
