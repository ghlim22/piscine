/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gylim <gylim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 19:06:45 by gylim             #+#    #+#             */
/*   Updated: 2022/10/02 20:24:11 by gylim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	_ft_print_addr(unsigned long long addr)
{
	char	arr[16];
	char	*hex_digits;
	int		i;

	hex_digits = "0123456789abcdef";
	i = 15;
	while (i >= 0)
	{
		arr[i] = hex_digits[addr % 16];
		addr /= 16;
		i--;
	}
	write(1, arr, 16);
	write(1, ": ", 2);
}

void	_ft_print_data(unsigned char *ptr_byte, unsigned int size)
{
	unsigned int	i;
	char			*hex_digits;

	i = 0;
	hex_digits = "0123456789abcdef";
	while (i < size)
	{
		write(1, &hex_digits[*(ptr_byte + i) / 16], 1);
		write(1, &hex_digits[*(ptr_byte + i) % 16], 1);
		i++;
		if (i % 2 == 0)
			write(1, " ", 1);
	}
	while (i < 16)
	{
		write(1, "  ", 2);
		i++;
		if (i % 2 == 0)
			write(1, " ", 1);
	}
}

void	_ft_print_char(unsigned char *ptr_byte, unsigned int size)
{
	unsigned int	i;
	char			c;

	i = 0;
	while (i < size)
	{
		c = ptr_byte[i];
		if (c >= 32 && c <= 126)
			write(1, &c, 1);
		else
			write(1, ".", 1);
		i++;
	}
	write(1, "\n", 1);
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned int	len;
	unsigned char	*ptr;

	ptr = (unsigned char *)addr;
	while (size > 0)
	{
		if (size / 16 > 0)
			len = 16;
		else
			len = size;
		_ft_print_addr((unsigned long long)ptr);
		_ft_print_data(ptr, len);
		_ft_print_char(ptr, len);
		ptr += 16;
		size -= len;
	}
	return (addr);
}
