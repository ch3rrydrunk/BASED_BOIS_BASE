/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_memory.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 12:14:20 by exam              #+#    #+#             */
/*   Updated: 2019/09/12 13:51:51 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

#define LINE 16

char				*ft_strrev(char *str, int len)
{
	int				i = 0;
	char			a = 0;

	while (i < len / 2)
	{
		str[i] = a;
		str[i] = str[len - i - 1];
		str[len - i - 1] = a;
		i++;
	}
	return (str);
}

char				*lil_itoa_hex(unsigned char num, char *res)
{
	int				len = 0;

	while (num)
	{
		*res = num % 16 <= 9 ? (char)((num % 16) + 48U) : (char)((num % 16) + 87U);
		res++;
		len++;
		num /= 16;
	}
	if (len == 1)
	{
		*res++ = 48U;
		len++;
	}
	return (ft_strrev(res, len));
}

void				print_hex(unsigned char *mem, size_t size)
{
	char			res[3] = {0};
	int				i = 0;

	while (i++ < size)
	{
		if (!(*mem))
			write(1, "00", 2);
		else
			write(1, lil_itoa_hex(*mem, res), 2);
		if (i % 2 == 0)
			write(1, " ", 1);
		mem++;
	}
}

void				print_memory(const void *addr, size_t size)
{
	unsigned char	*mem = (unsigned char *)addr;

	while (size)
	{
		if (size >= LINE)
		{
			print_hex(mem, LINE);
			write (1, "\ndone printing hex\n", 19);
			//print_byte(mem, LINE);
			size -= LINE;
			mem += LINE;
		}
		else
		{
			print_hex(mem, size);
			//print_hex(mem, size);
			size -= size;
		}
	}
}

int		main(void)
{
		int	tab[10] = {0, 23, 150, 255, 12, 16,  42, 103};
		print_memory(tab, sizeof(tab));
		return (0);
}
