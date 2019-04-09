/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormund <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 11:31:36 by cormund           #+#    #+#             */
/*   Updated: 2019/04/09 18:55:28 by cormund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "/Users/cormund/42/Libft/test_printer_color.h"
#include "/Users/cormund/42/Libft/srcs/libft.h"

static int intcmp(int *n1, int *n2)
{
	return (n1 == n2);
}

static void checker(void *s1, void *s2, int (*f)(void *, void *))
{
	if (f(s1, s2) != 0)
	{
		b_red(); printf(" ...\t...\t...\n\"FAIL\" ...\t...\t...\n"); reset();
	}
	else
	{
		b_green(); printf("...\t...\t...\n\"OK\" ...\t...\t...\n\n"); reset();
	}
}

static void	checker_str(int *s1)
{
	if (s1 != 0)
	{
		b_red(); printf(" ...\t...\t...\n\"FAIL\" ...\t...\t...\n"); reset();
	}
	else
	{
		b_green(); printf(" ...\t...\t...\n\"OK\" ...\t...\t...\n\n"); reset();
	}
}

int		main()
{
	char *str_lb;
	str_lb = "hello, world";
	char *str_ft;
	str_ft = "hello, world";
	char dst_lb[13] = "privet, mir!";
	char dst_ft[13] = "privet, mir!";
	char *str_zero;
	str_zero = "";;

	//for cmp
	char str_cmp1[10] = "\200";
	char str_cmp2[10] = "\0";

	int	n1;
	int n2;
	int len;
 
	len = 12;

	int		(*ft_cmp_s)(void *, void *);


	//____MEMSET_____

	//printf("memset( , 75, 15) out:\n%s\n", memset(str, 0, 15));
	//printf("memset( , 72, 2) out:\n%s\n", memset(str, 72, 2));
	//printf("memset( , 0,  2) out:\n%s\n", memset(str, 0, 2));
	//printf("ft_memset( , 75, 15) out:\n%s\n", ft_memset(str, 0, 15));
	//printf("ft_memset( , 72, 2) out:\n%s\n", ft_memset(str, 72, 2));
	//printf("ft_memset( , 0, 2) out:\n%s\n", ft_memset(str, 0, 2));

	//____bzero____

	//bzero(str_lb, 14);
	//ft_bzero(str_ft, 0);
	//printf("bzero(str_lb, 4) out:\n%s\n", str_lb);
	//printf("ft_bzero(str_ft, 4) out:\n%s\n", str_ft);
	//
	//___memcpy___
	//
	//printf("memcpy(dst_lb + 3, dst_lb + 4, 3) out:\n%s\n", memcpy(dst_lb + 3, dst_lb + 4, 3));
	//printf("ft_memcpy(dst_ft + 3, dst_ft + 4, 3) out:\n%s\n",ft_memcpy(dst_ft + 3, dst_ft + 4, 3));
	
	
	//___memccpy___

	//printf("dst_lb_befor = %s\n", dst_lb);
	//printf("memccpy(dst_lb, \"hel, world\", ' ', 5) out:\n%s\n", memccpy(dst_lb, str_lb, ' ', 5));
	//printf("dst_lb_after = %s\n", dst_lb);
	//printf("dst_lb_befor = %s\n", dst_lb);
	//printf("memccpy(dst_lb, \"hel, world\", ' ', 2) out:\n%s\n", memccpy(dst_lb, str_lb, ' ', 2));
	//printf("dst_lb_after = %s\n\n", dst_lb);
	//printf("dst_ft_befor = %s\n", dst_ft);
	//printf("memccpy(dst_ft, \"hel, world\", ' ', 5) out:\n%s\n", ft_memccpy(dst_ft, str_ft, ' ', 5));
	//printf("dst_ft_after = %s\n", dst_ft);
	//printf("dst_ft_befor = %s\n", dst_ft);
	//printf("memccpy(dst_ft, \"hel, world\", ' ', 2) out:\n%s\n", ft_memccpy(dst_ft, str_ft, ' ', 2));
	//printf("dst_ft_after = %s\n", dst_ft); 


	//___memmove___


	/*printf("dst_lb_befor = %s\n\n", dst_lb);
	printf("memmove((dst_lb + 3), (dst_lb + 4), 3) out:\n%s\n\n", memmove((dst_lb + 3), (dst_lb + 4), 3));
	printf("dst_lb_after = %s\n", dst_lb);
	printf("dst_ft_befor = %s\n\n", dst_ft);
	printf("ft_memmove((dst_ft + 3), (dst_ft + 4), 3) out:\n%s\n\n", ft_memmove((dst_ft + 3), (dst_ft + 4), 3));
	printf("dst_ft_after = %s\n", dst_ft);

	printf("%s\n", "test2");
	printf("dst_lb_befor = %s\n\n", dst_lb);
	printf("memmove((dst_lb + 4), (dst_lb + 3), 3) out:\n%s\n\n", memmove((dst_lb + 4), (dst_lb + 3), 3));
	printf("dst_lb_after = %s\n", dst_lb);
	printf("dst_ft_befor = %s\n\n", dst_ft);
	printf("ft_memmove((dst_ft + 4), (dst_ft + 3), 3) out:\n%s\n\n", ft_memmove((dst_ft + 4), (dst_ft + 3), 3));
	printf("dst_ft_after = %s\n", dst_ft);*/

	//___memchr___
	

	/*printf("dst_lb_befor = %s\n\n", dst_lb);
	printf("dst_lb = memchr(dst_lb, 'i', 10) out:\n%s\n\n", memchr(dst_lb, 'i', 10));
	printf("dst_ft_befor = %s\n\n", dst_ft);
	printf("dst_ft = ft_memchr(dst_ft, 'i', 10) out:\n%s\n\n", ft_memchr(dst_ft, 'i', 10));
	printf("%s\n", "test2");
	printf("dst_lb_befor = %s\n\n", str_zero);
	printf("dst_lb = memchr(dst_lb, 'i', 10) out:\n%s\n\n", memchr(str_zero, 'NULL', 10));
	printf("dst_ft_befor = %s\n\n", str_zero);
	printf("dst_ft = ft_memchr(dst_ft, 'i', 10) out:\n%s\n\n", ft_memchr(str_zero, 'NULL', 10));*/


	//___memcmp___
	
	/*printf("\n...FT_MEMСMP...\n"); reset();
	n1 = memcmp("", "", 10); n2 = ft_memcmp("", "", 10);
	printf("memcmp() out:\n%i\nft_memcmp() out:\n%i\n", n1, n2);
	ft_cmp_s = (int (*)(void *, void *))intcmp; //set func
	checker((char *)&n1, (char *)&n2, ft_cmp_s);
	printf("\n...FT_MEMСMP_TEST2...\n"); reset();
	n1 = memcmp(str_cmp1, str_cmp2, len); n2 = ft_memcmp(str_cmp1, str_cmp2, len);
	printf("memcmp() out:\n%i\nft_memcmp() out:\n%i\n", n1, n2);
	ft_cmp_s = (int (*)(void *, void *))intcmp; //set func
	checker((char *)&n1, (char *)&n2, ft_cmp_s);*/


	//test 2 unequal strings
	//
	//___strdup___
	//
	printf("\n...FT_STRDUP...\n"); reset();
	n1 = memcmp(strdup(str_lb), ft_strdup(str_lb), len);
	printf("strdup(str_lb) out:\n%s\n\n", strdup(str_lb));
	printf("ft_strdup(str_lb) out:\n%s\n\n", ft_strdup(str_lb));
	printf("memcmp(strdup(str_lb), ft_strdup(str_lb), len):\n%i\n", n1);
	checker_str(n1);
	//


	//___strlen___


	//printf("strlen (\"privet, mir!\") out:\n%d\n", strlen("privet, mir!"));
	//printf("ft_strlen (\"privet, mir!\") out:\n%d\n", ft_strlen("privet, mir!"));
	
	//___
	printf("\n...FT_STRCOPY...\n"); reset();
	n1 = memcmp(strcpy(dst_lb, str_lb), ft_strcpy(dst_ft, str_ft), len);
	printf("strcpy(dst_lb,str_lb) out:\n%s\n\n", strcpy(dst_lb,str_lb));
	printf("ft_strcpy(dst_ft, str_ft) out:\n%s\n\n", ft_strcpy(dst_ft, str_ft));
	printf("memcmp(strcpy(dst_lb,str_lb)), ft_strcpy(dst_ft, str_ft), len):\n%i\n", n1);
	checker_str(n1);

	
	return (0);
}
