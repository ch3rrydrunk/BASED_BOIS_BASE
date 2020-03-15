/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_tab.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ch3rryhq <ch3rryhq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/15 20:50:13 by ch3rryhq          #+#    #+#             */
/*   Updated: 2020/03/15 20:59:25 by ch3rryhq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int32_t	get_median(int32_t *begin, int32_t *end, int32_t *pivot)
{
	if (end - begin < 1)
		return (0);
	if (end - begin == 1)
	{
		if (*begin > *end)
		{
			*pivot = *begin;
			*begin = *end;
			*end = *pivot;
		}
		return (0);
	}
	*pivot = *(begin + (end - begin) / 2);
	if ((*pivot > *end && *end > *begin) || (*pivot < *end && *end < *begin))
		*pivot = *end;
	else if ((*pivot > *begin && *begin > *end)
		|| (*pivot < *begin && *begin < *end))
		*pivot = *begin;
	return (1);
}

void		sort_array(int32_t *begin, int32_t *end)
{
	int32_t pivot;
	int32_t *left;
	int32_t *right;
	int32_t buff;

	if (!get_median(begin, end, &pivot))
		return ;
	left = begin;
	right = end;
	while (left <= right)
	{
		if (*left < pivot)
			++left;
		else if (*right > pivot)
			--right;
		else
		{
			buff = *left;
			*left++ = *right;
			*right-- = buff;
		}
	}
	sort_array(begin, right);
	sort_array(left - 1, end);
}
