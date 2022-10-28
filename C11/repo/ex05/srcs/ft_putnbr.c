/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gylim <gylim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 20:29:37 by gylim             #+#    #+#             */
/*   Updated: 2022/10/12 21:03:15 by gylim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_putnbr.h"

void	ft_putnbr(int nb)
{
	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}	
	if (nb < 0)
	{
		write(1, "-", 1);
		nb *= -1;
	}
	ft_print_num(nb);
}

void	ft_print_num(int nb)
{
	if (nb / 10 > 0)
		ft_print_num(nb / 10);
	write(1, &"0123456789"[nb % 10], 1);
}
