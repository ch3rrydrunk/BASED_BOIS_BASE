/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caellis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 13:50:03 by caellis           #+#    #+#             */
/*   Updated: 2019/04/05 16:29:59 by caellis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
    unsigned char   *st1;
    unsigned char   *st2;
    unsigned char   b1;
    unsigned char   b2;

    st1 = (unsigned char *)s1;
    st2 = (unsigned char *)s2;
    b1 = *st1;
    b2 = *st2;
    if (!b1 || !b2)
    {
        if (b1 == '\0'&& b2 == '\0')
            return (0);
        return (b1 - b2);
    }
    while (n-- && (b1 == b2))
    {
        st1++;
        st2++;
    }
    return (b1 - b2);
}
