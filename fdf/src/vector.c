/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caellis <caellis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 20:45:20 by ch3rryhq          #+#    #+#             */
/*   Updated: 2019/09/30 13:39:11 by caellis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_vec		*new_vec(int	p_w, int p_h, int p_z)
{
	t_vec   *pnt;

	NULL_IF_ERROR((t_vec *)malloc(sizeof(t_vec)))
	pnt->x = p_w;
	pnt->y = p_h;
	pnt->z = p_z;
	pnt->next = NULL;
	return (pnt);
}

void        add_vec(t_vec **img, t_vec *pnt)
{
	t_vec   *buff;

	if (img)
	{
		buff = *img;
		*img = pnt;
		pnt->next = buff;
	}
}

int8_t		*clean_vec(t_vec **img)
{
	t_vec	*buff;

	if (img)
	{
		while ((*img)->next)
		{
			buff = *img;
			*img = (*img)->next;
			free(buff);
		}
		*img = NULL; 
	}
	return (NULL);
}