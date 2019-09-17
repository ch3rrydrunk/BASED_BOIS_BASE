/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_memory.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 12:01:42 by exam              #+#    #+#             */
/*   Updated: 2019/09/14 12:59:57 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static int	ft_isprint(unsigned char c)
{
	if (c > 31  && c < 127)
		return (1);
	return (0);
}

static int	output_hex(unsigned char *mem, size_t size)
{
	char			digit[16] = {"0123456789abcdef"};
	unsigned long	i = 0;
	int				spaces = 0;

	while (i++ < size)
	{
		write(1, &digit[(int)(*mem / 16)], 1);
		write(1, &digit[(int)(*mem % 16)], 1);
		mem++;
		if (i % 2 == 0)
		{
			write(1, " ", 1);
			spaces++;
		}
	}
	return (size * 2 + spaces);
}

static int	output_bytes(unsigned char *mem, size_t size)
{
	unsigned long	i = 0;

	while (i++ < size)
	{
		if (ft_isprint(*mem))
			write(1, mem, 1);
		else
			write(1, ".", 1);
		mem++;
	}
	return (size);
}

static void	output_padding(size_t size)
{
	while (size--)
		write(1, " ", 1);
}

void		print_memory(const void *addr, size_t size)
{
	unsigned char	*mem = (unsigned char *)addr;

	while (size >= 16)
	{
		output_hex(mem, 16);
		output_bytes(mem, 16);
		size -= 16;
		mem += 16;
		write(1, "\n", 1);
	}
	if (size)
	{
		output_padding(40 - output_hex(mem, size));
		output_bytes(mem, size);
		write(1, "\n", 1);
	}
}
