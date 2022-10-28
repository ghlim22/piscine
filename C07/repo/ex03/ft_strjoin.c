/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gylim <gylim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 15:19:34 by gylim             #+#    #+#             */
/*   Updated: 2022/10/10 14:51:52 by gylim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_getsize(int size, char **strs, char *sep)
{
	int	str_len;
	int	sep_len;
	int	i;
	int	j;

	str_len = 0;
	i = -1;
	while (++i < size)
	{
		j = -1;
		while (strs[i][++j] != '\0')
		{
			str_len++;
		}
	}
	i = -1;
	sep_len = 0;
	while (sep[++i])
		sep_len++;
	return (str_len + (size - 1) * sep_len + 1);
}

void	ft_join(int size, char **strs, char *sep, char *dst)
{
	int	i;
	int	j;
	int	k;

	i = -1;
	k = -1;
	while (++i < size)
	{
		j = -1;
		while (strs[i][++j])
			dst[++k] = strs[i][j];
		j = -1;
		while (i + 1 < size && sep[++j])
			dst[++k] = sep[j];
	}
	dst[++k] = '\0';
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*dst;

	if (size == 0)
	{
		dst = (char *)malloc(sizeof(char));
		dst[0] = '\0';
		return (dst);
	}
	dst = malloc(ft_getsize(size, strs, sep) * sizeof(char));
	ft_join(size, strs, sep, dst);
	return (dst);
}
