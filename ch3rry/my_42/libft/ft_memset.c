/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caellis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 19:56:42 by caellis           #+#    #+#             */
/*   Updated: 2019/04/04 19:13:10 by caellis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t len)
{
    unsigned char    *buff;

    if (len == 0 || s == NULL)
        return (s);
    buff = (unsigned char *)s;
    while (len--)
        *(buff++) = (unsigned char)c;
    return (s);
}