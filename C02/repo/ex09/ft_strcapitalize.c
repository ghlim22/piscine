/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gylim <gylim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 17:43:47 by gylim             #+#    #+#             */
/*   Updated: 2022/10/04 18:13:53 by gylim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	_ft_is_space_or_punc(char c)
{
	if ((c <= 47) || (c >= 58 && c <= 64))
		return (1);
	else if ((c >= 91 && c <= 96) || (c >= 123 && c <= 126))
		return (1);
	else
		return (0);
}

int	_ft_is_lower(char c)
{
	return (c >= 'a' && c <= 'z');
}

int	_ft_is_upper(char c)
{
	return (c >= 'A' && c <= 'Z');
}

char	*ft_strcapitalize(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (_ft_is_upper(str[i]))
			str[i] += 32;
		i++;
	}
	i = 0;
	if (_ft_is_lower(str[i]))
	{
		str[i] -= 32;
		i++;
	}
	while (str[i])
	{
		if (str[i + 1] && _ft_is_space_or_punc(str[i]))
		{
			if (_ft_is_lower(str[i + 1]))
				str[i + 1] -= 32;
		}
		i++;
	}
	return (str);
}
