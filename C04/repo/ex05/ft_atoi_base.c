/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gylim <gylim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 12:43:12 by gylim             #+#    #+#             */
/*   Updated: 2022/10/06 19:21:44 by gylim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	___ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

int	__ft_check_base(char *base)
{
	int	i;
	int	j;
	int	base_len;

	base_len = ___ft_strlen(base);
	if (base_len <= 1)
		return (0);
	i = 0;
	while (base[i])
	{
		if ((base[i] >= 9 && base[i] <= 13) || base[i] == ' ')
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
	return (base_len);
}

int	_ft_skip(char **str)
{
	int		minus_cnt;
	char	c;

	minus_cnt = 0;
	c = **str;
	while ((c >= 9 && c <= 13) || c == ' ')
	{
		++*str;
		c = **str;
	}
	while (c == '+' || c == '-')
	{
		if (c == '-')
			minus_cnt++;
		++*str;
		c = **str;
	}
	return (minus_cnt);
}

int	_ft_get_digit(char *str, char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (base[i] == *str)
			return (i);
		i++;
	}
	return (-1);
}

int	ft_atoi_base(char *str, char *base)
{
	int			minus_cnt;
	int			base_len;
	int			digit;
	long long	res;

	base_len = __ft_check_base(base);
	if (base_len == 0)
		return (0);
	minus_cnt = _ft_skip(&str);
	res = 0;
	digit = 0;
	while (*str)
	{
		digit = _ft_get_digit(str, base);
		if (digit == -1)
			break ;
		res = res * base_len + digit;
		str++;
	}
	if (minus_cnt > 0 && minus_cnt % 2 == 1)
		return (-res);
	else
		return (res);
}
