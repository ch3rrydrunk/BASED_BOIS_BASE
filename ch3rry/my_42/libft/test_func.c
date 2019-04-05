/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caellis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 14:26:59 by caellis           #+#    #+#             */
/*   Updated: 2019/04/05 13:44:08 by caellis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

# define S_TEST "H3IL CH3RRY"
# define LEN_ST 12
# define OK "_____GOOD__BOI_____\n"
# define NOK "XXX__BAD_DOGE__XXX\n"

static char	*ft_strcpy(char *dest, char *src)
{
	int i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

static void	checker(char *s1, char *s2)
{
	if (strcmp(s1, s2))
		printf(" ...\t...\t...\n"NOK" ...\t...\t...\n");
	else
		printf(" ...\t...\t...\n"OK" ...\t...\t...\n\n");
}

int			main(void)
{
	char	str1[LEN_ST] = S_TEST;
	char	str2[LEN_ST] = S_TEST;

	printf("\nHi, Master!\nHere are your tests..\n");
	printf("Please, enjoy\n\n");
	printf(" ...\t...\t...\n");
	printf(" .. %s  ..\n", S_TEST);
	printf(" ...\t...\t...\n\n");

	printf("\n ...GO FT_MEMSET...\n");	//FT_MEMSET
	printf("memset() out:\n%s\n", memset(str1, 33, 4));
	printf("ft_memset() out:\n%s\n", ft_memset(str2, 33, 4));
	checker(str1, str2);
	ft_strcpy(str1, S_TEST); ft_strcpy(str2, S_TEST);

	printf("\n ...GO FT_BZERO...\n");	//FT_BZERO
	bzero(str1, 4); ft_bzero(str2, 4);
	printf("bzero() out:\n%s\n", str1);
	printf("ft_bzero() out:\n%s\n", str2);
	checker(str1, str2);
	ft_strcpy(str1, S_TEST); ft_strcpy(str2, S_TEST);

	return (0);
}
