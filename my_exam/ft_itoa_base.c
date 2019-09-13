/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 12:02:03 by exam              #+#    #+#             */
/*   Updated: 2019/09/07 13:27:40 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	ft_strrev(char *str, int len)
{
	int		i = 0;
	char 	a;

	if (len >= 1)
	{
		while (i <= len / 2)
		{
			a = str[i];
			str[i] = str[len - i];
			str[len - i] = a;
			i++;
		}
	}
}

char	*ft_itoa_base(int value, int base)
{
	char		is_neg_dec = 0;
	char		*res = NULL;
	char 		*cue;
	long long	val = value;

	if (base >= 2 && base <= 16 && (cue = (char *)malloc(sizeof(char) * 32)))
	{
		res = cue;
		is_neg_dec = ((val < 0) && (base == 10)) ? 1 : 0;
		if (val)
		{
			val = val < 0 ? -val : val;
			while (val)
			{
				*cue++ = val % base > 9 ? (val % base) + '7' : (val % base) + '0';
				val /= base;
			}
		}
		else
			*cue++ = '0';
		if (is_neg_dec)
			*cue++ = '-';
		*cue = '\0';
		ft_strrev(res, (int)(cue - res - 1));
	}
	return (res);
}

