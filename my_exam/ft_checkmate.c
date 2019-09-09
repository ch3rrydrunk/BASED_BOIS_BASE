/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkmate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caellis <caellis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 18:31:02 by caellis           #+#    #+#             */
/*   Updated: 2019/09/09 15:52:45 by caellis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "checkmate.h"

char	checkKing(char **board, t_pos king, int rows)
{
	int		i = 0;

	while ()
}

void	checkmate(int rows, char **board)
{
	int		i = 0, j = 0;
	t_pos	k_pos;

	while (i < rows)
	{
		while (j < rows)
		{
			if (board[i][j] == KING && (k_pos.i_row = i) && (k_pos.j_col = j))
			{
				if (checkKing(board, k_pos, rows))
					write(1, "Success\n", 12);
				else
					write(1, "Fail\n", 5);
			}
			j++;
		}
		i++;
	}
}

int		main(int ac, char **av)
{
	if (ac > 1)
		checkmate(--ac, av);
	else
		write(1, "\n", 1);
	return (0);
}