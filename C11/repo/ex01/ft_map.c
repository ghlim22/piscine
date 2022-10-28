/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gylim <gylim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 21:07:20 by gylim             #+#    #+#             */
/*   Updated: 2022/10/13 19:34:16 by gylim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_map(int *tab, int length, int (*f)(int))
{
	int	*new_arr;
	int	i;

	new_arr = malloc(sizeof(int) * length);
	if (!new_arr)
		return (NULL);
	i = 0;
	while (i < length)
	{
		new_arr[i] = (*f)(tab[i]);
		i++;
	}
	return (new_arr);
}
