/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gylim <gylim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 10:28:44 by gylim             #+#    #+#             */
/*   Updated: 2022/10/20 22:53:22 by gylim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_baselen(char *base)
{
	int	i;
	int	j;
	int	minus;

	i = 0;
	minus = 1;
	while (base[i])
	{
		if (base[i] == ' ' || (base[i] >= 9 && base[i] <= 13))
			return (0);
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
	if (i < 2)
		return (0);
	return (i);
}

int	ft_is_digit(char *str, char *base, int *digit)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (*str == base[i])
		{
			*digit = i;
			return (1);
		}
		i++;
	}
	return (0);
}

int	ft_nbrlen(long long nbr, char *base)
{
	int	nbr_len;
	int	base_len;

	base_len = ft_baselen(base);
	if (!base_len)
		return (0);
	if (nbr < 0)
		nbr *= -1;
	nbr_len = 1;
	while (nbr >= base_len)
	{
		nbr_len++;
		nbr /= base_len;
	}
	return (nbr_len);
}

void	ft_fill(long long nbr, char *str, char *base, int i)
{
	int	base_len;

	base_len = ft_baselen(base);
	if (nbr < 0)
	{
		nbr *= -1;
		str[0] = '-';
	}
	if (nbr >= base_len)
		ft_fill(nbr / base_len, str, base, i - 1);
	str[i] = base[nbr % base_len];
}
