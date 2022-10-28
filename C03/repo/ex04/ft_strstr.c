/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gylim <gylim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 11:31:10 by gylim             #+#    #+#             */
/*   Updated: 2022/10/03 15:40:45 by gylim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	_ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

int	_ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (i < n - 1 && s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

char	*ft_strstr(char *str, char *to_find)
{
	int	find_len;

	find_len = _ft_strlen(to_find);
	if (find_len == 0)
		return (str);
	while (*str)
	{
		if (_ft_strncmp(str, to_find, find_len) == 0)
			return (str);
		str++;
	}
	return ((void *)0);
}
