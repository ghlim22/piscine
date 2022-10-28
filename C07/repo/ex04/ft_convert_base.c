/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gylim <gylim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 10:26:27 by gylim             #+#    #+#             */
/*   Updated: 2022/10/20 22:53:46 by gylim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int			ft_baselen(char *base);
int			ft_is_digit(char *str, char *base, int *digit);
int			ft_nbrlen(long long nbr, char *base);
void		ft_fill(long long nbr, char *str, char *base, int i);
long long	ft_atoi_base(char *str, char *base);
char		*ft_itoa_base(long long nbr, char *base);

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int			from_len;
	int			to_len;
	long long	temp;

	from_len = ft_baselen(base_from);
	to_len = ft_baselen(base_to);
	if (!from_len || !to_len)
		return (NULL);
	temp = ft_atoi_base(nbr, base_from);
	return (ft_itoa_base(temp, base_to));
}

long long	ft_atoi_base(char *str, char *base)
{
	int			digit;
	int			minus;
	int			base_len;
	long long	nbr;

	digit = 0;
	minus = 1;
	nbr = 0;
	base_len = ft_baselen(base);
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	while (*str == '+' || *str == '-')
	{
		if (*str == '-')
			minus *= -1;
		str++;
	}
	while (ft_is_digit(str, base, &digit))
	{
		nbr = (nbr * base_len) + digit;
		str++;
	}
	return (nbr * minus);
}

char	*ft_itoa_base(long long nbr, char *base)
{
	char	*str;
	int		base_len;
	int		str_size;

	base_len = ft_baselen(base);
	str_size = 1;
	if (!base_len)
		return (NULL);
	if (nbr < 0)
		str_size++;
	str_size += ft_nbrlen(nbr, base);
	str = malloc(str_size);
	if (!str)
		return (NULL);
	ft_fill(nbr, str, base, str_size - 2);
	str[str_size - 1] = '\0';
	return (str);
}
