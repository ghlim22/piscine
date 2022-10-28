/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gylim <gylim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 23:25:40 by gylim             #+#    #+#             */
/*   Updated: 2022/10/01 23:26:32 by gylim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_adjust(char *arr, int n)
{
	int	i;

	i = 1;
	while (i < n)
	{
		if (arr[i] >= 10 - n + i + '0')
		{
			arr[i - 1]++;
			while (i < n)
			{
				arr[i] = arr[i - 1] + 1;
				i++;
			}
			return (1);
		}
		i++;
	}
	return (0);
}

void	ft_print_combn(int n)
{
	char	arr[10];
	int		i;

	i = 0;
	while (i < n)
	{
		arr[i] = '0' + i;
		i++;
	}
	while (arr[0] <= 10 - n + '0')
	{
		write(1, arr, n);
		if (arr[0] < 10 - n + '0')
		{
			write(1, ", ", 2);
		}
		if (ft_adjust(arr, n) == 0)
		{
			arr[n - 1]++;
		}
	}
}
