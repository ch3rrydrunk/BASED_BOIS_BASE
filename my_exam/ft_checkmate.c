/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkmate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caellis <caellis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 18:31:02 by caellis           #+#    #+#             */
/*   Updated: 2019/09/10 12:21:54 by caellis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "checkmate.h"

void	ft_bzero(void *mem, size_t size)
{
	uint8_t		*ptr = (uint8_t *)mem;

	while (size--)
		*ptr++ = 0U;
}

char	checkDiags(char **board, t_pos king, int rows)
{
	return (0);
}

char	checkAxes(char **board, t_pos king, int rows)
{
	int		i = 0;
	t_pos	possible[rows << 2];
	t_pos	*cue = possible;

	ft_bzero(possible, sizeof(t_pos) * (rows << 2));
	while (i < rows)
	{
		if (board[king.i_row][i] == ROOK)
		{
			cue->i_row = king.i_row;
			cue->j_col = i;
			cue++;
		}
		if (board[i][king.j_col] == ROOK)
		{
			cue->i_row = i;
			cue->j_col = king.j_col;
			cue++;
		}
	}
	if (cue != possible && (i = 0))
	{
		
	}
	return (0);
}

char	checkKing(char **board, t_pos king, int rows)
{
	int		i = 0;

	if (checkAxes(board, king, rows) || checkDiags(board, king, rows))
		return (1);
	return (0);
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