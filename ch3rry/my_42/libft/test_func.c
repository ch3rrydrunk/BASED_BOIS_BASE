/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caellis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 14:26:59 by caellis           #+#    #+#             */
/*   Updated: 2019/04/05 21:26:16 by caellis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

# define S_TEST "H3IL CH3RRY"
# define LEN_ST 12
# define OK "_____GOOD__BOI_____\n"
# define NOK "XXX__BAD_DOGE__XXX\n"

static int	check_adr_inter(char *s1, char *s2)
{
	while (s1++)
	{
		while(s2++)
		{
			if (s1 == s2)
				return (1);
		}
	}
	return (0);
}

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

static void	checker(char *s1, char *s2, int (*f)(void *, void *))
{
	if (f(s1, s2))
		printf(" ...\t...\t...\n"NOK" ...\t...\t...\n");
	else
		printf(" ...\t...\t...\n"OK" ...\t...\t...\n\n");
}

int			main(void)
{
	char	str1[LEN_ST] = S_TEST;
	char	str2[LEN_ST] = S_TEST;
	//char	*buff;
	int		(*ft_cmp_s)(void *, void *);

	printf("\nHi, Master!\nHere are your tests..\n");
	printf("Please, enjoy\n\n");
	printf(" ...\t...\t...\n");
	printf(" .. %s  ..\n", S_TEST);
	printf(" ...\t...\t...\n\n");

	ft_cmp_s = (int (*)(void *, void *))strcmp;
	printf("\n ...GO FT_MEMSET...\n");	//FT_MEMSET
	printf("memset() out:\n%s\n", memset(str1, 33, 4));
	printf("ft_memset() out:\n%s\n", ft_memset(str2, 33, 4));
	checker(str1, str2, ft_cmp_s);
	ft_strcpy(str1, S_TEST); ft_strcpy(str2, S_TEST); //reset

	printf("\n ...GO FT_BZERO...\n");	//FT_BZERO
	bzero(str1, 4); ft_bzero(str2, 4);
	printf("bzero() out:\n%s\n", str1);
	printf("ft_bzero() out:\n%s\n", str2);
	checker(str1, str2, ft_cmp_s);
	ft_strcpy(str1, S_TEST); ft_strcpy(str2, S_TEST); //reset

	printf("\n ...GO FT_MEMCPY...\n");	//FT_MEMCPY
	ft_memset(str2, 33, 4); //set args
	printf("memcpy() out:\n%s\n", memcpy(str1, str2, LEN_ST - 1));
	ft_strcpy(str1, S_TEST); //set args
	printf("ft_memcpy() out:\n%s\n", ft_memcpy(str1, str2, LEN_ST - 1));
	checker(str1, str2, ft_cmp_s);
	ft_strcpy(str1, S_TEST); ft_strcpy(str2, S_TEST); //reset

	printf("\n ...GO FT_MEMCCPY...\n");	//FT_MEMCCPY
	ft_memset(str2, 33, 4); //set args
	printf("memccpy() opt1(no 'A' met) out:\n%s\n", memccpy(str1, str2, 'A', LEN_ST - 1));
	ft_strcpy(str1, S_TEST); //set args
	printf("ft_memccpy() opt1(no 'A' met) out:\n%s\n", ft_memccpy(str1, str2, 'A', LEN_ST - 1));
	checker(str1, str2, ft_cmp_s);
	printf("memccpy() opt2(' ' met) out:\n%s\n", memccpy(str1, str2, ' ', LEN_ST - 1));
	ft_strcpy(str1, S_TEST); //set args
	printf("ft_memccpy() opt2(' ' met) out:\n%s\n", ft_memccpy(str1, str2, ' ', LEN_ST - 1));
	checker(str1, str2, ft_cmp_s);
	ft_strcpy(str1, S_TEST); ft_strcpy(str2, S_TEST); //reset

	printf("\n ...GO FT_MEMMOVE...\n");	//FT_MEMMOVE
	ft_memset(str2, 33, 4); //set args
	printf("memmove() opt1(no 'A' met) out:\n%s\n", memmove(str1, str2, 'A', LEN_ST - 1));
	ft_strcpy(str1, S_TEST); //set args
	printf("ft_memmove() opt1(no 'A' met) out:\n%s\n", ft_memmove(str1, str2, 'A', LEN_ST - 1));
	checker(str1, str2, ft_cmp_s);
	printf("memmove() opt2(' ' met) out:\n%s\n", memmove(str1, str2, ' ', LEN_ST - 1));
	ft_strcpy(str1, S_TEST); //set args
	printf("ft_memmove() opt2(' ' met) out:\n%s\n", ft_memmove(str1, str2, ' ', LEN_ST - 1));
	checker(str1, str2, ft_cmp_s);
	ft_strcpy(str1, S_TEST); ft_strcpy(str2, S_TEST); //reset
	return (0);
}
