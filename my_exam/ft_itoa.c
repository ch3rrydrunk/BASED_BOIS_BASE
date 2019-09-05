/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caellis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 18:30:29 by caellis           #+#    #+#             */
/*   Updated: 2019/09/05 21:20:02 by caellis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

void	ft_strrev(char *str, int len)
{
	int	i = 0;
	char	a;

	if (len-- > 1)
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

char	*itoa(int nb)
{
	char	*str = NULL;
	char	*cue;
	char	is_neg = nb < 0 ? 1 : 0;
	int	len = 0;

	if ((str = (char *)malloc(sizeof(char) * 12)))
	{
		cue = str;
		if (nb == -2147483648)
			return (str = "-2147483648");
		else if (nb)
		{
			nb = is_neg ? -nb : nb;
			while (nb)
			{
				*cue++ = (nb % 10) + 48U;
				nb /= 10;
				len++;
			}
			if (is_neg && len++)
				*cue++ = '-';
		}
		else if ((++len))
			*cue++ = 48U;
		*cue = '\0';
		ft_strrev(str, len);
	}
	return (str);
}

int	main(void)
{
	printf("14 is %s\n10 is %s\n-11 is %s\n0 is %s\n-2147483648 is %s\n", itoa(14), itoa(10), itoa(-11), itoa(0), itoa(-2147483648));
	return(0);
}
