/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gylim <gylim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 16:56:14 by gylim             #+#    #+#             */
/*   Updated: 2022/10/09 20:44:51 by gylim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_stock_str.h"

int		get_strlen(char *str);
char	*ft_strdup(char *src, int src_len);

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	struct s_stock_str	*arr;
	int					i;
	int					str_len;

	arr = malloc(sizeof(*arr) * (ac + 1));
	if (!arr)
		return (NULL);
	i = 0;
	while (i < ac && av[i] != NULL)
	{
		str_len = get_strlen(av[i]);
		arr[i].size = str_len;
		arr[i].str = av[i];
		arr[i].copy = ft_strdup(av[i], str_len);
		if (!arr[i].copy)
		{
			free(arr);
			return (NULL);
		}	
		++i;
	}
	arr[i].size = 0;
	arr[i].str = 0;
	arr[i].copy = 0;
	return (arr);
}

int	get_strlen(char *str)
{
	int	len;

	len = 0;
	while (*str)
	{
		len++;
		str++;
	}
	return (len);
}

char	*ft_strdup(char *src, int src_len)
{
	char	*dst;
	int		i;

	dst = malloc(src_len + 1);
	if (!dst)
		return (NULL);
	i = 0;
	while (i < src_len)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}
