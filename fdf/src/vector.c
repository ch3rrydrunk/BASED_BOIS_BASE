/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caellis <caellis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 20:45:20 by ch3rryhq          #+#    #+#             */
/*   Updated: 2019/10/01 15:55:05 by caellis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_vec		*new_vec(int p_w, int p_h, int p_z)
{
	t_vec   *pnt;

	NULL_IF_ERROR(pnt = (t_vec *)malloc(sizeof(t_vec)))
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

void		*clean_vec(t_vec **img)
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

t_vec		*smul_vec(t_vec *img, int scalar)
{
	t_vec	*buff;

	buff = img;
	if (buff)
	{
		while (buff->next)
		{
			buff->x *= scalar;
			buff->y *= scalar;
			buff->z *= scalar;
			buff = img->next;
		}
	}
	return (img);
}