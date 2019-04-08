/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormund <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 12:01:21 by cormund           #+#    #+#             */
/*   Updated: 2019/04/05 17:41:23 by cormund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "/Users/cormund/42/Libft/includes/libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
		*(unsigned char *)(b+i++) = (unsigned char)c;
	return ((void*)b);
}
