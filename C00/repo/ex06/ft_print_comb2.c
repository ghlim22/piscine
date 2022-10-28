/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gylim <gylim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 22:27:36 by gylim             #+#    #+#             */
/*   Updated: 2022/10/01 23:37:47 by gylim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_two_digits(int n);

void	ft_print_comb2(void)
{
	int	first_num;
	int	second_num;

	first_num = 0;
	while (first_num < 98)
	{
		second_num = first_num + 1;
		while (second_num < 100)
		{
			ft_print_two_digits(first_num);
			write(1, " ", 1);
			ft_print_two_digits(second_num);
			write(1, ", ", 2);
			second_num++;
		}
		first_num++;
	}
	write(1, "98 99", 5);
}

void	ft_print_two_digits(int n)
{
	char	*digits;

	digits = "0123456789";
	if (n < 10)
	{
		write(1, "0", 1);
		write(1, &digits[n % 10], 1);
	}
	else
	{
		write(1, &digits[n / 10], 1);
		write(1, &digits[n % 10], 1);
	}
}	
