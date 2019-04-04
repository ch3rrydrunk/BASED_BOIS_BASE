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

# define S_TEST "HEIL CHERRY"
# define LEN_ST 12
# define B_TEST "00001010"
# define C_TEST 'A'

int		main(void)
{
	char	str[LEN_ST] = {S_TEST};

	printf("Hello, Master!\nThese are your tests!\n");
	printf("Please, enjoy!\n");
	printf(" ...\t...\t...\n");
	printf("S_TEST OK: %s\n", S_TEST);
	printf(" ...\t...\t...\n");

	//FT_MEMSET
	printf("TESTING ft_memset()\n");
	memset(str, 48, LEN_ST);
	printf("%s\n", str);

	return (0);
}
