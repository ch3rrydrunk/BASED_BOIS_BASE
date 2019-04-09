/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormund <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 11:31:36 by cormund           #+#    #+#             */
/*   Updated: 2019/04/09 10:32:03 by cormund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "/Users/cormund/42/Libft/srcs/libft.h"

int		main()
{
	char *str_lb;
	str_lb = "hel, world";
	char *str_ft;
	str_ft = "hel, world";
	char dst_lb[8] = "privet!";
	char dst_ft[8] = "privet!";


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


	printf("dst_lb_befor = %s\n\n", dst_lb);
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
	printf("dst_ft_after = %s\n", dst_ft);

	//___strlen___


	//printf("strlen (\"privet, mir!\") out:\n%d\n", strlen("privet, mir!"));
	//printf("ft_strlen (\"privet, mir!\") out:\n%d\n", ft_strlen("privet, mir!"));
	return (0);
}
