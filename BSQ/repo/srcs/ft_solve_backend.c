/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve_backend.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gylim <gylim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 20:49:32 by gylim             #+#    #+#             */
/*   Updated: 2022/10/19 20:51:23 by gylim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_struct.h"

int	ft_get_max(int a, int b)
{	
	if (a >= b)
		return (a);
	else
		return (b);
}

int	ft_get_min(int a, int b)
{
	if (a <= b)
		return (a);
	else
		return (b);
}

void	ft_print(t_data *map)
{
	int	i;
	int	j;
	int	start_row;
	int	start_col;

	i = 0;
	start_row = map->info[1][0];
	start_col = map->info[1][1];
	while (i < map->info[1][2])
	{
		j = 0;
		while (j < map->info[1][2])
		{
			map->map[i + start_row][j + start_col] = map->info[2][2];
			j++;
		}
		i++;
	}
	i = 0;
	while (i < map->info[0][0])
	{
		write(1, map->map[i], map->info[0][1]);
		write(1, "\n", 1);
		i++;
	}
}

void	ft_update_bsq(t_data *map, int row, int col, int max)
{
	map->info[1][0] = row;
	map->info[1][1] = col;
	map->info[1][2] = max;
}

int	ft_find_bsq(t_data *map, int row, int col)
{
	int	max_size;
	int	i;
	int	j;

	max_size = ft_get_min(map->info[0][0] - row, map->info[0][1] - col);
	i = 0;
	while (i < max_size)
	{
		j = 0;
		while (j < max_size)
		{
			if (map->map[i + row][j + col] == map->info[2][1])
			{
				max_size = ft_get_max(i, j);
				if (max_size <= map->info[1][2])
					return (j);
			}
			j++;
		}
		i++;
	}
	if (max_size > map->info[1][2])
		ft_update_bsq(map, row, col, max_size);
	return (0);
}
