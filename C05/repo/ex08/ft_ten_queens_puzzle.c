/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queen_puzzle.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gylim <gylim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 22:06:27 by gylim             #+#    #+#             */
/*   Updated: 2022/10/07 10:45:39 by gylim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	_ft_init_arr(int check[][20])
{
	int	i;
	int	j;

	i = 0;
	while (i < 3)
	{
		j = 0;
		while (j < 20)
		{
			check[i][j] = 0;
			j++;
		}
		i++;
	}
}

int	_ft_check(int check[][20], int i, int depth)
{
	if (check[0][i])
		return (0);
	if (check[1][i + depth])
		return (0);
	if (check[2][10 - i + depth - 1])
		return (0);
	check[0][i] = 1;
	check[1][i + depth] = 1;
	check[2][10 - i + depth - 1] = 1;
	return (1);
}

void	_ft_recursive(char arr[], int check[][20], int *cnt, int depth)
{
	int	i;

	if (depth == 10)
	{
		write(1, arr, 11);
		(*cnt)++;
		return ;
	}
	i = -1;
	while (++i < 10)
	{
		if (_ft_check(check, i, depth))
		{
			arr[depth] = '0' + i;
			_ft_recursive(arr, check, cnt, depth + 1);
			check[0][i] = 0;
			check[1][i + depth] = 0;
			check[2][10 - i + depth - 1] = 0;
		}
	}
}

int	ft_ten_queens_puzzle(void)
{
	char	arr[11];
	int		check[3][20];
	int		cnt;

	cnt = 0;
	arr[10] = '\n';
	_ft_init_arr(check);
	_ft_recursive(arr, check, &cnt, 0);
	return (cnt);
}
