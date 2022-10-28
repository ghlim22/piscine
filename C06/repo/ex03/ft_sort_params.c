/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gylim <gylim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 22:53:43 by gylim             #+#    #+#             */
/*   Updated: 2022/10/08 16:39:44 by gylim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	____ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

void	____ft_putstr(char *str)
{
	int	len;

	len = ____ft_strlen(str);
	write(1, str, len);
}

int	____ft_compare(char *str1, char *str2)
{
	while (*str1 && str2 && *str1 == *str2)
	{
		str1++;
		str2++;
	}
	return (*str1 - *str2);
}

void	____sort(char **arr, int size)
{
	int		i;
	int		j;
	int		pivot;
	char	*temp;

	i = 0;
	while (++i < size - 1)
	{
		pivot = i;
		j = i + 1;
		while (j < size)
		{
			if (____ft_compare(arr[j], arr[pivot]) < 0)
			{
				pivot = j;
			}
			j++;
		}
		if (pivot != i)
		{
			temp = arr[i];
			arr[i] = arr[pivot];
			arr[pivot] = temp;
		}
	}
}

int	main(int argc, char **argv)
{
	int	i;

	____sort(argv, argc);
	i = 1;
	while (i < argc)
	{
		____ft_putstr(argv[i]);
		write(1, "\n", 1);
		i++;
	}
	return (0);
}
