/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caellis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 13:50:03 by caellis           #+#    #+#             */
/*   Updated: 2019/04/05 16:29:59 by caellis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void    *ft_memmove(void *dst, const void *src, size_t len)
{
    unsigned char   *buff;
    unsigned char   *cast;

    buff = (unsigned char *)dst;
    cast = (unsigned char *)src;
    if (dst == src || len == 0 || dst == NULL || src == NULL)
        return (dst);
    if (buff > cast)
    {
        cast += len - 1;
        buff += len - 1;
        while (len--)
            *(buff--) = *(cast--);
    }
    else
        ft_memcpy(dst, src, len);
    return (dst);
}
