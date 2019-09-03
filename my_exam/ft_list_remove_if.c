/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_if.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caellis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 18:33:19 by caellis           #+#    #+#             */
/*   Updated: 2019/09/03 18:33:47 by caellis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef struct    s_list
{
    struct s_list	*next;
    void				*data;
}                 t_list;

void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
	t_list	*tmp;
	
	if (begin_list)
	{
		while (*begin_list)
		{
			if (cmp(*begin_list, data_ref) == 0)
			{
				tmp = *begin_list;
				*begin_list = (*begin_list)->next;
				free(tmp);
			}
			else
				*begin_list = (*begin_list)->next;
		}
	}
}
