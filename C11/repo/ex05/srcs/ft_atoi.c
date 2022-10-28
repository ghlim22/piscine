/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gylim <gylim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 20:46:40 by gylim             #+#    #+#             */
/*   Updated: 2022/10/12 00:17:47 by gylim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_atoi.h>

int	ft_isspace(char c)
{
	return ((c >= 9 && c <= 13) || c == ' ');
}

int	ft_atoi(char *str)
{
	int			minus_cnt;
	int			i;
	long long	res;

	minus_cnt = 0;
	i = 0;
	res = 0;
	while (ft_isspace(str[i]))
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			minus_cnt++;
		i++;
	}
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - '0');
		i++;
	}
	if (minus_cnt > 0 && minus_cnt % 2 == 1)
		return (-res);
	else
		return (res);
}
