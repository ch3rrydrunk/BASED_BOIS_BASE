/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_put_empty.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caellis <caellis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/28 18:50:10 by bnesoi            #+#    #+#             */
/*   Updated: 2019/09/20 16:34:19 by caellis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		put_padding(t_pf_format *f)
{
	while (--f->pad > 0)
		pf_put_buffered(&f->pad_c, f, 1, 0);
}

void			pf_put_empty(t_pf_format *f)
{
	!(f->flg & PF_F_LEFTJ) ? put_padding(f) : 0;
	pf_put_buffered("%", f, 1, 0);
	f->flg & PF_F_LEFTJ ? put_padding(f) : 0;
}
