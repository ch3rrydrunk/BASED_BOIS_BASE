/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caellis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 14:26:59 by caellis           #+#    #+#             */
/*   Updated: 2019/04/04 19:29:56 by caellis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

# define S_TEST "H3IL CH3RRY"
# define LEN_ST 12
# define OK "_____GOOD__BOI_____\n"
# define NOK "XXX__BAD_DOGE__XXX\n"

static void	checker(char *s1, char *s2)
{
	if (strcmp(s1, s2))
		printf(" ...\t...\t...\n"NOK" ...\t...\t...\n");
	else
		printf(" ...\t...\t...\n"OK" ...\t...\t...\n");
}

int			main(void)
{
	char	str1[LEN_ST] = S_TEST;
	char	str2[LEN_ST] = S_TEST;

	printf("Hello, Master!\nHere are your tests..\n");
	printf("Please, enjoy\n");
	printf(" ...\t...\t...\n");
	printf(" .. %s  ..\n", S_TEST);
	printf(" ...\t...\t...\n");

	printf("\n ...GO FT_MEMSET...\n");	//FT_MEMSET
	printf("memset() out:\n%s\n", memset(str1, 33, 4));
	printf("ft_memset() out:\n%s\n", ft_memset(str2, 33, 4));
	checker(str1, str2);

	return (0);
}
