/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gylim <gylim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 22:10:59 by gylim             #+#    #+#             */
/*   Updated: 2022/10/01 23:36:05 by gylim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>	

void	ft_print_comb(void)
{
	char	digit0;
	char	digit1;
	char	digit2;

	digit0 = '0';
	while (digit0 < '7')
	{
		digit1 = digit0 + 1;
		while (digit1 <= '8')
		{
			digit2 = digit1 + 1;
			while (digit2 <= '9')
			{
				write(1, &digit0, 1);
				write(1, &digit1, 1);
				write(1, &digit2, 1);
				write(1, ", ", 2);
				digit2++;
			}
			digit1++;
		}
		digit0++;
	}
	write(1, "789", 3);
}
