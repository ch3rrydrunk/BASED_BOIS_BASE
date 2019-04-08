/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormund <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 11:31:36 by cormund           #+#    #+#             */
/*   Updated: 2019/04/08 10:59:56 by cormund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "/Users/cormund/42/Libft/srcs/libft.h"

int		main()
{
	char str[20] = "hello, world";
	char str_lb[] = "hello, world";
	char str_ft[] = "hello, world";
	char dst_lb[30];
	char ds_ft[30];


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
	//___memccpy___
	//
	printf("memccpy(dst_lb, str, 15) out:\n%s\n", memccpy(dst_lb, str, 15));
	printf("ft_memccpy(dst_ft, str, 15) out:\n%s\n",ft_memccpy(dst_ft, str, 15));
	return (0);
}
