/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gylim <gylim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 18:58:48 by gylim             #+#    #+#             */
/*   Updated: 2022/10/02 20:24:44 by gylim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	_ft_print_hex(unsigned char c)
{
	char	*hex_digits;

	hex_digits = "0123456789abcdef";
	write(1, "\\", 1);
	write(1, &hex_digits[c / 16], 1);
	write(1, &hex_digits[c % 16], 1);
}

int	_ft_str_is_printable(char c)
{
	return (c >= 32 && c <= 126);
}

void	ft_putstr_non_printable(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (_ft_str_is_printable(str[i]))
			write(1, &str[i], 1);
		else
			_ft_print_hex((unsigned char)str[i]);
		i++;
	}
}
