/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gylim <gylim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 21:04:00 by gylim             #+#    #+#             */
/*   Updated: 2022/10/06 13:33:16 by gylim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	__ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

int	_ft_check_base(char *base)
{
	int	i;
	int	j;
	int	base_len;

	base_len = __ft_strlen(base);
	if (base_len <= 1)
		return (0);
	i = 0;
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-')
			return (0);
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (base_len);
}

void	__ft_print_num(long long nbr, char *base, int base_len)
{
	if (nbr / base_len > 0)
		__ft_print_num(nbr / base_len, base, base_len);
	write(1, &base[nbr % base_len], 1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int			base_len;
	long long	temp;

	base_len = _ft_check_base(base);
	if (base_len == 0)
		return ;
	temp = nbr;
	if (temp < 0)
	{
		temp *= -1;
		write(1, "-", 1);
	}
	__ft_print_num(temp, base, base_len);
}
