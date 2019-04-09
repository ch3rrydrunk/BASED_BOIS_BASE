/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_printer_color.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormund <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 14:41:15 by cormund           #+#    #+#             */
/*   Updated: 2019/04/09 14:42:46 by cormund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	red() 
{
	printf("\033[0;31m");
}

void	green()
{
	printf("\033[0;32m");
}

void	yellow()
{
	printf("\033[0;33m");
}

void	blue()
{
	printf("\033[0;34m");
}

void	magenta()
{
	printf("\033[0;35m");
}

void	b_red() 
{
	printf("\033[1;31m");
}

void	b_green()
{
	printf("\033[1;32m");
}

void	b_yellow()
{
	printf("\033[1;33m");
}

void	b_blue()
{
	printf("\033[1;34m");
}

void	b_magenta()
{
	printf("\033[1;35m");
}

void	reset()
{
	printf("\033[0m");
	printf("");
}
